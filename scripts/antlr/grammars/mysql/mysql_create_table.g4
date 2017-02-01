grammar mysql_create_table;

import mysql_literals;

// http://dev.mysql.com/doc/refman/5.7/en/create-table.html

create_table:
    CREATE (TEMPORARY)? TABLE (IF NOT EXISTS)? table_name
        create_definition_list (table_option_list)? (partition_specification)?
    | CREATE (TEMPORARY)? TABLE (IF NOT EXISTS)? table_name
        (LIKE old_table_name | LPAREN LIKE old_table_name RPAREN)
    | CREATE (TEMPORARY)? TABLE (IF NOT EXISTS)? table_name
        (create_definition_list)? (table_option_list)? (partition_specification)?
        (IGNORE | REPLACE)? (AS)? query_expression
    ;

create_definition:
    column_name column_definition
    | index_definition
    | CHECK check_expression
    ;

index_definition:
    (constraint)? PRIMARY KEY (index_structure)? index_column_list index_option_list
    | (INDEX | KEY) (index_name)? (index_structure)? index_column_list index_option_list
    | (constraint)? UNIQUE (INDEX | KEY)? (index_name)? (index_structure)? index_column_list index_option_list
    | (FULLTEXT | SPATIAL) (INDEX | KEY)? (index_name)? index_column_list index_option_list
    | (constraint)? FOREIGN KEY (index_name)? index_column_list reference_definition
    ;

column_definition:
    data_type column_options (reference_definition)?
    | data_type generated_column_options
    ;

column_options:
    (NOT NULL | NULL)?
    (DEFAULT default_value)?
    (AUTO_INCREMENT)?
    (UNIQUE (KEY)? | (PRIMARY)? KEY)?
    (COMMENT comment)?
    (COLUMN_FORMAT column_format)?
    (STORAGE column_storage)?
    (ON UPDATE on_update_set)?
    ;

generated_column_options:
    (GENERATED ALWAYS)?
    AS as_expression
    (VIRTUAL | STORED)?
    (UNIQUE (KEY)?)?
    (COMMENT comment)?
    (NOT NULL | NULL)?
    ((PRIMARY)? KEY)?
    ;

data_type:
    integer_type (LPAREN length RPAREN)? (UNSIGNED)? (ZEROFILL)?
    | real_type (LPAREN length (COMMA decimals)? RPAREN)? (UNSIGNED)? (ZEROFILL)?
    | datetime_type (LPAREN fsp RPAREN)?
    | char_type (LPAREN length RPAREN)? (BINARY)? (charset)? (collation)?
    | binary_type (LPAREN length RPAREN)?
    | blob_type
    | text_type (LPAREN length RPAREN)? (BINARY)? (charset)? (collation)?
    | enum_type enum_value_list (charset)? (collation)?
    | spatial_type
    | JSON
    ;

table_option:
    ENGINE (EQUAL)? engine_name
    | AUTO_INCREMENT (EQUAL)? auto_increment
    | AVG_ROW_LENGTH (EQUAL)? avg_row_length
    | (DEFAULT)? charset
    | CHECKSUM (EQUAL)? checksum
    | (DEFAULT)? collation
    | COMMENT (EQUAL)? comment
    | COMPRESSION (EQUAL)? compression
    | CONNECTION (EQUAL)? connection
    | DATA DIRECTORY (EQUAL)? data_directory
    | DELAY_KEY_WRITE (EQUAL)? delay_key_write
    | ENCRYPTION (EQUAL)? encryption
    | INDEX DIRECTORY (EQUAL)? index_directory
    | INSERT_METHOD (EQUAL)? insert_method
    | KEY_BLOCK_SIZE (EQUAL)? key_block_size
    | MAX_ROWS (EQUAL)? max_number_of_rows
    | MIN_ROWS (EQUAL)? min_number_of_rows
    | PACK_KEYS (EQUAL)? pack_keys
    | PASSWORD (EQUAL)? password
    | ROW_FORMAT (EQUAL)? row_format
    | STATS_AUTO_RECALC (EQUAL)? stats_auto_recalc
    | STATS_PERSISTENT (EQUAL)? stats_persistent
    | STATS_SAMPLE_PAGES (EQUAL)? stats_sample_pages
    | TABLESPACE tablespace_name
    | UNION (EQUAL)? table_union_list
    ;

partition_specification:
    PARTITION BY partition_by (PARTITIONS partition_count)?
        (SUBPARTITION BY subpartition_by (SUBPARTITIONS subpartition_count)?)?
        (partition_definition_list)?
    ;

partition_definition_list:
    LPAREN partition_definition (COMMA partition_definition)* RPAREN
    ;

partition_by:
    (LINEAR)? HASH hash_expression
    | (LINEAR)? KEY (ALGORITHM EQUAL key_algorithm)? key_column_list
    | RANGE(range_expression | COLUMNS range_column_list)
    | LIST(list_expression | COLUMNS list_column_list)
    ;

subpartition_by:
    (LINEAR)? HASH hash_expression
    | (LINEAR)? KEY (ALGORITHM EQUAL key_algorithm)? key_column_list
    ;

