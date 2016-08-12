grammar mysql_alter_table;

import mysql_create_table;

// http://dev.mysql.com/doc/refman/5.7/en/alter-table.html

alter_table:
    ALTER (IGNORE)? TABLE table_name
        (alter_specification_list)?
        (partition_specification)?
    ;

alter_specification:
    table_option_list
    | ADD (COLUMN)? column_name column_definition (first_after)?
    | ADD (COLUMN)? column_definition_list
    | ADD index_definition
    | ALGORITHM (EQUAL)? table_algorithm
    | ALTER (COLUMN)? column_name (SET DEFAULT default_value | DROP DEFAULT)
    | CHANGE (COLUMN)? old_column_name new_column_name column_definition (first_after)?
    | LOCK (EQUAL)? table_lock
    | MODIFY (COLUMN)? column_name column_definition (first_after)?
    | DROP (COLUMN)? column_name
    | DROP PRIMARY KEY
    | DROP (INDEX|KEY) index_name
    | DROP FOREIGN KEY fk_symbol
    | DISABLE KEYS
    | ENABLE KEYS
    | RENAME (TO|AS)? new_table_name
    | RENAME (INDEX|KEY) old_index_name TO new_index_name
    | ORDER BY column_name_list
    | CONVERT TO charset (collation)?
    | (DEFAULT)? charset (collation)?
    | DISCARD TABLESPACE
    | IMPORT TABLESPACE
    | FORCE
    | (WITHOUT|WITH) VALIDATION
    | ADD PARTITION LPAREN partition_definition RPAREN
    | DROP PARTITION partition_name_list
    | DISCARD PARTITION (partition_name_list | ALL) TABLESPACE
    | IMPORT PARTITION (partition_name_list | ALL) TABLESPACE
    | TRUNCATE PARTITION (partition_name_list | ALL)
    | COALESCE PARTITION partition_number
    | REORGANIZE PARTITION partition_name_list INTO partition_definition_list
    | EXCHANGE PARTITION partition_name WITH TABLE table_name ((WITH | WITHOUT) VALIDATION)?
    | ANALYZE PARTITION (partition_name_list | ALL)
    | CHECK PARTITION (partition_name_list | ALL)
    | OPTIMIZE PARTITION (partition_name_list | ALL)
    | REBUILD PARTITION (partition_name_list | ALL)
    | REPAIR PARTITION (partition_name_list | ALL)
    | REMOVE PARTITIONING
    | UPGRADE PARTITIONING
    ;

alter_specification_list: alter_specification (COMMA alter_specification)*;
column_name_list: column_name (COMMA column_name)*;
partition_name_list: partition_name (COMMA partition_name)*;
partition_definition_list: LPAREN partition_definition (COMMA partition_definition)* RPAREN;
column_definition_list: LPAREN column_name column_definition (COMMA column_name column_definition)* RPAREN;

table_algorithm: DEFAULT | INPLACE | COPY;
table_lock: DEFAULT | NONE | SHARED | EXCLUSIVE;
first_after: FIRST | AFTER column_name;

fk_symbol: symbol;
new_table_name: table_name;
old_column_name: column_name;
new_column_name: column_name;
old_index_name: index_name;
new_index_name: index_name;
partition_number: integer_literal;
