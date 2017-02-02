
// Generated from grammars/mysql/mysql.g4 by ANTLR 4.6

#pragma once

#include "antlr4-runtime.h"
#include "mysqlParser.h"

namespace mysql
{

/**
 * This interface defines an abstract listener for a parse tree produced by mysqlParser.
 */
class mysqlListener : public antlr4::tree::ParseTreeListener
{
public:
    virtual void enterParse(mysqlParser::ParseContext *ctx) = 0;
    virtual void exitParse(mysqlParser::ParseContext *ctx) = 0;

    virtual void enterStatement(mysqlParser::StatementContext *ctx) = 0;
    virtual void exitStatement(mysqlParser::StatementContext *ctx) = 0;

    virtual void enterAssignment(mysqlParser::AssignmentContext *ctx) = 0;
    virtual void exitAssignment(mysqlParser::AssignmentContext *ctx) = 0;

    virtual void enterDrop_table(mysqlParser::Drop_tableContext *ctx) = 0;
    virtual void exitDrop_table(mysqlParser::Drop_tableContext *ctx) = 0;

    virtual void enterTable_name_list(mysqlParser::Table_name_listContext *ctx) = 0;
    virtual void exitTable_name_list(mysqlParser::Table_name_listContext *ctx) = 0;

    virtual void enterCreate_table(mysqlParser::Create_tableContext *ctx) = 0;
    virtual void exitCreate_table(mysqlParser::Create_tableContext *ctx) = 0;

    virtual void enterCreate_definition(mysqlParser::Create_definitionContext *ctx) = 0;
    virtual void exitCreate_definition(mysqlParser::Create_definitionContext *ctx) = 0;

    virtual void enterIndex_definition(mysqlParser::Index_definitionContext *ctx) = 0;
    virtual void exitIndex_definition(mysqlParser::Index_definitionContext *ctx) = 0;

    virtual void enterColumn_definition(mysqlParser::Column_definitionContext *ctx) = 0;
    virtual void exitColumn_definition(mysqlParser::Column_definitionContext *ctx) = 0;

    virtual void enterColumn_options(mysqlParser::Column_optionsContext *ctx) = 0;
    virtual void exitColumn_options(mysqlParser::Column_optionsContext *ctx) = 0;

    virtual void enterGenerated_column_options(mysqlParser::Generated_column_optionsContext *ctx)
        = 0;
    virtual void exitGenerated_column_options(mysqlParser::Generated_column_optionsContext *ctx)
        = 0;

    virtual void enterData_type(mysqlParser::Data_typeContext *ctx) = 0;
    virtual void exitData_type(mysqlParser::Data_typeContext *ctx) = 0;

    virtual void enterTable_option(mysqlParser::Table_optionContext *ctx) = 0;
    virtual void exitTable_option(mysqlParser::Table_optionContext *ctx) = 0;

    virtual void enterPartition_specification(mysqlParser::Partition_specificationContext *ctx) = 0;
    virtual void exitPartition_specification(mysqlParser::Partition_specificationContext *ctx) = 0;

    virtual void enterPartition_definition_list(mysqlParser::Partition_definition_listContext *ctx)
        = 0;
    virtual void exitPartition_definition_list(mysqlParser::Partition_definition_listContext *ctx)
        = 0;

    virtual void enterPartition_by(mysqlParser::Partition_byContext *ctx) = 0;
    virtual void exitPartition_by(mysqlParser::Partition_byContext *ctx) = 0;

    virtual void enterSubpartition_by(mysqlParser::Subpartition_byContext *ctx) = 0;
    virtual void exitSubpartition_by(mysqlParser::Subpartition_byContext *ctx) = 0;

    virtual void enterPartition_definition(mysqlParser::Partition_definitionContext *ctx) = 0;
    virtual void exitPartition_definition(mysqlParser::Partition_definitionContext *ctx) = 0;

    virtual void enterSubpartition_definition_list(
        mysqlParser::Subpartition_definition_listContext *ctx)
        = 0;
    virtual void exitSubpartition_definition_list(
        mysqlParser::Subpartition_definition_listContext *ctx)
        = 0;

