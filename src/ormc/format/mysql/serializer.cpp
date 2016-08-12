/*!
 * \file
 * \brief     MySQL serializer implementation
 * \author    Diego Sogari <diego.sogari@gmail.com>
 * \date      2016
 * \copyright All rights reserved
 */
#include "serializer.h"

// Internal program includes
#include "mysqlBaseVisitor.h"
#include "mysqlLexer.h"
#include "mysqlParser.h"

// Factory registering
CPPORM_REGISTER_string(SerializerFactory, mysql::Serializer, mysql);

namespace mysql
{
/*!
 * \brief Stateful visitor
 */
template <typename T>
class StatefulVisitor : public mysqlBaseVisitor
{
protected:
    /*!
     * \brief The state type
     */
    typedef T State;

    /*!
     * \brief The visitor states
     */
    std::stack<T> mStates;

    /*!
     * \brief Enter state
     * \param[in] ctx The context
     * \param[in] state The new state
     * \return The aggregate result
     */
    template <typename C>
    antlrcpp::Any EnterState(C *ctx, T state)
    {
        mStates.push(state);
        auto result = visitChildren(ctx);
        mStates.pop();
        return result;
    }

    /*!
     * \brief Get literal
     * \param[in] ctx The context
     * \return The string
     */
    template <typename C>
    std::string GetLiteral(C *ctx)
    {
        return ctx->literal() ? GetStringLiteral(ctx->literal().get()) : ctx->getText();
    }

    /*!
     * \brief Get integer literal
     * \param[in] ctx The context
     * \return The string
     */
    template <typename C>
    std::string GetIntegerLiteral(C *ctx)
    {
        return ctx->integer_literal() ? ctx->integer_literal()->getText() : ctx->getText();
    }

    /*!
     * \brief Get string literal
     * \param[in] ctx The context
     * \return The string
     */
    template <typename C>
    std::string GetStringLiteral(C *ctx)
    {
        if (ctx->string_literal())
        {
            auto result = ctx->string_literal()->getText();
            return result.substr(1, result.size() - 2);
        }
        return ctx->getText();
    }

    /*!
     * \brief Get identifier
     * \param[in] ctx The context
     * \return The string
     */
    template <typename C>
    std::string GetIdentifier(C *ctx)
    {
        if (ctx->identifier())
        {
            auto identifier = ctx->identifier();
            if (identifier->BQUOTED_STRING())
            {
                auto result = identifier->getText();
                return result.substr(1, result.size() - 2);
            }
            return identifier->getText();
        }
        return ctx->getText();
    }
};

/*!
 * \brief Schema definition state
 */
enum class SchemaDefinitionState
{
    parse,
    createTable,
    createDef,
    alterTable,
    alterSpec,
    columnDef,
    columnOpt,
    dataType,
    enumValues,
    indexDef,
    indexOpt,
    tableOpt,
    reference,
    unionOpt,
    check
};

/*!
 * \brief Schema definition visitor
 */
class SchemaDefinitionVisitor : public StatefulVisitor<SchemaDefinitionState>, public GraphBuilder
{
    using GraphBuilder::GraphBuilder;

public:
    antlrcpp::Any visitParse(mysqlParser::ParseContext *ctx) override
    {
        return EnterState(ctx, State::parse);
    }

    antlrcpp::Any visitCreate_table(mysqlParser::Create_tableContext *ctx) override
    {
        return EnterState(ctx, State::createTable);
    }

    antlrcpp::Any visitAlter_table(mysqlParser::Alter_tableContext *ctx) override
    {
        return EnterState(ctx, State::alterTable);
    }

    antlrcpp::Any visitCreate_definition(mysqlParser::Create_definitionContext *ctx) override
    {
        return EnterState(ctx, State::createDef);
    }

    antlrcpp::Any visitAlter_specification(mysqlParser::Alter_specificationContext *ctx) override
    {
        return EnterState(ctx, State::alterSpec);
    }

    antlrcpp::Any visitColumn_definition(mysqlParser::Column_definitionContext *ctx) override
    {
        return EnterState(ctx, State::columnDef);
    }

