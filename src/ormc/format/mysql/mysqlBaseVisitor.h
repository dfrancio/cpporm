
// Generated from grammars/mysql/mysql.g4 by ANTLR 4.6

#pragma once

#include "antlr4-runtime.h"
#include "mysqlVisitor.h"

namespace mysql
{

/**
 * This class provides an empty implementation of mysqlVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class mysqlBaseVisitor : public mysqlVisitor
{
public:
    virtual antlrcpp::Any visitParse(mysqlParser::ParseContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitStatement(mysqlParser::StatementContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitAssignment(mysqlParser::AssignmentContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitDrop_table(mysqlParser::Drop_tableContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitTable_name_list(mysqlParser::Table_name_listContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitCreate_table(mysqlParser::Create_tableContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitCreate_definition(
        mysqlParser::Create_definitionContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitIndex_definition(mysqlParser::Index_definitionContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitColumn_definition(
        mysqlParser::Column_definitionContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitColumn_options(mysqlParser::Column_optionsContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitGenerated_column_options(
        mysqlParser::Generated_column_optionsContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitData_type(mysqlParser::Data_typeContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitTable_option(mysqlParser::Table_optionContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitPartition_specification(
        mysqlParser::Partition_specificationContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitPartition_definition_list(
        mysqlParser::Partition_definition_listContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitPartition_by(mysqlParser::Partition_byContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitSubpartition_by(mysqlParser::Subpartition_byContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitPartition_definition(
        mysqlParser::Partition_definitionContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitSubpartition_definition_list(
        mysqlParser::Subpartition_definition_listContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitPartition_values(mysqlParser::Partition_valuesContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitSubpartition_definition(
        mysqlParser::Subpartition_definitionContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitPartition_options(
        mysqlParser::Partition_optionsContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitIndex_option(mysqlParser::Index_optionContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitReference_definition(
        mysqlParser::Reference_definitionContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitCreate_definition_list(
        mysqlParser::Create_definition_listContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitTable_option_list(
        mysqlParser::Table_option_listContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitIndex_option_list(
        mysqlParser::Index_option_listContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitIndex_column_list(
        mysqlParser::Index_column_listContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitLess_than_value_list(
        mysqlParser::Less_than_value_listContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitIn_value_list(mysqlParser::In_value_listContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitEnum_value_list(mysqlParser::Enum_value_listContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitKey_column_list(mysqlParser::Key_column_listContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitRange_column_list(
        mysqlParser::Range_column_listContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitList_column_list(mysqlParser::List_column_listContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitTable_union_list(mysqlParser::Table_union_listContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitConstraint(mysqlParser::ConstraintContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitCharset(mysqlParser::CharsetContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitCollation(mysqlParser::CollationContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitIndex_structure(mysqlParser::Index_structureContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitIndex_column(mysqlParser::Index_columnContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitFsp(mysqlParser::FspContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitLength(mysqlParser::LengthContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitDecimals(mysqlParser::DecimalsContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitPartition_count(mysqlParser::Partition_countContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitSubpartition_count(
        mysqlParser::Subpartition_countContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitAuto_increment(mysqlParser::Auto_incrementContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitAvg_row_length(mysqlParser::Avg_row_lengthContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitKey_block_size(mysqlParser::Key_block_sizeContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitMax_number_of_rows(
        mysqlParser::Max_number_of_rowsContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitMin_number_of_rows(
        mysqlParser::Min_number_of_rowsContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitStats_sample_pages(
        mysqlParser::Stats_sample_pagesContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitChecksum(mysqlParser::ChecksumContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitCompression(mysqlParser::CompressionContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitDelay_key_write(mysqlParser::Delay_key_writeContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitEncryption(mysqlParser::EncryptionContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitInsert_method(mysqlParser::Insert_methodContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitPack_keys(mysqlParser::Pack_keysContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitRow_format(mysqlParser::Row_formatContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitStats_auto_recalc(
        mysqlParser::Stats_auto_recalcContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitStats_persistent(mysqlParser::Stats_persistentContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitKey_algorithm(mysqlParser::Key_algorithmContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitMatch_option(mysqlParser::Match_optionContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitOn_delete_option(mysqlParser::On_delete_optionContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitOn_update_option(mysqlParser::On_update_optionContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitColumn_format(mysqlParser::Column_formatContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitColumn_storage(mysqlParser::Column_storageContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitInteger_type(mysqlParser::Integer_typeContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitReal_type(mysqlParser::Real_typeContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitText_type(mysqlParser::Text_typeContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitBlob_type(mysqlParser::Blob_typeContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitSpatial_type(mysqlParser::Spatial_typeContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitEnum_type(mysqlParser::Enum_typeContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitBinary_type(mysqlParser::Binary_typeContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitChar_type(mysqlParser::Char_typeContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitDatetime_type(mysqlParser::Datetime_typeContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitOn_update_set(mysqlParser::On_update_setContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitDefault_value(mysqlParser::Default_valueContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitComment(mysqlParser::CommentContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitConnection(mysqlParser::ConnectionContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitPassword(mysqlParser::PasswordContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitData_directory(mysqlParser::Data_directoryContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitIndex_directory(mysqlParser::Index_directoryContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitAs_expression(mysqlParser::As_expressionContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitQuery_expression(mysqlParser::Query_expressionContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitCheck_expression(mysqlParser::Check_expressionContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitHash_expression(mysqlParser::Hash_expressionContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitRange_expression(mysqlParser::Range_expressionContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitList_expression(mysqlParser::List_expressionContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitLess_than_expression(
        mysqlParser::Less_than_expressionContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitExpression(mysqlParser::ExpressionContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitSymbol(mysqlParser::SymbolContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitEngine_name(mysqlParser::Engine_nameContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitOld_table_name(mysqlParser::Old_table_nameContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitColumn_name(mysqlParser::Column_nameContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitIndex_name(mysqlParser::Index_nameContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitTablespace_name(mysqlParser::Tablespace_nameContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitTable_name(mysqlParser::Table_nameContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitDatabase_name(mysqlParser::Database_nameContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitParser_name(mysqlParser::Parser_nameContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitCharset_name(mysqlParser::Charset_nameContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitCollation_name(mysqlParser::Collation_nameContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitPartition_name(mysqlParser::Partition_nameContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitLogical_name(mysqlParser::Logical_nameContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitLiteral(mysqlParser::LiteralContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitIdentifier(mysqlParser::IdentifierContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitBool_literal(mysqlParser::Bool_literalContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitFloat_literal(mysqlParser::Float_literalContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitInteger_literal(mysqlParser::Integer_literalContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitString_literal(mysqlParser::String_literalContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitDatetime_literal(mysqlParser::Datetime_literalContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitAlter_table(mysqlParser::Alter_tableContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitAlter_specification(
        mysqlParser::Alter_specificationContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitAlter_specification_list(
        mysqlParser::Alter_specification_listContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitColumn_name_list(mysqlParser::Column_name_listContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitPartition_name_list(
        mysqlParser::Partition_name_listContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitColumn_definition_list(
        mysqlParser::Column_definition_listContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitTable_algorithm(mysqlParser::Table_algorithmContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitTable_lock(mysqlParser::Table_lockContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitFirst_after(mysqlParser::First_afterContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitFk_symbol(mysqlParser::Fk_symbolContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitNew_table_name(mysqlParser::New_table_nameContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitOld_column_name(mysqlParser::Old_column_nameContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitNew_column_name(mysqlParser::New_column_nameContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitOld_index_name(mysqlParser::Old_index_nameContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitNew_index_name(mysqlParser::New_index_nameContext *ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitPartition_number(mysqlParser::Partition_numberContext *ctx) override
    {
        return visitChildren(ctx);
    }
};

} // namespace mysql