    virtual void enterPartition_values(mysqlParser::Partition_valuesContext *ctx) = 0;
    virtual void exitPartition_values(mysqlParser::Partition_valuesContext *ctx) = 0;

    virtual void enterSubpartition_definition(mysqlParser::Subpartition_definitionContext *ctx) = 0;
    virtual void exitSubpartition_definition(mysqlParser::Subpartition_definitionContext *ctx) = 0;

    virtual void enterPartition_options(mysqlParser::Partition_optionsContext *ctx) = 0;
    virtual void exitPartition_options(mysqlParser::Partition_optionsContext *ctx) = 0;

    virtual void enterIndex_option(mysqlParser::Index_optionContext *ctx) = 0;
    virtual void exitIndex_option(mysqlParser::Index_optionContext *ctx) = 0;

    virtual void enterReference_definition(mysqlParser::Reference_definitionContext *ctx) = 0;
    virtual void exitReference_definition(mysqlParser::Reference_definitionContext *ctx) = 0;

    virtual void enterCreate_definition_list(mysqlParser::Create_definition_listContext *ctx) = 0;
    virtual void exitCreate_definition_list(mysqlParser::Create_definition_listContext *ctx) = 0;

    virtual void enterTable_option_list(mysqlParser::Table_option_listContext *ctx) = 0;
    virtual void exitTable_option_list(mysqlParser::Table_option_listContext *ctx) = 0;

    virtual void enterIndex_option_list(mysqlParser::Index_option_listContext *ctx) = 0;
    virtual void exitIndex_option_list(mysqlParser::Index_option_listContext *ctx) = 0;

    virtual void enterIndex_column_list(mysqlParser::Index_column_listContext *ctx) = 0;
    virtual void exitIndex_column_list(mysqlParser::Index_column_listContext *ctx) = 0;

    virtual void enterLess_than_value_list(mysqlParser::Less_than_value_listContext *ctx) = 0;
    virtual void exitLess_than_value_list(mysqlParser::Less_than_value_listContext *ctx) = 0;

    virtual void enterIn_value_list(mysqlParser::In_value_listContext *ctx) = 0;
    virtual void exitIn_value_list(mysqlParser::In_value_listContext *ctx) = 0;

    virtual void enterEnum_value_list(mysqlParser::Enum_value_listContext *ctx) = 0;
    virtual void exitEnum_value_list(mysqlParser::Enum_value_listContext *ctx) = 0;

    virtual void enterKey_column_list(mysqlParser::Key_column_listContext *ctx) = 0;
    virtual void exitKey_column_list(mysqlParser::Key_column_listContext *ctx) = 0;

    virtual void enterRange_column_list(mysqlParser::Range_column_listContext *ctx) = 0;
    virtual void exitRange_column_list(mysqlParser::Range_column_listContext *ctx) = 0;

    virtual void enterList_column_list(mysqlParser::List_column_listContext *ctx) = 0;
    virtual void exitList_column_list(mysqlParser::List_column_listContext *ctx) = 0;

    virtual void enterTable_union_list(mysqlParser::Table_union_listContext *ctx) = 0;
    virtual void exitTable_union_list(mysqlParser::Table_union_listContext *ctx) = 0;

    virtual void enterConstraint(mysqlParser::ConstraintContext *ctx) = 0;
    virtual void exitConstraint(mysqlParser::ConstraintContext *ctx) = 0;

    virtual void enterCharset(mysqlParser::CharsetContext *ctx) = 0;
    virtual void exitCharset(mysqlParser::CharsetContext *ctx) = 0;

    virtual void enterCollation(mysqlParser::CollationContext *ctx) = 0;
    virtual void exitCollation(mysqlParser::CollationContext *ctx) = 0;

    virtual void enterIndex_structure(mysqlParser::Index_structureContext *ctx) = 0;
    virtual void exitIndex_structure(mysqlParser::Index_structureContext *ctx) = 0;

    virtual void enterIndex_column(mysqlParser::Index_columnContext *ctx) = 0;
    virtual void exitIndex_column(mysqlParser::Index_columnContext *ctx) = 0;

    virtual void enterFsp(mysqlParser::FspContext *ctx) = 0;
    virtual void exitFsp(mysqlParser::FspContext *ctx) = 0;