    antlrcpp::Any visitColumn_options(mysqlParser::Column_optionsContext *ctx) override
    {
        if (ctx->NOT() && ctx->NULL())
        {
            GetCurrentField().properties[CPPORM_PROP_NOT_NULL] = "";
        }
        if (ctx->AUTO_INCREMENT())
        {
            GetCurrentField().properties[CPPORM_PROP_IDENTITY] = "";
        }
        if (ctx->UNIQUE())
        {
            auto &index = GetCurrentIndex();
            index.type = "UNIQUE";
            index.fieldNames.push_back(mFieldName);
        }
        else if (ctx->PRIMARY() || ctx->KEY())
        {
            auto &index = GetCurrentIndex();
            index.type = "PRIMARY_KEY";
            index.fieldNames.push_back(mFieldName);
        }
        return EnterState(ctx, State::columnOpt);
    }

    antlrcpp::Any visitDefault_value(mysqlParser::Default_valueContext *ctx) override
    {
        if (mStates.top() == State::columnOpt)
            GetCurrentField().properties["DEFAULT"] = GetLiteral(ctx);
        return visitChildren(ctx);
    }

    antlrcpp::Any visitComment(mysqlParser::CommentContext *ctx) override
    {
        switch (mStates.top())
        {
        case State::columnOpt:
            GetCurrentField().properties["COMMENT"] = GetStringLiteral(ctx);
            break;
        case State::indexOpt:
            GetCurrentIndex().properties["COMMENT"] = GetStringLiteral(ctx);
            break;
        case State::tableOpt:
            GetCurrentNode().properties["COMMENT"] = GetStringLiteral(ctx);
            break;
        default:
            break;
        }
        return visitChildren(ctx);
    }

    antlrcpp::Any visitColumn_format(mysqlParser::Column_formatContext *ctx) override
    {
        if (mStates.top() == State::columnOpt)
            GetCurrentField().properties["COLUMN_FORMAT"] = ctx->getText();
        return visitChildren(ctx);
    }

    antlrcpp::Any visitColumn_storage(mysqlParser::Column_storageContext *ctx) override
    {
        if (mStates.top() == State::columnOpt)
            GetCurrentField().properties["STORAGE"] = ctx->getText();
        return visitChildren(ctx);
    }

    antlrcpp::Any visitExpression(mysqlParser::ExpressionContext *ctx) override
    {
        switch (mStates.top())
        {
        case State::columnOpt:
            GetCurrentField().properties["AS"] = GetLiteral(ctx);
            break;
        case State::check:
            GetCurrentCheck().expression = GetLiteral(ctx);
            break;
        default:
            break;
        }
        return visitChildren(ctx);
    }

    antlrcpp::Any visitGenerated_column_options(
        mysqlParser::Generated_column_optionsContext *ctx) override
    {
        if (ctx->NULL() && ctx->NOT())
        {
            GetCurrentField().properties[CPPORM_PROP_NOT_NULL] = "";
            return visitChildren(ctx);
        }
        else if (ctx->GENERATED() && ctx->ALWAYS())
        {
            GetCurrentField().properties["GENERATED_ALWAYS"] = "";
            return visitChildren(ctx);
        }
        else if (ctx->VIRTUAL())
        {
            GetCurrentField().properties["TYPE"] = ctx->VIRTUAL()->getText();
            return visitChildren(ctx);
        }
        else if (ctx->STORED())
        {
            GetCurrentField().properties["TYPE"] = ctx->STORED()->getText();
            return visitChildren(ctx);
        }
        else if (ctx->UNIQUE())
        {
            auto &index = GetCurrentIndex();
            index.type = "UNIQUE";
            index.fieldNames.push_back(mFieldName);
            return visitChildren(ctx);
        }
        else if (ctx->PRIMARY())
        {
            auto &index = GetCurrentIndex();
            index.type = "PRIMARY_KEY";
            index.fieldNames.push_back(mFieldName);
            return visitChildren(ctx);
        }
        return EnterState(ctx, State::columnOpt);
    }

    /*!
     * \brief Visit column data type
     * \param[in] ctx The context
     * \return The aggregate result
     */
    antlrcpp::Any visitData_type(mysqlParser::Data_typeContext *ctx) override
    {
        if (ctx->UNSIGNED())
            GetCurrentField().properties["UNSIGNED"] = "";
        if (ctx->ZEROFILL())
            GetCurrentField().properties["ZEROFILL"] = "";
        if (ctx->BINARY())
            GetCurrentField().properties["BINARY"] = "";
        if (ctx->JSON())
        {
            GetCurrentField().dataType = ctx->JSON()->getText();
            return visitChildren(ctx);
        }
        return EnterState(ctx, State::dataType);
    }

