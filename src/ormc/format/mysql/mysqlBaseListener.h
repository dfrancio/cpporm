
// Generated from ./mysql.g4 by ANTLR 4.5.3

#pragma once

#include "antlr4-runtime.h"
#include "mysqlListener.h"

namespace mysql
{

/**
 * This class provides an empty implementation of mysqlListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class mysqlBaseListener : public mysqlListener
{
public:
    virtual void enterParse(mysqlParser::ParseContext * /*ctx*/) override
    {
    }
    virtual void exitParse(mysqlParser::ParseContext * /*ctx*/) override
    {
    }

    virtual void enterStatement(mysqlParser::StatementContext * /*ctx*/) override
    {
    }
    virtual void exitStatement(mysqlParser::StatementContext * /*ctx*/) override
    {
    }

    virtual void enterAssignment(mysqlParser::AssignmentContext * /*ctx*/) override
    {
    }
    virtual void exitAssignment(mysqlParser::AssignmentContext * /*ctx*/) override
    {
    }

    virtual void enterDrop_table(mysqlParser::Drop_tableContext * /*ctx*/) override
    {
    }
    virtual void exitDrop_table(mysqlParser::Drop_tableContext * /*ctx*/) override
    {
    }

    virtual void enterTable_name_list(mysqlParser::Table_name_listContext * /*ctx*/) override
    {
    }
    virtual void exitTable_name_list(mysqlParser::Table_name_listContext * /*ctx*/) override
    {
    }

    virtual void enterCreate_table(mysqlParser::Create_tableContext * /*ctx*/) override
    {
    }
    virtual void exitCreate_table(mysqlParser::Create_tableContext * /*ctx*/) override
    {
    }

    virtual void enterCreate_definition(mysqlParser::Create_definitionContext * /*ctx*/) override
    {
    }
    virtual void exitCreate_definition(mysqlParser::Create_definitionContext * /*ctx*/) override
    {
    }

    virtual void enterIndex_definition(mysqlParser::Index_definitionContext * /*ctx*/) override
    {
    }
    virtual void exitIndex_definition(mysqlParser::Index_definitionContext * /*ctx*/) override
    {
    }

    virtual void enterColumn_definition(mysqlParser::Column_definitionContext * /*ctx*/) override
    {
    }
    virtual void exitColumn_definition(mysqlParser::Column_definitionContext * /*ctx*/) override
    {
    }

    virtual void enterColumn_options(mysqlParser::Column_optionsContext * /*ctx*/) override
    {
    }
    virtual void exitColumn_options(mysqlParser::Column_optionsContext * /*ctx*/) override
    {
    }

    virtual void enterGenerated_column_options(
        mysqlParser::Generated_column_optionsContext * /*ctx*/) override
    {
    }
    virtual void exitGenerated_column_options(
        mysqlParser::Generated_column_optionsContext * /*ctx*/) override
    {
    }

    virtual void enterData_type(mysqlParser::Data_typeContext * /*ctx*/) override
    {
    }
    virtual void exitData_type(mysqlParser::Data_typeContext * /*ctx*/) override
    {
    }

    virtual void enterTable_option(mysqlParser::Table_optionContext * /*ctx*/) override
    {
    }
    virtual void exitTable_option(mysqlParser::Table_optionContext * /*ctx*/) override
    {
    }

    virtual void enterPartition_specification(
        mysqlParser::Partition_specificationContext * /*ctx*/) override
    {
    }
    virtual void exitPartition_specification(
        mysqlParser::Partition_specificationContext * /*ctx*/) override
    {
    }

    virtual void enterPartition_definition_list(
        mysqlParser::Partition_definition_listContext * /*ctx*/) override
    {
    }
    virtual void exitPartition_definition_list(
        mysqlParser::Partition_definition_listContext * /*ctx*/) override
    {
    }

    virtual void enterPartition_by(mysqlParser::Partition_byContext * /*ctx*/) override
    {
    }
    virtual void exitPartition_by(mysqlParser::Partition_byContext * /*ctx*/) override
    {
    }

    virtual void enterSubpartition_by(mysqlParser::Subpartition_byContext * /*ctx*/) override
    {
    }
    virtual void exitSubpartition_by(mysqlParser::Subpartition_byContext * /*ctx*/) override
    {
    }

    virtual void enterPartition_definition(
        mysqlParser::Partition_definitionContext * /*ctx*/) override
    {
    }
    virtual void exitPartition_definition(
        mysqlParser::Partition_definitionContext * /*ctx*/) override
    {
    }

    virtual void enterSubpartition_definition_list(
        mysqlParser::Subpartition_definition_listContext * /*ctx*/) override
    {
    }
    virtual void exitSubpartition_definition_list(
        mysqlParser::Subpartition_definition_listContext * /*ctx*/) override
    {
    }

    virtual void enterPartition_values(mysqlParser::Partition_valuesContext * /*ctx*/) override
    {
    }
    virtual void exitPartition_values(mysqlParser::Partition_valuesContext * /*ctx*/) override
    {
    }

    virtual void enterSubpartition_definition(
        mysqlParser::Subpartition_definitionContext * /*ctx*/) override
    {
    }
    virtual void exitSubpartition_definition(
        mysqlParser::Subpartition_definitionContext * /*ctx*/) override
    {
    }

    virtual void enterPartition_options(mysqlParser::Partition_optionsContext * /*ctx*/) override
    {
    }
    virtual void exitPartition_options(mysqlParser::Partition_optionsContext * /*ctx*/) override
    {
    }

    virtual void enterIndex_option(mysqlParser::Index_optionContext * /*ctx*/) override
    {
    }
    virtual void exitIndex_option(mysqlParser::Index_optionContext * /*ctx*/) override
    {
    }

    virtual void enterReference_definition(
        mysqlParser::Reference_definitionContext * /*ctx*/) override
    {
    }
    virtual void exitReference_definition(
        mysqlParser::Reference_definitionContext * /*ctx*/) override
    {
    }

    virtual void enterCreate_definition_list(
        mysqlParser::Create_definition_listContext * /*ctx*/) override
    {
    }
    virtual void exitCreate_definition_list(
        mysqlParser::Create_definition_listContext * /*ctx*/) override
    {
    }

    virtual void enterTable_option_list(mysqlParser::Table_option_listContext * /*ctx*/) override
    {
    }
    virtual void exitTable_option_list(mysqlParser::Table_option_listContext * /*ctx*/) override
    {
    }

    virtual void enterIndex_option_list(mysqlParser::Index_option_listContext * /*ctx*/) override
    {
    }
    virtual void exitIndex_option_list(mysqlParser::Index_option_listContext * /*ctx*/) override
    {
    }

    virtual void enterIndex_column_list(mysqlParser::Index_column_listContext * /*ctx*/) override
    {
    }
    virtual void exitIndex_column_list(mysqlParser::Index_column_listContext * /*ctx*/) override
    {
    }

    virtual void enterLess_than_value_list(
        mysqlParser::Less_than_value_listContext * /*ctx*/) override
    {
    }
    virtual void exitLess_than_value_list(
        mysqlParser::Less_than_value_listContext * /*ctx*/) override
    {
    }

    virtual void enterIn_value_list(mysqlParser::In_value_listContext * /*ctx*/) override
    {
    }
    virtual void exitIn_value_list(mysqlParser::In_value_listContext * /*ctx*/) override
    {
    }

    virtual void enterEnum_value_list(mysqlParser::Enum_value_listContext * /*ctx*/) override
    {
    }
    virtual void exitEnum_value_list(mysqlParser::Enum_value_listContext * /*ctx*/) override
    {
    }

    virtual void enterKey_column_list(mysqlParser::Key_column_listContext * /*ctx*/) override
    {
    }
    virtual void exitKey_column_list(mysqlParser::Key_column_listContext * /*ctx*/) override
    {
    }

    virtual void enterRange_column_list(mysqlParser::Range_column_listContext * /*ctx*/) override
    {
    }
    virtual void exitRange_column_list(mysqlParser::Range_column_listContext * /*ctx*/) override
    {
    }

    virtual void enterList_column_list(mysqlParser::List_column_listContext * /*ctx*/) override
    {
    }
    virtual void exitList_column_list(mysqlParser::List_column_listContext * /*ctx*/) override
    {
    }

    virtual void enterTable_union_list(mysqlParser::Table_union_listContext * /*ctx*/) override
    {
    }
    virtual void exitTable_union_list(mysqlParser::Table_union_listContext * /*ctx*/) override
    {
    }

    virtual void enterConstraint(mysqlParser::ConstraintContext * /*ctx*/) override
    {
    }
    virtual void exitConstraint(mysqlParser::ConstraintContext * /*ctx*/) override
    {
    }

    virtual void enterCharset(mysqlParser::CharsetContext * /*ctx*/) override
    {
    }
    virtual void exitCharset(mysqlParser::CharsetContext * /*ctx*/) override
    {
    }

    virtual void enterCollation(mysqlParser::CollationContext * /*ctx*/) override
    {
    }
    virtual void exitCollation(mysqlParser::CollationContext * /*ctx*/) override
    {
    }

    virtual void enterIndex_structure(mysqlParser::Index_structureContext * /*ctx*/) override
    {
    }
    virtual void exitIndex_structure(mysqlParser::Index_structureContext * /*ctx*/) override
    {
    }

    virtual void enterIndex_column(mysqlParser::Index_columnContext * /*ctx*/) override
    {
    }
    virtual void exitIndex_column(mysqlParser::Index_columnContext * /*ctx*/) override
    {
    }

    virtual void enterFsp(mysqlParser::FspContext * /*ctx*/) override
    {
    }
    virtual void exitFsp(mysqlParser::FspContext * /*ctx*/) override
    {
    }

    virtual void enterLength(mysqlParser::LengthContext * /*ctx*/) override
    {
    }
    virtual void exitLength(mysqlParser::LengthContext * /*ctx*/) override
    {
    }

    virtual void enterDecimals(mysqlParser::DecimalsContext * /*ctx*/) override
    {
    }
    virtual void exitDecimals(mysqlParser::DecimalsContext * /*ctx*/) override
    {
    }

    virtual void enterPartition_count(mysqlParser::Partition_countContext * /*ctx*/) override
    {
    }
    virtual void exitPartition_count(mysqlParser::Partition_countContext * /*ctx*/) override
    {
    }

    virtual void enterSubpartition_count(mysqlParser::Subpartition_countContext * /*ctx*/) override
    {
    }
    virtual void exitSubpartition_count(mysqlParser::Subpartition_countContext * /*ctx*/) override
    {
    }

    virtual void enterAuto_increment(mysqlParser::Auto_incrementContext * /*ctx*/) override
    {
    }
    virtual void exitAuto_increment(mysqlParser::Auto_incrementContext * /*ctx*/) override
    {
    }

    virtual void enterAvg_row_length(mysqlParser::Avg_row_lengthContext * /*ctx*/) override
    {
    }
    virtual void exitAvg_row_length(mysqlParser::Avg_row_lengthContext * /*ctx*/) override
    {
    }

    virtual void enterKey_block_size(mysqlParser::Key_block_sizeContext * /*ctx*/) override
    {
    }
    virtual void exitKey_block_size(mysqlParser::Key_block_sizeContext * /*ctx*/) override
    {
    }

    virtual void enterMax_number_of_rows(mysqlParser::Max_number_of_rowsContext * /*ctx*/) override
    {
    }
    virtual void exitMax_number_of_rows(mysqlParser::Max_number_of_rowsContext * /*ctx*/) override
    {
    }

    virtual void enterMin_number_of_rows(mysqlParser::Min_number_of_rowsContext * /*ctx*/) override
    {
    }
    virtual void exitMin_number_of_rows(mysqlParser::Min_number_of_rowsContext * /*ctx*/) override
    {
    }

    virtual void enterStats_sample_pages(mysqlParser::Stats_sample_pagesContext * /*ctx*/) override
    {
    }
    virtual void exitStats_sample_pages(mysqlParser::Stats_sample_pagesContext * /*ctx*/) override
    {
    }

    virtual void enterChecksum(mysqlParser::ChecksumContext * /*ctx*/) override
    {
    }
    virtual void exitChecksum(mysqlParser::ChecksumContext * /*ctx*/) override
    {
    }

    virtual void enterCompression(mysqlParser::CompressionContext * /*ctx*/) override
    {
    }
    virtual void exitCompression(mysqlParser::CompressionContext * /*ctx*/) override
    {
    }

    virtual void enterDelay_key_write(mysqlParser::Delay_key_writeContext * /*ctx*/) override
    {
    }
    virtual void exitDelay_key_write(mysqlParser::Delay_key_writeContext * /*ctx*/) override
    {
    }

    virtual void enterEncryption(mysqlParser::EncryptionContext * /*ctx*/) override
    {
    }
    virtual void exitEncryption(mysqlParser::EncryptionContext * /*ctx*/) override
    {
    }

    virtual void enterInsert_method(mysqlParser::Insert_methodContext * /*ctx*/) override
    {
    }
    virtual void exitInsert_method(mysqlParser::Insert_methodContext * /*ctx*/) override
    {
    }

    virtual void enterPack_keys(mysqlParser::Pack_keysContext * /*ctx*/) override
    {
    }
    virtual void exitPack_keys(mysqlParser::Pack_keysContext * /*ctx*/) override
    {
    }

    virtual void enterRow_format(mysqlParser::Row_formatContext * /*ctx*/) override
    {
    }
    virtual void exitRow_format(mysqlParser::Row_formatContext * /*ctx*/) override
    {
    }

    virtual void enterStats_auto_recalc(mysqlParser::Stats_auto_recalcContext * /*ctx*/) override
    {
    }
    virtual void exitStats_auto_recalc(mysqlParser::Stats_auto_recalcContext * /*ctx*/) override
    {
    }

    virtual void enterStats_persistent(mysqlParser::Stats_persistentContext * /*ctx*/) override
    {
    }
    virtual void exitStats_persistent(mysqlParser::Stats_persistentContext * /*ctx*/) override
    {
    }

    virtual void enterKey_algorithm(mysqlParser::Key_algorithmContext * /*ctx*/) override
    {
    }
    virtual void exitKey_algorithm(mysqlParser::Key_algorithmContext * /*ctx*/) override
    {
    }

    virtual void enterMatch_option(mysqlParser::Match_optionContext * /*ctx*/) override
    {
    }
    virtual void exitMatch_option(mysqlParser::Match_optionContext * /*ctx*/) override
    {
    }

    virtual void enterOn_delete_option(mysqlParser::On_delete_optionContext * /*ctx*/) override
    {
    }
    virtual void exitOn_delete_option(mysqlParser::On_delete_optionContext * /*ctx*/) override
    {
    }

    virtual void enterOn_update_option(mysqlParser::On_update_optionContext * /*ctx*/) override
    {
    }
    virtual void exitOn_update_option(mysqlParser::On_update_optionContext * /*ctx*/) override
    {
    }

    virtual void enterColumn_format(mysqlParser::Column_formatContext * /*ctx*/) override
    {
    }
    virtual void exitColumn_format(mysqlParser::Column_formatContext * /*ctx*/) override
    {
    }

    virtual void enterColumn_storage(mysqlParser::Column_storageContext * /*ctx*/) override
    {
    }
    virtual void exitColumn_storage(mysqlParser::Column_storageContext * /*ctx*/) override
    {
    }

    virtual void enterInteger_type(mysqlParser::Integer_typeContext * /*ctx*/) override
    {
    }
    virtual void exitInteger_type(mysqlParser::Integer_typeContext * /*ctx*/) override
    {
    }

    virtual void enterReal_type(mysqlParser::Real_typeContext * /*ctx*/) override
    {
    }
    virtual void exitReal_type(mysqlParser::Real_typeContext * /*ctx*/) override
    {
    }

    virtual void enterText_type(mysqlParser::Text_typeContext * /*ctx*/) override
    {
    }
    virtual void exitText_type(mysqlParser::Text_typeContext * /*ctx*/) override
    {
    }

    virtual void enterBlob_type(mysqlParser::Blob_typeContext * /*ctx*/) override
    {
    }
    virtual void exitBlob_type(mysqlParser::Blob_typeContext * /*ctx*/) override
    {
    }

    virtual void enterSpatial_type(mysqlParser::Spatial_typeContext * /*ctx*/) override
    {
    }
    virtual void exitSpatial_type(mysqlParser::Spatial_typeContext * /*ctx*/) override
    {
    }

    virtual void enterEnum_type(mysqlParser::Enum_typeContext * /*ctx*/) override
    {
    }
    virtual void exitEnum_type(mysqlParser::Enum_typeContext * /*ctx*/) override
    {
    }

    virtual void enterBinary_type(mysqlParser::Binary_typeContext * /*ctx*/) override
    {
    }
    virtual void exitBinary_type(mysqlParser::Binary_typeContext * /*ctx*/) override
    {
    }

    virtual void enterChar_type(mysqlParser::Char_typeContext * /*ctx*/) override
    {
    }
    virtual void exitChar_type(mysqlParser::Char_typeContext * /*ctx*/) override
    {
    }

    virtual void enterDatetime_type(mysqlParser::Datetime_typeContext * /*ctx*/) override
    {
    }
    virtual void exitDatetime_type(mysqlParser::Datetime_typeContext * /*ctx*/) override
    {
    }

    virtual void enterOn_update_set(mysqlParser::On_update_setContext * /*ctx*/) override
    {
    }
    virtual void exitOn_update_set(mysqlParser::On_update_setContext * /*ctx*/) override
    {
    }

    virtual void enterDefault_value(mysqlParser::Default_valueContext * /*ctx*/) override
    {
    }
    virtual void exitDefault_value(mysqlParser::Default_valueContext * /*ctx*/) override
    {
    }

    virtual void enterComment(mysqlParser::CommentContext * /*ctx*/) override
    {
    }
    virtual void exitComment(mysqlParser::CommentContext * /*ctx*/) override
    {
    }

    virtual void enterConnection(mysqlParser::ConnectionContext * /*ctx*/) override
    {
    }
    virtual void exitConnection(mysqlParser::ConnectionContext * /*ctx*/) override
    {
    }

    virtual void enterPassword(mysqlParser::PasswordContext * /*ctx*/) override
    {
    }
    virtual void exitPassword(mysqlParser::PasswordContext * /*ctx*/) override
    {
    }

    virtual void enterData_directory(mysqlParser::Data_directoryContext * /*ctx*/) override
    {
    }
    virtual void exitData_directory(mysqlParser::Data_directoryContext * /*ctx*/) override
    {
    }

    virtual void enterIndex_directory(mysqlParser::Index_directoryContext * /*ctx*/) override
    {
    }
    virtual void exitIndex_directory(mysqlParser::Index_directoryContext * /*ctx*/) override
    {
    }

    virtual void enterAs_expression(mysqlParser::As_expressionContext * /*ctx*/) override
    {
    }
    virtual void exitAs_expression(mysqlParser::As_expressionContext * /*ctx*/) override
    {
    }

    virtual void enterQuery_expression(mysqlParser::Query_expressionContext * /*ctx*/) override
    {
    }
    virtual void exitQuery_expression(mysqlParser::Query_expressionContext * /*ctx*/) override
    {
    }

    virtual void enterCheck_expression(mysqlParser::Check_expressionContext * /*ctx*/) override
    {
    }
    virtual void exitCheck_expression(mysqlParser::Check_expressionContext * /*ctx*/) override
    {
    }

    virtual void enterHash_expression(mysqlParser::Hash_expressionContext * /*ctx*/) override
    {
    }
    virtual void exitHash_expression(mysqlParser::Hash_expressionContext * /*ctx*/) override
    {
    }

    virtual void enterRange_expression(mysqlParser::Range_expressionContext * /*ctx*/) override
    {
    }
    virtual void exitRange_expression(mysqlParser::Range_expressionContext * /*ctx*/) override
    {
    }

    virtual void enterList_expression(mysqlParser::List_expressionContext * /*ctx*/) override
    {
    }
    virtual void exitList_expression(mysqlParser::List_expressionContext * /*ctx*/) override
    {
    }

    virtual void enterLess_than_expression(
        mysqlParser::Less_than_expressionContext * /*ctx*/) override
    {
    }
    virtual void exitLess_than_expression(
        mysqlParser::Less_than_expressionContext * /*ctx*/) override
    {
    }

    virtual void enterExpression(mysqlParser::ExpressionContext * /*ctx*/) override
    {
    }
    virtual void exitExpression(mysqlParser::ExpressionContext * /*ctx*/) override
    {
    }

    virtual void enterSymbol(mysqlParser::SymbolContext * /*ctx*/) override
    {
    }
    virtual void exitSymbol(mysqlParser::SymbolContext * /*ctx*/) override
    {
    }

    virtual void enterEngine_name(mysqlParser::Engine_nameContext * /*ctx*/) override
    {
    }
    virtual void exitEngine_name(mysqlParser::Engine_nameContext * /*ctx*/) override
    {
    }

    virtual void enterOld_table_name(mysqlParser::Old_table_nameContext * /*ctx*/) override
    {
    }
    virtual void exitOld_table_name(mysqlParser::Old_table_nameContext * /*ctx*/) override
    {
    }

    virtual void enterColumn_name(mysqlParser::Column_nameContext * /*ctx*/) override
    {
    }
    virtual void exitColumn_name(mysqlParser::Column_nameContext * /*ctx*/) override
    {
    }

    virtual void enterIndex_name(mysqlParser::Index_nameContext * /*ctx*/) override
    {
    }
    virtual void exitIndex_name(mysqlParser::Index_nameContext * /*ctx*/) override
    {
    }

    virtual void enterTablespace_name(mysqlParser::Tablespace_nameContext * /*ctx*/) override
    {
    }
    virtual void exitTablespace_name(mysqlParser::Tablespace_nameContext * /*ctx*/) override
    {
    }

    virtual void enterTable_name(mysqlParser::Table_nameContext * /*ctx*/) override
    {
    }
    virtual void exitTable_name(mysqlParser::Table_nameContext * /*ctx*/) override
    {
    }

    virtual void enterDatabase_name(mysqlParser::Database_nameContext * /*ctx*/) override
    {
    }
    virtual void exitDatabase_name(mysqlParser::Database_nameContext * /*ctx*/) override
    {
    }

    virtual void enterParser_name(mysqlParser::Parser_nameContext * /*ctx*/) override
    {
    }
    virtual void exitParser_name(mysqlParser::Parser_nameContext * /*ctx*/) override
    {
    }

    virtual void enterCharset_name(mysqlParser::Charset_nameContext * /*ctx*/) override
    {
    }
    virtual void exitCharset_name(mysqlParser::Charset_nameContext * /*ctx*/) override
    {
    }

    virtual void enterCollation_name(mysqlParser::Collation_nameContext * /*ctx*/) override
    {
    }
    virtual void exitCollation_name(mysqlParser::Collation_nameContext * /*ctx*/) override
    {
    }

    virtual void enterPartition_name(mysqlParser::Partition_nameContext * /*ctx*/) override
    {
    }
    virtual void exitPartition_name(mysqlParser::Partition_nameContext * /*ctx*/) override
    {
    }

    virtual void enterLogical_name(mysqlParser::Logical_nameContext * /*ctx*/) override
    {
    }
    virtual void exitLogical_name(mysqlParser::Logical_nameContext * /*ctx*/) override
    {
    }

    virtual void enterLiteral(mysqlParser::LiteralContext * /*ctx*/) override
    {
    }
    virtual void exitLiteral(mysqlParser::LiteralContext * /*ctx*/) override
    {
    }

    virtual void enterIdentifier(mysqlParser::IdentifierContext * /*ctx*/) override
    {
    }
    virtual void exitIdentifier(mysqlParser::IdentifierContext * /*ctx*/) override
    {
    }

    virtual void enterBool_literal(mysqlParser::Bool_literalContext * /*ctx*/) override
    {
    }
    virtual void exitBool_literal(mysqlParser::Bool_literalContext * /*ctx*/) override
    {
    }

    virtual void enterFloat_literal(mysqlParser::Float_literalContext * /*ctx*/) override
    {
    }
    virtual void exitFloat_literal(mysqlParser::Float_literalContext * /*ctx*/) override
    {
    }

    virtual void enterInteger_literal(mysqlParser::Integer_literalContext * /*ctx*/) override
    {
    }
    virtual void exitInteger_literal(mysqlParser::Integer_literalContext * /*ctx*/) override
    {
    }

    virtual void enterString_literal(mysqlParser::String_literalContext * /*ctx*/) override
    {
    }
    virtual void exitString_literal(mysqlParser::String_literalContext * /*ctx*/) override
    {
    }

    virtual void enterDatetime_literal(mysqlParser::Datetime_literalContext * /*ctx*/) override
    {
    }
    virtual void exitDatetime_literal(mysqlParser::Datetime_literalContext * /*ctx*/) override
    {
    }

    virtual void enterAlter_table(mysqlParser::Alter_tableContext * /*ctx*/) override
    {
    }
    virtual void exitAlter_table(mysqlParser::Alter_tableContext * /*ctx*/) override
    {
    }

    virtual void enterAlter_specification(
        mysqlParser::Alter_specificationContext * /*ctx*/) override
    {
    }
    virtual void exitAlter_specification(mysqlParser::Alter_specificationContext * /*ctx*/) override
    {
    }

    virtual void enterAlter_specification_list(
        mysqlParser::Alter_specification_listContext * /*ctx*/) override
    {
    }
    virtual void exitAlter_specification_list(
        mysqlParser::Alter_specification_listContext * /*ctx*/) override
    {
    }

    virtual void enterColumn_name_list(mysqlParser::Column_name_listContext * /*ctx*/) override
    {
    }
    virtual void exitColumn_name_list(mysqlParser::Column_name_listContext * /*ctx*/) override
    {
    }

    virtual void enterPartition_name_list(
        mysqlParser::Partition_name_listContext * /*ctx*/) override
    {
    }
    virtual void exitPartition_name_list(mysqlParser::Partition_name_listContext * /*ctx*/) override
    {
    }

    virtual void enterColumn_definition_list(
        mysqlParser::Column_definition_listContext * /*ctx*/) override
    {
    }
    virtual void exitColumn_definition_list(
        mysqlParser::Column_definition_listContext * /*ctx*/) override
    {
    }

    virtual void enterTable_algorithm(mysqlParser::Table_algorithmContext * /*ctx*/) override
    {
    }
    virtual void exitTable_algorithm(mysqlParser::Table_algorithmContext * /*ctx*/) override
    {
    }

    virtual void enterTable_lock(mysqlParser::Table_lockContext * /*ctx*/) override
    {
    }
    virtual void exitTable_lock(mysqlParser::Table_lockContext * /*ctx*/) override
    {
    }

    virtual void enterFirst_after(mysqlParser::First_afterContext * /*ctx*/) override
    {
    }
    virtual void exitFirst_after(mysqlParser::First_afterContext * /*ctx*/) override
    {
    }

    virtual void enterFk_symbol(mysqlParser::Fk_symbolContext * /*ctx*/) override
    {
    }
    virtual void exitFk_symbol(mysqlParser::Fk_symbolContext * /*ctx*/) override
    {
    }

    virtual void enterNew_table_name(mysqlParser::New_table_nameContext * /*ctx*/) override
    {
    }
    virtual void exitNew_table_name(mysqlParser::New_table_nameContext * /*ctx*/) override
    {
    }

    virtual void enterOld_column_name(mysqlParser::Old_column_nameContext * /*ctx*/) override
    {
    }
    virtual void exitOld_column_name(mysqlParser::Old_column_nameContext * /*ctx*/) override
    {
    }

    virtual void enterNew_column_name(mysqlParser::New_column_nameContext * /*ctx*/) override
    {
    }
    virtual void exitNew_column_name(mysqlParser::New_column_nameContext * /*ctx*/) override
    {
    }

    virtual void enterOld_index_name(mysqlParser::Old_index_nameContext * /*ctx*/) override
    {
    }
    virtual void exitOld_index_name(mysqlParser::Old_index_nameContext * /*ctx*/) override
    {
    }

    virtual void enterNew_index_name(mysqlParser::New_index_nameContext * /*ctx*/) override
    {
    }
    virtual void exitNew_index_name(mysqlParser::New_index_nameContext * /*ctx*/) override
    {
    }

    virtual void enterPartition_number(mysqlParser::Partition_numberContext * /*ctx*/) override
    {
    }
    virtual void exitPartition_number(mysqlParser::Partition_numberContext * /*ctx*/) override
    {
    }

    virtual void enterEveryRule(ParserRuleContext * /*ctx*/) override
    {
    }
    virtual void exitEveryRule(ParserRuleContext * /*ctx*/) override
    {
    }
    virtual void visitTerminal(tree::TerminalNode * /*node*/) override
    {
    }
    virtual void visitErrorNode(tree::ErrorNode * /*node*/) override
    {
    }
};

} // namespace mysql
