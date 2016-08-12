grammar mysql;

import
    mysql_drop_table,
    mysql_alter_table,
    mysql_create_table;

parse:
    (statement SEMI)* EOF
    ;

statement:
    assignment
    | drop_table
    | alter_table
    | create_table
    ;

assignment:
    SET identifier EQUAL literal
    ;