    antlrcpp::Any visitFsp(mysqlParser::FspContext *ctx) override
    {
        if (mStates.top() == State::dataType)
            GetCurrentField().properties["FSP"] = GetIntegerLiteral(ctx);
        return visitChildren(ctx);
    }

    antlrcpp::Any visitLength(mysqlParser::LengthContext *ctx) override
    {
        if (mStates.top() == State::dataType)
            GetCurrentField().properties["LENGTH"] = GetIntegerLiteral(ctx);
        return visitChildren(ctx);
    }

    antlrcpp::Any visitDecimals(mysqlParser::DecimalsContext *ctx) override
    {
        if (mStates.top() == State::dataType)
            GetCurrentField().properties["DECIMALS"] = GetIntegerLiteral(ctx);
        return visitChildren(ctx);
    }

    antlrcpp::Any visitOn_update_set(mysqlParser::On_update_setContext *ctx) override
    {
        if (mStates.top() == State::columnOpt)
            GetCurrentField().properties[CPPORM_PROP_ON_UPDATE] = GetLiteral(ctx);
        return visitChildren(ctx);
    }

    antlrcpp::Any visitCharset_name(mysqlParser::Charset_nameContext *ctx) override
    {
        switch (mStates.top())
        {
        case State::dataType:
            GetCurrentField().properties["CHARSET"] = GetIdentifier(ctx);
            break;
        case State::tableOpt:
            GetCurrentNode().properties["CHARSET"] = GetIdentifier(ctx);
            break;
        default:
            break;
        }
        return visitChildren(ctx);
    }

    antlrcpp::Any visitCollation_name(mysqlParser::Collation_nameContext *ctx) override
    {
        switch (mStates.top())
        {
        case State::dataType:
            GetCurrentField().properties["COLLATE"] = GetIdentifier(ctx);
            break;
        case State::tableOpt:
            GetCurrentNode().properties["COLLATE"] = GetIdentifier(ctx);
            break;
        default:
            break;
        }
        return visitChildren(ctx);
    }

    antlrcpp::Any visitEnum_value_list(mysqlParser::Enum_value_listContext *ctx) override
    {
        return EnterState(ctx, State::enumValues);
    }

    antlrcpp::Any visitLiteral(mysqlParser::LiteralContext *ctx) override
    {
        if (mStates.top() == State::enumValues)
        {
            auto &property = GetCurrentField().properties["VALUES"];
            if (!property.empty())
                property += ',';
            property += GetStringLiteral(ctx);
        }
        return visitChildren(ctx);
    }

    antlrcpp::Any visitInteger_type(mysqlParser::Integer_typeContext *ctx) override
    {
        if (mStates.top() == State::dataType)
            GetCurrentField().dataType = ctx->getText();
        return visitChildren(ctx);
    }

    antlrcpp::Any visitReal_type(mysqlParser::Real_typeContext *ctx) override
    {
        if (mStates.top() == State::dataType)
            GetCurrentField().dataType = ctx->getText();
        return visitChildren(ctx);
    }

    antlrcpp::Any visitText_type(mysqlParser::Text_typeContext *ctx) override
    {
        if (mStates.top() == State::dataType)
            GetCurrentField().dataType = ctx->getText();
        return visitChildren(ctx);
    }

    antlrcpp::Any visitBlob_type(mysqlParser::Blob_typeContext *ctx) override
    {
        if (mStates.top() == State::dataType)
            GetCurrentField().dataType = ctx->getText();
        return visitChildren(ctx);
    }

    antlrcpp::Any visitSpatial_type(mysqlParser::Spatial_typeContext *ctx) override
    {
        if (mStates.top() == State::dataType)
            GetCurrentField().dataType = ctx->getText();
        return visitChildren(ctx);
    }

    antlrcpp::Any visitEnum_type(mysqlParser::Enum_typeContext *ctx) override
    {
        if (mStates.top() == State::dataType)
            GetCurrentField().dataType = ctx->getText();
        return visitChildren(ctx);
    }

