grammar mysql_drop_table;

import mysql_create_table;

// http://dev.mysql.com/doc/refman/5.7/en/drop-table.html

drop_table:
    DROP (TEMPORARY)? TABLE (IF EXISTS)? table_name_list (RESTRICT | CASCADE)?
    ;

table_name_list: table_name (COMMA table_name)*;