    virtual void enterLength(mysqlParser::LengthContext *ctx) = 0;
    virtual void exitLength(mysqlParser::LengthContext *ctx) = 0;

    virtual void enterDecimals(mysqlParser::DecimalsContext *ctx) = 0;
    virtual void exitDecimals(mysqlParser::DecimalsContext *ctx) = 0;

    virtual void enterPartition_count(mysqlParser::Partition_countContext *ctx) = 0;
    virtual void exitPartition_count(mysqlParser::Partition_countContext *ctx) = 0;

    virtual void enterSubpartition_count(mysqlParser::Subpartition_countContext *ctx) = 0;
    virtual void exitSubpartition_count(mysqlParser::Subpartition_countContext *ctx) = 0;

    virtual void enterAuto_increment(mysqlParser::Auto_incrementContext *ctx) = 0;
    virtual void exitAuto_increment(mysqlParser::Auto_incrementContext *ctx) = 0;

    virtual void enterAvg_row_length(mysqlParser::Avg_row_lengthContext *ctx) = 0;
    virtual void exitAvg_row_length(mysqlParser::Avg_row_lengthContext *ctx) = 0;

    virtual void enterKey_block_size(mysqlParser::Key_block_sizeContext *ctx) = 0;
    virtual void exitKey_block_size(mysqlParser::Key_block_sizeContext *ctx) = 0;

    virtual void enterMax_number_of_rows(mysqlParser::Max_number_of_rowsContext *ctx) = 0;
    virtual void exitMax_number_of_rows(mysqlParser::Max_number_of_rowsContext *ctx) = 0;

    virtual void enterMin_number_of_rows(mysqlParser::Min_number_of_rowsContext *ctx) = 0;
    virtual void exitMin_number_of_rows(mysqlParser::Min_number_of_rowsContext *ctx) = 0;

    virtual void enterStats_sample_pages(mysqlParser::Stats_sample_pagesContext *ctx) = 0;
    virtual void exitStats_sample_pages(mysqlParser::Stats_sample_pagesContext *ctx) = 0;

    virtual void enterChecksum(mysqlParser::ChecksumContext *ctx) = 0;
    virtual void exitChecksum(mysqlParser::ChecksumContext *ctx) = 0;

    virtual void enterCompression(mysqlParser::CompressionContext *ctx) = 0;
    virtual void exitCompression(mysqlParser::CompressionContext *ctx) = 0;

    virtual void enterDelay_key_write(mysqlParser::Delay_key_writeContext *ctx) = 0;
    virtual void exitDelay_key_write(mysqlParser::Delay_key_writeContext *ctx) = 0;

    virtual void enterEncryption(mysqlParser::EncryptionContext *ctx) = 0;
    virtual void exitEncryption(mysqlParser::EncryptionContext *ctx) = 0;

    virtual void enterInsert_method(mysqlParser::Insert_methodContext *ctx) = 0;
    virtual void exitInsert_method(mysqlParser::Insert_methodContext *ctx) = 0;

    virtual void enterPack_keys(mysqlParser::Pack_keysContext *ctx) = 0;
    virtual void exitPack_keys(mysqlParser::Pack_keysContext *ctx) = 0;

    virtual void enterRow_format(mysqlParser::Row_formatContext *ctx) = 0;
    virtual void exitRow_format(mysqlParser::Row_formatContext *ctx) = 0;

    virtual void enterStats_auto_recalc(mysqlParser::Stats_auto_recalcContext *ctx) = 0;
    virtual void exitStats_auto_recalc(mysqlParser::Stats_auto_recalcContext *ctx) = 0;

    virtual void enterStats_persistent(mysqlParser::Stats_persistentContext *ctx) = 0;
    virtual void exitStats_persistent(mysqlParser::Stats_persistentContext *ctx) = 0;

    virtual void enterKey_algorithm(mysqlParser::Key_algorithmContext *ctx) = 0;
    virtual void exitKey_algorithm(mysqlParser::Key_algorithmContext *ctx) = 0;