    antlrcpp::Any visitBinary_type(mysqlParser::Binary_typeContext *ctx) override
    {
        if (mStates.top() == State::dataType)
            GetCurrentField().dataType = ctx->getText();
        return visitChildren(ctx);
    }

    antlrcpp::Any visitChar_type(mysqlParser::Char_typeContext *ctx) override
    {
        if (mStates.top() == State::dataType)
            GetCurrentField().dataType = ctx->getText();
        return visitChildren(ctx);
    }

    antlrcpp::Any visitDatetime_type(mysqlParser::Datetime_typeContext *ctx) override
    {
        if (mStates.top() == State::dataType)
            GetCurrentField().dataType = ctx->getText();
        return visitChildren(ctx);
    }

    antlrcpp::Any visitTable_name(mysqlParser::Table_nameContext *ctx) override
    {
        switch (mStates.top())
        {
        case State::reference:
            mRefNodeName = GetIdentifier(ctx);
            AddEdge();
            break;
        case State::createTable:
            mNodeName = GetIdentifier(ctx);
            GetCurrentNode().name = mNodeName;
        case State::alterTable:
            mNodeName = GetIdentifier(ctx);
            break;
        case State::unionOpt:
        {
            auto &property = GetCurrentNode().properties["UNION"];
            if (!property.empty())
                property += ',';
            property += GetIdentifier(ctx);
            break;
        }
        default:
            break;
        }
        return visitChildren(ctx);
    }

    antlrcpp::Any visitColumn_name(mysqlParser::Column_nameContext *ctx) override
    {
        switch (mStates.top())
        {
        case State::createDef:
            mFieldName = GetIdentifier(ctx);
            GetCurrentField().name = mFieldName;
            break;
        case State::indexDef:
            GetCurrentIndex().fieldNames.push_back(GetIdentifier(ctx));
            break;
        case State::reference:
            GetCurrentEdge().refFieldNames.push_back(GetIdentifier(ctx));
            break;
        default:
            break;
        }
        return visitChildren(ctx);
    }

    antlrcpp::Any visitIndex_definition(mysqlParser::Index_definitionContext *ctx) override
    {
        AddIndex();

        if (ctx->PRIMARY())
            GetCurrentIndex().type = "PRIMARY_KEY";
        else if (ctx->UNIQUE())
            GetCurrentIndex().type = "UNIQUE";
        else if (ctx->FOREIGN())
            GetCurrentIndex().type = "FOREIGN_KEY";
        else if (ctx->FULLTEXT())
            GetCurrentIndex().type = "FULLTEXT";
        else if (ctx->SPATIAL())
            GetCurrentIndex().type = "SPATIAL";
        else if (ctx->INDEX())
            GetCurrentIndex().type = "INDEX";
        else if (ctx->KEY())
            GetCurrentIndex().type = "KEY";

        auto result = EnterState(ctx, State::indexDef);
        if (GetCurrentIndex().type == "FOREIGN_KEY")
        {
            auto &edge = GetCurrentEdge();
            edge.indexNumber = GetCurrentNode().indices.size();
            edge.refNodeName = mRefNodeName;
        }
        return result;
    }

    antlrcpp::Any visitReference_definition(mysqlParser::Reference_definitionContext *ctx) override
    {
        return EnterState(ctx, State::reference);
    }

    antlrcpp::Any visitMatch_option(mysqlParser::Match_optionContext *ctx) override
    {
        if (mStates.top() == State::reference)
            GetCurrentIndex().properties["MATCH"] = ctx->getText();
        return visitChildren(ctx);
    }

    antlrcpp::Any visitOn_delete_option(mysqlParser::On_delete_optionContext *ctx) override
    {
        if (mStates.top() == State::reference)
            GetCurrentIndex().properties[CPPORM_PROP_ON_DELETE] = ctx->getText();
        return visitChildren(ctx);
    }

    antlrcpp::Any visitOn_update_option(mysqlParser::On_update_optionContext *ctx) override
    {
        if (mStates.top() == State::reference)
            GetCurrentIndex().properties[CPPORM_PROP_ON_UPDATE] = ctx->getText();
        return visitChildren(ctx);
    }

