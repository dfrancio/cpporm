
// Generated from grammars/mysql/mysql.g4 by ANTLR 4.5.3

#pragma once

#include "antlr4-runtime.h"
#include "mysqlParser.h"

namespace mysql
{

/**
 * This class defines an abstract visitor for a parse tree
 * produced by mysqlParser.
 */
class mysqlVisitor : public antlr4::tree::AbstractParseTreeVisitor
{
public:
    /**
     * Visit parse trees produced by mysqlParser.
     */
    virtual antlrcpp::Any visitParse(mysqlParser::ParseContext *context) = 0;

    virtual antlrcpp::Any visitStatement(mysqlParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitAssignment(mysqlParser::AssignmentContext *context) = 0;

    virtual antlrcpp::Any visitDrop_table(mysqlParser::Drop_tableContext *context) = 0;

    virtual antlrcpp::Any visitTable_name_list(mysqlParser::Table_name_listContext *context) = 0;

    virtual antlrcpp::Any visitCreate_table(mysqlParser::Create_tableContext *context) = 0;

    virtual antlrcpp::Any visitCreate_definition(mysqlParser::Create_definitionContext *context)
        = 0;

    virtual antlrcpp::Any visitIndex_definition(mysqlParser::Index_definitionContext *context) = 0;

    virtual antlrcpp::Any visitColumn_definition(mysqlParser::Column_definitionContext *context)
        = 0;

    virtual antlrcpp::Any visitColumn_options(mysqlParser::Column_optionsContext *context) = 0;

    virtual antlrcpp::Any visitGenerated_column_options(
        mysqlParser::Generated_column_optionsContext *context)
        = 0;

    virtual antlrcpp::Any visitData_type(mysqlParser::Data_typeContext *context) = 0;

    virtual antlrcpp::Any visitTable_option(mysqlParser::Table_optionContext *context) = 0;

    virtual antlrcpp::Any visitPartition_specification(
        mysqlParser::Partition_specificationContext *context)
        = 0;

    virtual antlrcpp::Any visitPartition_definition_list(
        mysqlParser::Partition_definition_listContext *context)
        = 0;

    virtual antlrcpp::Any visitPartition_by(mysqlParser::Partition_byContext *context) = 0;

    virtual antlrcpp::Any visitSubpartition_by(mysqlParser::Subpartition_byContext *context) = 0;

    virtual antlrcpp::Any visitPartition_definition(
        mysqlParser::Partition_definitionContext *context)
        = 0;

    virtual antlrcpp::Any visitSubpartition_definition_list(
        mysqlParser::Subpartition_definition_listContext *context)
        = 0;

    virtual antlrcpp::Any visitPartition_values(mysqlParser::Partition_valuesContext *context) = 0;

    virtual antlrcpp::Any visitSubpartition_definition(
        mysqlParser::Subpartition_definitionContext *context)
        = 0;

    virtual antlrcpp::Any visitPartition_options(mysqlParser::Partition_optionsContext *context)
        = 0;

    virtual antlrcpp::Any visitIndex_option(mysqlParser::Index_optionContext *context) = 0;

    virtual antlrcpp::Any visitReference_definition(
        mysqlParser::Reference_definitionContext *context)
        = 0;

    virtual antlrcpp::Any visitCreate_definition_list(
        mysqlParser::Create_definition_listContext *context)
        = 0;

    virtual antlrcpp::Any visitTable_option_list(mysqlParser::Table_option_listContext *context)
        = 0;

    virtual antlrcpp::Any visitIndex_option_list(mysqlParser::Index_option_listContext *context)
        = 0;

    virtual antlrcpp::Any visitIndex_column_list(mysqlParser::Index_column_listContext *context)
        = 0;

    virtual antlrcpp::Any visitLess_than_value_list(
        mysqlParser::Less_than_value_listContext *context)
        = 0;

    virtual antlrcpp::Any visitIn_value_list(mysqlParser::In_value_listContext *context) = 0;

    virtual antlrcpp::Any visitEnum_value_list(mysqlParser::Enum_value_listContext *context) = 0;

    virtual antlrcpp::Any visitKey_column_list(mysqlParser::Key_column_listContext *context) = 0;

    virtual antlrcpp::Any visitRange_column_list(mysqlParser::Range_column_listContext *context)
        = 0;

    virtual antlrcpp::Any visitList_column_list(mysqlParser::List_column_listContext *context) = 0;

    virtual antlrcpp::Any visitTable_union_list(mysqlParser::Table_union_listContext *context) = 0;

    virtual antlrcpp::Any visitConstraint(mysqlParser::ConstraintContext *context) = 0;

    virtual antlrcpp::Any visitCharset(mysqlParser::CharsetContext *context) = 0;

    virtual antlrcpp::Any visitCollation(mysqlParser::CollationContext *context) = 0;

    virtual antlrcpp::Any visitIndex_structure(mysqlParser::Index_structureContext *context) = 0;

    virtual antlrcpp::Any visitIndex_column(mysqlParser::Index_columnContext *context) = 0;

    virtual antlrcpp::Any visitFsp(mysqlParser::FspContext *context) = 0;

    virtual antlrcpp::Any visitLength(mysqlParser::LengthContext *context) = 0;

    virtual antlrcpp::Any visitDecimals(mysqlParser::DecimalsContext *context) = 0;

    virtual antlrcpp::Any visitPartition_count(mysqlParser::Partition_countContext *context) = 0;

    virtual antlrcpp::Any visitSubpartition_count(mysqlParser::Subpartition_countContext *context)
        = 0;

    virtual antlrcpp::Any visitAuto_increment(mysqlParser::Auto_incrementContext *context) = 0;

    virtual antlrcpp::Any visitAvg_row_length(mysqlParser::Avg_row_lengthContext *context) = 0;

    virtual antlrcpp::Any visitKey_block_size(mysqlParser::Key_block_sizeContext *context) = 0;

    virtual antlrcpp::Any visitMax_number_of_rows(mysqlParser::Max_number_of_rowsContext *context)
        = 0;

    virtual antlrcpp::Any visitMin_number_of_rows(mysqlParser::Min_number_of_rowsContext *context)
        = 0;

    virtual antlrcpp::Any visitStats_sample_pages(mysqlParser::Stats_sample_pagesContext *context)
        = 0;

    virtual antlrcpp::Any visitChecksum(mysqlParser::ChecksumContext *context) = 0;

    virtual antlrcpp::Any visitCompression(mysqlParser::CompressionContext *context) = 0;

    virtual antlrcpp::Any visitDelay_key_write(mysqlParser::Delay_key_writeContext *context) = 0;

    virtual antlrcpp::Any visitEncryption(mysqlParser::EncryptionContext *context) = 0;

    virtual antlrcpp::Any visitInsert_method(mysqlParser::Insert_methodContext *context) = 0;

    virtual antlrcpp::Any visitPack_keys(mysqlParser::Pack_keysContext *context) = 0;

    virtual antlrcpp::Any visitRow_format(mysqlParser::Row_formatContext *context) = 0;

    virtual antlrcpp::Any visitStats_auto_recalc(mysqlParser::Stats_auto_recalcContext *context)
        = 0;

    virtual antlrcpp::Any visitStats_persistent(mysqlParser::Stats_persistentContext *context) = 0;

    virtual antlrcpp::Any visitKey_algorithm(mysqlParser::Key_algorithmContext *context) = 0;

    virtual antlrcpp::Any visitMatch_option(mysqlParser::Match_optionContext *context) = 0;

    virtual antlrcpp::Any visitOn_delete_option(mysqlParser::On_delete_optionContext *context) = 0;

    virtual antlrcpp::Any visitOn_update_option(mysqlParser::On_update_optionContext *context) = 0;

    virtual antlrcpp::Any visitColumn_format(mysqlParser::Column_formatContext *context) = 0;

    virtual antlrcpp::Any visitColumn_storage(mysqlParser::Column_storageContext *context) = 0;

    virtual antlrcpp::Any visitInteger_type(mysqlParser::Integer_typeContext *context) = 0;

    virtual antlrcpp::Any visitReal_type(mysqlParser::Real_typeContext *context) = 0;

    virtual antlrcpp::Any visitText_type(mysqlParser::Text_typeContext *context) = 0;

    virtual antlrcpp::Any visitBlob_type(mysqlParser::Blob_typeContext *context) = 0;

    virtual antlrcpp::Any visitSpatial_type(mysqlParser::Spatial_typeContext *context) = 0;

    virtual antlrcpp::Any visitEnum_type(mysqlParser::Enum_typeContext *context) = 0;

    virtual antlrcpp::Any visitBinary_type(mysqlParser::Binary_typeContext *context) = 0;

    virtual antlrcpp::Any visitChar_type(mysqlParser::Char_typeContext *context) = 0;

    virtual antlrcpp::Any visitDatetime_type(mysqlParser::Datetime_typeContext *context) = 0;

    virtual antlrcpp::Any visitOn_update_set(mysqlParser::On_update_setContext *context) = 0;

    virtual antlrcpp::Any visitDefault_value(mysqlParser::Default_valueContext *context) = 0;

    virtual antlrcpp::Any visitComment(mysqlParser::CommentContext *context) = 0;

    virtual antlrcpp::Any visitConnection(mysqlParser::ConnectionContext *context) = 0;

    virtual antlrcpp::Any visitPassword(mysqlParser::PasswordContext *context) = 0;

    virtual antlrcpp::Any visitData_directory(mysqlParser::Data_directoryContext *context) = 0;

    virtual antlrcpp::Any visitIndex_directory(mysqlParser::Index_directoryContext *context) = 0;

    virtual antlrcpp::Any visitAs_expression(mysqlParser::As_expressionContext *context) = 0;

    virtual antlrcpp::Any visitQuery_expression(mysqlParser::Query_expressionContext *context) = 0;

    virtual antlrcpp::Any visitCheck_expression(mysqlParser::Check_expressionContext *context) = 0;

    virtual antlrcpp::Any visitHash_expression(mysqlParser::Hash_expressionContext *context) = 0;

    virtual antlrcpp::Any visitRange_expression(mysqlParser::Range_expressionContext *context) = 0;

    virtual antlrcpp::Any visitList_expression(mysqlParser::List_expressionContext *context) = 0;

    virtual antlrcpp::Any visitLess_than_expression(
        mysqlParser::Less_than_expressionContext *context)
        = 0;

    virtual antlrcpp::Any visitExpression(mysqlParser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitSymbol(mysqlParser::SymbolContext *context) = 0;

    virtual antlrcpp::Any visitEngine_name(mysqlParser::Engine_nameContext *context) = 0;

    virtual antlrcpp::Any visitOld_table_name(mysqlParser::Old_table_nameContext *context) = 0;

    virtual antlrcpp::Any visitColumn_name(mysqlParser::Column_nameContext *context) = 0;

    virtual antlrcpp::Any visitIndex_name(mysqlParser::Index_nameContext *context) = 0;

    virtual antlrcpp::Any visitTablespace_name(mysqlParser::Tablespace_nameContext *context) = 0;

    virtual antlrcpp::Any visitTable_name(mysqlParser::Table_nameContext *context) = 0;

    virtual antlrcpp::Any visitDatabase_name(mysqlParser::Database_nameContext *context) = 0;

    virtual antlrcpp::Any visitParser_name(mysqlParser::Parser_nameContext *context) = 0;

    virtual antlrcpp::Any visitCharset_name(mysqlParser::Charset_nameContext *context) = 0;

    virtual antlrcpp::Any visitCollation_name(mysqlParser::Collation_nameContext *context) = 0;

    virtual antlrcpp::Any visitPartition_name(mysqlParser::Partition_nameContext *context) = 0;

    virtual antlrcpp::Any visitLogical_name(mysqlParser::Logical_nameContext *context) = 0;

    virtual antlrcpp::Any visitLiteral(mysqlParser::LiteralContext *context) = 0;

    virtual antlrcpp::Any visitIdentifier(mysqlParser::IdentifierContext *context) = 0;

    virtual antlrcpp::Any visitBool_literal(mysqlParser::Bool_literalContext *context) = 0;

    virtual antlrcpp::Any visitFloat_literal(mysqlParser::Float_literalContext *context) = 0;

    virtual antlrcpp::Any visitInteger_literal(mysqlParser::Integer_literalContext *context) = 0;

    virtual antlrcpp::Any visitString_literal(mysqlParser::String_literalContext *context) = 0;

    virtual antlrcpp::Any visitDatetime_literal(mysqlParser::Datetime_literalContext *context) = 0;

    virtual antlrcpp::Any visitAlter_table(mysqlParser::Alter_tableContext *context) = 0;

    virtual antlrcpp::Any visitAlter_specification(mysqlParser::Alter_specificationContext *context)
        = 0;

    virtual antlrcpp::Any visitAlter_specification_list(
        mysqlParser::Alter_specification_listContext *context)
        = 0;

    virtual antlrcpp::Any visitColumn_name_list(mysqlParser::Column_name_listContext *context) = 0;

    virtual antlrcpp::Any visitPartition_name_list(mysqlParser::Partition_name_listContext *context)
        = 0;

    virtual antlrcpp::Any visitColumn_definition_list(
        mysqlParser::Column_definition_listContext *context)
        = 0;

    virtual antlrcpp::Any visitTable_algorithm(mysqlParser::Table_algorithmContext *context) = 0;

    virtual antlrcpp::Any visitTable_lock(mysqlParser::Table_lockContext *context) = 0;

    virtual antlrcpp::Any visitFirst_after(mysqlParser::First_afterContext *context) = 0;

    virtual antlrcpp::Any visitFk_symbol(mysqlParser::Fk_symbolContext *context) = 0;

    virtual antlrcpp::Any visitNew_table_name(mysqlParser::New_table_nameContext *context) = 0;

    virtual antlrcpp::Any visitOld_column_name(mysqlParser::Old_column_nameContext *context) = 0;

    virtual antlrcpp::Any visitNew_column_name(mysqlParser::New_column_nameContext *context) = 0;

    virtual antlrcpp::Any visitOld_index_name(mysqlParser::Old_index_nameContext *context) = 0;

    virtual antlrcpp::Any visitNew_index_name(mysqlParser::New_index_nameContext *context) = 0;

    virtual antlrcpp::Any visitPartition_number(mysqlParser::Partition_numberContext *context) = 0;
};

} // namespace mysql