    virtual void enterMatch_option(mysqlParser::Match_optionContext *ctx) = 0;
    virtual void exitMatch_option(mysqlParser::Match_optionContext *ctx) = 0;

    virtual void enterOn_delete_option(mysqlParser::On_delete_optionContext *ctx) = 0;
    virtual void exitOn_delete_option(mysqlParser::On_delete_optionContext *ctx) = 0;

    virtual void enterOn_update_option(mysqlParser::On_update_optionContext *ctx) = 0;
    virtual void exitOn_update_option(mysqlParser::On_update_optionContext *ctx) = 0;

    virtual void enterColumn_format(mysqlParser::Column_formatContext *ctx) = 0;
    virtual void exitColumn_format(mysqlParser::Column_formatContext *ctx) = 0;

    virtual void enterColumn_storage(mysqlParser::Column_storageContext *ctx) = 0;
    virtual void exitColumn_storage(mysqlParser::Column_storageContext *ctx) = 0;

    virtual void enterInteger_type(mysqlParser::Integer_typeContext *ctx) = 0;
    virtual void exitInteger_type(mysqlParser::Integer_typeContext *ctx) = 0;

    virtual void enterReal_type(mysqlParser::Real_typeContext *ctx) = 0;
    virtual void exitReal_type(mysqlParser::Real_typeContext *ctx) = 0;

    virtual void enterText_type(mysqlParser::Text_typeContext *ctx) = 0;
    virtual void exitText_type(mysqlParser::Text_typeContext *ctx) = 0;

    virtual void enterBlob_type(mysqlParser::Blob_typeContext *ctx) = 0;
    virtual void exitBlob_type(mysqlParser::Blob_typeContext *ctx) = 0;

    virtual void enterSpatial_type(mysqlParser::Spatial_typeContext *ctx) = 0;
    virtual void exitSpatial_type(mysqlParser::Spatial_typeContext *ctx) = 0;

    virtual void enterEnum_type(mysqlParser::Enum_typeContext *ctx) = 0;
    virtual void exitEnum_type(mysqlParser::Enum_typeContext *ctx) = 0;

    virtual void enterBinary_type(mysqlParser::Binary_typeContext *ctx) = 0;
    virtual void exitBinary_type(mysqlParser::Binary_typeContext *ctx) = 0;

    virtual void enterChar_type(mysqlParser::Char_typeContext *ctx) = 0;
    virtual void exitChar_type(mysqlParser::Char_typeContext *ctx) = 0;

    virtual void enterDatetime_type(mysqlParser::Datetime_typeContext *ctx) = 0;
    virtual void exitDatetime_type(mysqlParser::Datetime_typeContext *ctx) = 0;

    virtual void enterOn_update_set(mysqlParser::On_update_setContext *ctx) = 0;
    virtual void exitOn_update_set(mysqlParser::On_update_setContext *ctx) = 0;

    virtual void enterDefault_value(mysqlParser::Default_valueContext *ctx) = 0;
    virtual void exitDefault_value(mysqlParser::Default_valueContext *ctx) = 0;

    virtual void enterComment(mysqlParser::CommentContext *ctx) = 0;
    virtual void exitComment(mysqlParser::CommentContext *ctx) = 0;

    virtual void enterConnection(mysqlParser::ConnectionContext *ctx) = 0;
    virtual void exitConnection(mysqlParser::ConnectionContext *ctx) = 0;

    virtual void enterPassword(mysqlParser::PasswordContext *ctx) = 0;
    virtual void exitPassword(mysqlParser::PasswordContext *ctx) = 0;

    virtual void enterData_directory(mysqlParser::Data_directoryContext *ctx) = 0;
    virtual void exitData_directory(mysqlParser::Data_directoryContext *ctx) = 0;

    virtual void enterIndex_directory(mysqlParser::Index_directoryContext *ctx) = 0;
    virtual void exitIndex_directory(mysqlParser::Index_directoryContext *ctx) = 0;

    virtual void enterAs_expression(mysqlParser::As_expressionContext *ctx) = 0;
    virtual void exitAs_expression(mysqlParser::As_expressionContext *ctx) = 0;