    antlrcpp::Any visitIndex_option(mysqlParser::Index_optionContext *ctx) override
    {
        return EnterState(ctx, State::indexOpt);
    }

    antlrcpp::Any visitIndex_structure(mysqlParser::Index_structureContext *ctx) override
    {
        if (mStates.top() == State::indexOpt)
            GetCurrentIndex().properties["STRUCTURE"] = ctx->getText();
        return visitChildren(ctx);
    }

    antlrcpp::Any visitParser_name(mysqlParser::Parser_nameContext *ctx) override
    {
        if (mStates.top() == State::indexOpt)
            GetCurrentIndex().properties["PARSER_NAME"] = GetIdentifier(ctx);
        return visitChildren(ctx);
    }

    antlrcpp::Any visitCheck_expression(mysqlParser::Check_expressionContext *ctx) override
    {
        AddCheck();
        return EnterState(ctx, State::check);
    }

    antlrcpp::Any visitTable_option(mysqlParser::Table_optionContext *ctx) override
    {
        return EnterState(ctx, State::tableOpt);
    }

    antlrcpp::Any visitConnection(mysqlParser::ConnectionContext *ctx) override
    {
        if (mStates.top() == State::tableOpt)
            GetCurrentNode().properties["CONNECTION"] = GetStringLiteral(ctx);
        return visitChildren(ctx);
    }

    antlrcpp::Any visitPassword(mysqlParser::PasswordContext *ctx) override
    {
        if (mStates.top() == State::tableOpt)
            GetCurrentNode().properties["PASSWORD"] = GetStringLiteral(ctx);
        return visitChildren(ctx);
    }

    antlrcpp::Any visitData_directory(mysqlParser::Data_directoryContext *ctx) override
    {
        if (mStates.top() == State::tableOpt)
            GetCurrentNode().properties["DATA_DIRECTORY"] = GetStringLiteral(ctx);
        return visitChildren(ctx);
    }

    antlrcpp::Any visitIndex_directory(mysqlParser::Index_directoryContext *ctx) override
    {
        if (mStates.top() == State::tableOpt)
            GetCurrentNode().properties["INDEX_DIRECTORY"] = GetStringLiteral(ctx);
        return visitChildren(ctx);
    }

    antlrcpp::Any visitEngine_name(mysqlParser::Engine_nameContext *ctx) override
    {
        if (mStates.top() == State::tableOpt)
            GetCurrentNode().properties["ENGINE_NAME"] = GetIdentifier(ctx);
        return visitChildren(ctx);
    }

    antlrcpp::Any visitAuto_increment(mysqlParser::Auto_incrementContext *ctx) override
    {
        if (mStates.top() == State::tableOpt)
            GetCurrentNode().properties["AUTO_INCREMENT"] = GetIntegerLiteral(ctx);
        return visitChildren(ctx);
    }

    antlrcpp::Any visitAvg_row_length(mysqlParser::Avg_row_lengthContext *ctx) override
    {
        if (mStates.top() == State::tableOpt)
            GetCurrentNode().properties["AVG_ROW_LENGTH"] = GetIntegerLiteral(ctx);
        return visitChildren(ctx);
    }

    antlrcpp::Any visitKey_block_size(mysqlParser::Key_block_sizeContext *ctx) override
    {
        if (mStates.top() == State::tableOpt)
            GetCurrentNode().properties["KEY_BLOCK_SIZE"] = GetIntegerLiteral(ctx);
        return visitChildren(ctx);
    }

    antlrcpp::Any visitMax_number_of_rows(mysqlParser::Max_number_of_rowsContext *ctx) override
    {
        if (mStates.top() == State::tableOpt)
            GetCurrentNode().properties["MAX_ROWS"] = GetIntegerLiteral(ctx);
        return visitChildren(ctx);
    }

    antlrcpp::Any visitMin_number_of_rows(mysqlParser::Min_number_of_rowsContext *ctx) override
    {
        if (mStates.top() == State::tableOpt)
            GetCurrentNode().properties["MIN_ROWS"] = GetIntegerLiteral(ctx);
        return visitChildren(ctx);
    }