partition_definition:
    PARTITION partition_name
        (partition_values)? partition_options
        (subpartition_definition_list)?
    ;

subpartition_definition_list:
    LPAREN subpartition_definition (COMMA subpartition_definition)* RPAREN
    ;

partition_values:
    VALUES
        ( LESS THAN
            ( less_than_expression
            | less_than_value_list
            | MAXVALUE)
        | IN in_value_list)
    ;

subpartition_definition:
    SUBPARTITION logical_name partition_options
    ;

partition_options:
    ((STORAGE)? ENGINE (EQUAL)? engine_name)?
        (COMMENT (EQUAL)? comment)?
        (DATA DIRECTORY (EQUAL)? data_directory)?
        (INDEX DIRECTORY (EQUAL)? index_directory)?
        (MAX_ROWS (EQUAL)? max_number_of_rows)?
        (MIN_ROWS (EQUAL)? min_number_of_rows)?
        (TABLESPACE (EQUAL)? tablespace_name)?
    ;

index_option:
    KEY_BLOCK_SIZE (EQUAL)? key_block_size
    | USING index_structure
    | WITH PARSER parser_name
    | COMMENT comment
    ;

reference_definition:
    REFERENCES table_name index_column_list
        (MATCH match_option)?
        (ON DELETE on_delete_option)?
        (ON UPDATE on_update_option)?
    ;

create_definition_list: LPAREN create_definition (COMMA create_definition)* RPAREN;
table_option_list: table_option ((COMMA)? table_option)*;
index_option_list: (index_option)*;
index_column_list: LPAREN index_column (COMMA index_column)* RPAREN;
less_than_value_list: LPAREN literal (COMMA literal)* RPAREN;
in_value_list: LPAREN literal (COMMA literal)* RPAREN;
enum_value_list: LPAREN literal (COMMA literal)* RPAREN;
key_column_list: LPAREN identifier (COMMA identifier)* RPAREN;
range_column_list: LPAREN identifier (COMMA identifier)* RPAREN;
list_column_list: LPAREN identifier (COMMA identifier)* RPAREN;
table_union_list: LPAREN table_name (COMMA table_name)* RPAREN;

constraint: CONSTRAINT (symbol)?;
charset: (CHARACTER SET | CHARSET) (EQUAL)? charset_name;
collation: COLLATE (EQUAL)? collation_name;
index_structure: BTREE | HASH;
index_column: column_name (LPAREN length RPAREN)? (ASC | DESC)?;

fsp: integer_literal;
length: integer_literal;
decimals: integer_literal;
partition_count: integer_literal;
subpartition_count: integer_literal;
auto_increment: integer_literal;
avg_row_length: integer_literal;
key_block_size: integer_literal;
max_number_of_rows: integer_literal;
min_number_of_rows: integer_literal;
stats_sample_pages: integer_literal;

checksum: integer_literal;
compression: string_literal;
delay_key_write: integer_literal;
encryption: string_literal;
insert_method: NO | FIRST | LAST;
pack_keys: integer_literal | DEFAULT;
row_format: DEFAULT | DYNAMIC | FIXED | COMPRESSED | REDUNDANT | COMPACT;
stats_auto_recalc: DEFAULT | integer_literal;
stats_persistent: DEFAULT | integer_literal;
key_algorithm: integer_literal;
match_option: FULL | PARTIAL | SIMPLE;
on_delete_option: RESTRICT | CASCADE | SET NULL | NO ACTION;
on_update_option: RESTRICT | CASCADE | SET NULL | NO ACTION;
column_format: FIXED | DYNAMIC | DEFAULT;
column_storage: DISK | MEMORY | DEFAULT;
integer_type: TINYINT | SMALLINT | MEDIUMINT | INT | INTEGER | BIGINT;
real_type: REAL | DOUBLE (PRECISION)? | FLOAT | DECIMAL | NUMERIC;
text_type: TINYTEXT | TEXT | MEDIUMTEXT | LONGTEXT;
blob_type: TINYBLOB | BLOB | MEDIUMBLOB | LONGBLOB;
spatial_type: GEOMETRY | POINT | LINESTRING | POLYGON | MULTIPOINT | MULTILINESTRING | MULTIPOLYGON | GEOMETRYCOLLECTION;
enum_type: ENUM | SET;
binary_type: BIT | BINARY | VARBINARY;
char_type: CHAR | VARCHAR;
datetime_type: DATE | TIME | TIMESTAMP | DATETIME | YEAR;

on_update_set: literal;
default_value: literal;
comment: string_literal;
connection: string_literal;
password: string_literal;
data_directory: string_literal;
index_directory: string_literal;

as_expression: expression;
query_expression: expression;
check_expression: expression;
hash_expression: expression;
range_expression: expression;
list_expression: expression;
less_than_expression: expression;
expression: LPAREN literal RPAREN;

symbol: identifier;
engine_name: identifier;
old_table_name: table_name;
column_name: identifier;
index_name: identifier;
tablespace_name: identifier;
table_name: (database_name PERIOD)? identifier;
database_name: identifier;
parser_name: identifier;
charset_name: identifier;
collation_name: identifier;
partition_name: identifier;
logical_name: identifier;