    virtual void enterQuery_expression(mysqlParser::Query_expressionContext *ctx) = 0;
    virtual void exitQuery_expression(mysqlParser::Query_expressionContext *ctx) = 0;

    virtual void enterCheck_expression(mysqlParser::Check_expressionContext *ctx) = 0;
    virtual void exitCheck_expression(mysqlParser::Check_expressionContext *ctx) = 0;

    virtual void enterHash_expression(mysqlParser::Hash_expressionContext *ctx) = 0;
    virtual void exitHash_expression(mysqlParser::Hash_expressionContext *ctx) = 0;

    virtual void enterRange_expression(mysqlParser::Range_expressionContext *ctx) = 0;
    virtual void exitRange_expression(mysqlParser::Range_expressionContext *ctx) = 0;

    virtual void enterList_expression(mysqlParser::List_expressionContext *ctx) = 0;
    virtual void exitList_expression(mysqlParser::List_expressionContext *ctx) = 0;

    virtual void enterLess_than_expression(mysqlParser::Less_than_expressionContext *ctx) = 0;
    virtual void exitLess_than_expression(mysqlParser::Less_than_expressionContext *ctx) = 0;

    virtual void enterExpression(mysqlParser::ExpressionContext *ctx) = 0;
    virtual void exitExpression(mysqlParser::ExpressionContext *ctx) = 0;

    virtual void enterSymbol(mysqlParser::SymbolContext *ctx) = 0;
    virtual void exitSymbol(mysqlParser::SymbolContext *ctx) = 0;

    virtual void enterEngine_name(mysqlParser::Engine_nameContext *ctx) = 0;
    virtual void exitEngine_name(mysqlParser::Engine_nameContext *ctx) = 0;

    virtual void enterOld_table_name(mysqlParser::Old_table_nameContext *ctx) = 0;
    virtual void exitOld_table_name(mysqlParser::Old_table_nameContext *ctx) = 0;

    virtual void enterColumn_name(mysqlParser::Column_nameContext *ctx) = 0;
    virtual void exitColumn_name(mysqlParser::Column_nameContext *ctx) = 0;

    virtual void enterIndex_name(mysqlParser::Index_nameContext *ctx) = 0;
    virtual void exitIndex_name(mysqlParser::Index_nameContext *ctx) = 0;

    virtual void enterTablespace_name(mysqlParser::Tablespace_nameContext *ctx) = 0;
    virtual void exitTablespace_name(mysqlParser::Tablespace_nameContext *ctx) = 0;

    virtual void enterTable_name(mysqlParser::Table_nameContext *ctx) = 0;
    virtual void exitTable_name(mysqlParser::Table_nameContext *ctx) = 0;

    virtual void enterDatabase_name(mysqlParser::Database_nameContext *ctx) = 0;
    virtual void exitDatabase_name(mysqlParser::Database_nameContext *ctx) = 0;

    virtual void enterParser_name(mysqlParser::Parser_nameContext *ctx) = 0;
    virtual void exitParser_name(mysqlParser::Parser_nameContext *ctx) = 0;

    virtual void enterCharset_name(mysqlParser::Charset_nameContext *ctx) = 0;
    virtual void exitCharset_name(mysqlParser::Charset_nameContext *ctx) = 0;

    virtual void enterCollation_name(mysqlParser::Collation_nameContext *ctx) = 0;
    virtual void exitCollation_name(mysqlParser::Collation_nameContext *ctx) = 0;

    virtual void enterPartition_name(mysqlParser::Partition_nameContext *ctx) = 0;
    virtual void exitPartition_name(mysqlParser::Partition_nameContext *ctx) = 0;

    virtual void enterLogical_name(mysqlParser::Logical_nameContext *ctx) = 0;
    virtual void exitLogical_name(mysqlParser::Logical_nameContext *ctx) = 0;

    virtual void enterLiteral(mysqlParser::LiteralContext *ctx) = 0;
    virtual void exitLiteral(mysqlParser::LiteralContext *ctx) = 0;

    virtual void enterIdentifier(mysqlParser::IdentifierContext *ctx) = 0;
    virtual void exitIdentifier(mysqlParser::IdentifierContext *ctx) = 0;