    antlrcpp::Any visitStats_sample_pages(mysqlParser::Stats_sample_pagesContext *ctx) override
    {
        if (mStates.top() == State::tableOpt)
            GetCurrentNode().properties["STATS_SAMPLE_PAGES"] = GetIntegerLiteral(ctx);
        return visitChildren(ctx);
    }

    antlrcpp::Any visitChecksum(mysqlParser::ChecksumContext *ctx) override
    {
        if (mStates.top() == State::tableOpt)
            GetCurrentNode().properties["CHECKSUM"] = ctx->getText();
        return visitChildren(ctx);
    }

    antlrcpp::Any visitCompression(mysqlParser::CompressionContext *ctx) override
    {
        if (mStates.top() == State::tableOpt)
            GetCurrentNode().properties["COMPRESSION"] = ctx->getText();
        return visitChildren(ctx);
    }

    antlrcpp::Any visitDelay_key_write(mysqlParser::Delay_key_writeContext *ctx) override
    {
        if (mStates.top() == State::tableOpt)
            GetCurrentNode().properties["DELAY_KEY_WRITE"] = ctx->getText();
        return visitChildren(ctx);
    }

    antlrcpp::Any visitEncryption(mysqlParser::EncryptionContext *ctx) override
    {
        if (mStates.top() == State::tableOpt)
            GetCurrentNode().properties["ENCRYPTION"] = ctx->getText();
        return visitChildren(ctx);
    }

    antlrcpp::Any visitInsert_method(mysqlParser::Insert_methodContext *ctx) override
    {
        if (mStates.top() == State::tableOpt)
            GetCurrentNode().properties["INSERT_METHOD"] = ctx->getText();
        return visitChildren(ctx);
    }

    antlrcpp::Any visitPack_keys(mysqlParser::Pack_keysContext *ctx) override
    {
        if (mStates.top() == State::tableOpt)
            GetCurrentNode().properties["PACK_KEYS"] = ctx->getText();
        return visitChildren(ctx);
    }

    antlrcpp::Any visitRow_format(mysqlParser::Row_formatContext *ctx) override
    {
        if (mStates.top() == State::tableOpt)
            GetCurrentNode().properties["ROW_FORMAT"] = ctx->getText();
        return visitChildren(ctx);
    }

    antlrcpp::Any visitStats_auto_recalc(mysqlParser::Stats_auto_recalcContext *ctx) override
    {
        if (mStates.top() == State::tableOpt)
            GetCurrentNode().properties["STATS_AUTO_RECALC"] = ctx->getText();
        return visitChildren(ctx);
    }

    antlrcpp::Any visitStats_persistent(mysqlParser::Stats_persistentContext *ctx) override
    {
        if (mStates.top() == State::tableOpt)
            GetCurrentNode().properties["STATS_PERSISTENT"] = ctx->getText();
        return visitChildren(ctx);
    }

    antlrcpp::Any visitTablespace_name(mysqlParser::Tablespace_nameContext *ctx) override
    {
        if (mStates.top() == State::tableOpt)
            GetCurrentNode().properties["TABLESPACE"] = GetIdentifier(ctx);
        return visitChildren(ctx);
    }

    antlrcpp::Any visitTable_union_list(mysqlParser::Table_union_listContext *ctx) override
    {
        if (mStates.top() == State::tableOpt)
            return EnterState(ctx, State::unionOpt);
        else
            return visitChildren(ctx);
    }
};

/*!
 * \details
 */
void Serializer::Parse(const std::string &filename, ListGraph &graph)
{
    std::ifstream stream(filename);

    ANTLRInputStream input(stream);
    mysqlLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    tokens.fill();

#ifndef NDEBUG
    for (auto token : tokens.getTokens())
        std::cout << token->toString() << std::endl;
#endif

    mysqlParser parser(&tokens);
    auto tree = parser.parse();

#ifndef NDEBUG
    std::cout << tree->toStringTree(&parser) << std::endl;
#endif

    SchemaDefinitionVisitor schemaDefinitionVisitor(graph);
    schemaDefinitionVisitor.visit(tree.get());
}

/*!
 * \details
 */
void Serializer::Write(const std::string &, const std::string &, const ListGraph &)
{
    throw cpporm::NotImplementedError(
        "mysql::Serializer::Write(const std::string &, const std::string &, const ListGraph &)");
}

} // namespace mysql