    virtual void enterBool_literal(mysqlParser::Bool_literalContext *ctx) = 0;
    virtual void exitBool_literal(mysqlParser::Bool_literalContext *ctx) = 0;

    virtual void enterFloat_literal(mysqlParser::Float_literalContext *ctx) = 0;
    virtual void exitFloat_literal(mysqlParser::Float_literalContext *ctx) = 0;

    virtual void enterInteger_literal(mysqlParser::Integer_literalContext *ctx) = 0;
    virtual void exitInteger_literal(mysqlParser::Integer_literalContext *ctx) = 0;

    virtual void enterString_literal(mysqlParser::String_literalContext *ctx) = 0;
    virtual void exitString_literal(mysqlParser::String_literalContext *ctx) = 0;

    virtual void enterDatetime_literal(mysqlParser::Datetime_literalContext *ctx) = 0;
    virtual void exitDatetime_literal(mysqlParser::Datetime_literalContext *ctx) = 0;

    virtual void enterAlter_table(mysqlParser::Alter_tableContext *ctx) = 0;
    virtual void exitAlter_table(mysqlParser::Alter_tableContext *ctx) = 0;

    virtual void enterAlter_specification(mysqlParser::Alter_specificationContext *ctx) = 0;
    virtual void exitAlter_specification(mysqlParser::Alter_specificationContext *ctx) = 0;

    virtual void enterAlter_specification_list(mysqlParser::Alter_specification_listContext *ctx)
        = 0;
    virtual void exitAlter_specification_list(mysqlParser::Alter_specification_listContext *ctx)
        = 0;

    virtual void enterColumn_name_list(mysqlParser::Column_name_listContext *ctx) = 0;
    virtual void exitColumn_name_list(mysqlParser::Column_name_listContext *ctx) = 0;

    virtual void enterPartition_name_list(mysqlParser::Partition_name_listContext *ctx) = 0;
    virtual void exitPartition_name_list(mysqlParser::Partition_name_listContext *ctx) = 0;

    virtual void enterColumn_definition_list(mysqlParser::Column_definition_listContext *ctx) = 0;
    virtual void exitColumn_definition_list(mysqlParser::Column_definition_listContext *ctx) = 0;

    virtual void enterTable_algorithm(mysqlParser::Table_algorithmContext *ctx) = 0;
    virtual void exitTable_algorithm(mysqlParser::Table_algorithmContext *ctx) = 0;

    virtual void enterTable_lock(mysqlParser::Table_lockContext *ctx) = 0;
    virtual void exitTable_lock(mysqlParser::Table_lockContext *ctx) = 0;

    virtual void enterFirst_after(mysqlParser::First_afterContext *ctx) = 0;
    virtual void exitFirst_after(mysqlParser::First_afterContext *ctx) = 0;

    virtual void enterFk_symbol(mysqlParser::Fk_symbolContext *ctx) = 0;
    virtual void exitFk_symbol(mysqlParser::Fk_symbolContext *ctx) = 0;

    virtual void enterNew_table_name(mysqlParser::New_table_nameContext *ctx) = 0;
    virtual void exitNew_table_name(mysqlParser::New_table_nameContext *ctx) = 0;

    virtual void enterOld_column_name(mysqlParser::Old_column_nameContext *ctx) = 0;
    virtual void exitOld_column_name(mysqlParser::Old_column_nameContext *ctx) = 0;

    virtual void enterNew_column_name(mysqlParser::New_column_nameContext *ctx) = 0;
    virtual void exitNew_column_name(mysqlParser::New_column_nameContext *ctx) = 0;

    virtual void enterOld_index_name(mysqlParser::Old_index_nameContext *ctx) = 0;
    virtual void exitOld_index_name(mysqlParser::Old_index_nameContext *ctx) = 0;

    virtual void enterNew_index_name(mysqlParser::New_index_nameContext *ctx) = 0;
    virtual void exitNew_index_name(mysqlParser::New_index_nameContext *ctx) = 0;

    virtual void enterPartition_number(mysqlParser::Partition_numberContext *ctx) = 0;
    virtual void exitPartition_number(mysqlParser::Partition_numberContext *ctx) = 0;
};

} // namespace mysql
