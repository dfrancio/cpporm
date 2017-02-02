
// Generated from grammars/mysql/mysql.g4 by ANTLR 4.6

#pragma once

#include "antlr4-runtime.h"

#define SAVED_NULL NULL
#undef NULL
#define SAVED_TRUE TRUE
#undef TRUE
#define SAVED_UNICODE UNICODE
#undef UNICODE

namespace mysql
{

class mysqlParser : public antlr4::Parser
{
public:
    enum
    {
        ACCESSIBLE = 1,
        ACCOUNT = 2,
        ACTION = 3,
        ADD = 4,
        AFTER = 5,
        AGAINST = 6,
        AGGREGATE = 7,
        ALGORITHM = 8,
        ALL = 9,
        ALTER = 10,
        ALWAYS = 11,
        ANALYSE = 12,
        ANALYZE = 13,
        AND = 14,
        ANY = 15,
        AS = 16,
        ASC = 17,
        ASCII = 18,
        ASENSITIVE = 19,
        AT = 20,
        AUTOEXTEND_SIZE = 21,
        AUTO_INCREMENT = 22,
        AVG = 23,
        AVG_ROW_LENGTH = 24,
        BACKUP = 25,
        BEFORE = 26,
        BEGIN = 27,
        BETWEEN = 28,
        BIGINT = 29,
        BINARY = 30,
        BINLOG = 31,
        BIT = 32,
        BLOB = 33,
        BLOCK = 34,
        BOOL = 35,
        BOOLEAN = 36,
        BOTH = 37,
        BTREE = 38,
        BY = 39,
        BYTE = 40,
        CACHE = 41,
        CALL = 42,
        CASCADE = 43,
        CASCADED = 44,
        CASE = 45,
        CATALOG_NAME = 46,
        CHAIN = 47,
        CHANGE = 48,
        CHANGED = 49,
        CHANNEL = 50,
        CHAR = 51,
        CHARACTER = 52,
        CHARSET = 53,
        CHECK = 54,
        CHECKSUM = 55,
        CIPHER = 56,
        CLASS_ORIGIN = 57,
        CLIENT = 58,
        CLOSE = 59,
        COALESCE = 60,
        CODE = 61,
        COLLATE = 62,
        COLLATION = 63,
        COLUMN = 64,
        COLUMNS = 65,
        COLUMN_FORMAT = 66,
        COLUMN_NAME = 67,
        COMMENT = 68,
        COMMIT = 69,
        COMMITTED = 70,
        COMPACT = 71,
        COMPLETION = 72,
        COMPRESSED = 73,
        COMPRESSION = 74,
        CONCURRENT = 75,
        CONDITION = 76,
        CONNECTION = 77,
        CONSISTENT = 78,
        CONSTRAINT = 79,
        CONSTRAINT_CATALOG = 80,
        CONSTRAINT_NAME = 81,
        CONSTRAINT_SCHEMA = 82,
        CONTAINS = 83,
        CONTEXT = 84,
        CONTINUE = 85,
        CONVERT = 86,
        COPY = 87,
        CPU = 88,
        CREATE = 89,
        CROSS = 90,
        CUBE = 91,
        CURRENT = 92,
        CURRENT_DATE = 93,
        CURRENT_TIME = 94,
        CURRENT_TIMESTAMP = 95,
        CURRENT_USER = 96,
        CURSOR = 97,
        CURSOR_NAME = 98,
        DATA = 99,
        DATABASE = 100,
        DATABASES = 101,
        DATAFILE = 102,
        DATE = 103,
        DATETIME = 104,
        DAY = 105,
        DAY_HOUR = 106,
        DAY_MICROSECOND = 107,
        DAY_MINUTE = 108,
        DAY_SECOND = 109,
        DEALLOCATE = 110,
        DEC = 111,
        DECIMAL = 112,
        DECLARE = 113,
        DEFAULT = 114,
        DEFAULT_AUTH = 115,
        DEFINER = 116,
        DELAYED = 117,
        DELAY_KEY_WRITE = 118,
        DELETE = 119,
        DESC = 120,
        DESCRIBE = 121,
        DES_KEY_FILE = 122,
        DETERMINISTIC = 123,
        DIAGNOSTICS = 124,
        DIRECTORY = 125,
        DISABLE = 126,
        DISCARD = 127,
        DISK = 128,
        DISTINCT = 129,
        DISTINCTROW = 130,
        DIV = 131,
        DO = 132,
        DOUBLE = 133,
        DROP = 134,
        DUAL = 135,
        DUMPFILE = 136,
        DUPLICATE = 137,
        DYNAMIC = 138,
        EACH = 139,
        ELSE = 140,
        ELSEIF = 141,
        ENABLE = 142,
        ENCLOSED = 143,
        ENCRYPTION = 144,
        END = 145,
        ENDS = 146,
        ENGINE = 147,
        ENGINES = 148,
        ENUM = 149,
        ERROR = 150,
        ERRORS = 151,
        ESCAPE = 152,
        ESCAPED = 153,
        EVENT = 154,
        EVENTS = 155,
        EVERY = 156,
        EXCHANGE = 157,
        EXCLUSIVE = 158,
        EXECUTE = 159,
        EXISTS = 160,
        EXIT = 161,
        EXPANSION = 162,
        EXPIRE = 163,
        EXPLAIN = 164,
        EXPORT = 165,
        EXTENDED = 166,
        EXTENT_SIZE = 167,
        FALSE = 168,
        FAST = 169,
        FAULTS = 170,
        FETCH = 171,
        FIELDS = 172,
        FILE = 173,
        FILE_BLOCK_SIZE = 174,
        FILTER = 175,
        FIRST = 176,
        FIXED = 177,
        FLOAT = 178,
        FLOAT4 = 179,
        FLOAT8 = 180,
        FLUSH = 181,
        FOLLOWS = 182,
        FOR = 183,
        FORCE = 184,
        FOREIGN = 185,
        FORMAT = 186,
        FOUND = 187,
        FROM = 188,
        FULL = 189,
        FULLTEXT = 190,
        FUNCTION = 191,
        GENERAL = 192,
        GENERATED = 193,
        GEOMETRY = 194,
        GEOMETRYCOLLECTION = 195,
        GET = 196,
        GET_FORMAT = 197,
        GLOBAL = 198,
        GRANT = 199,
        GRANTS = 200,
        GROUP = 201,
        GROUP_REPLICATION = 202,
        HANDLER = 203,
        HASH = 204,
        HAVING = 205,
        HELP = 206,
        HIGH_PRIORITY = 207,
        HOST = 208,
        HOSTS = 209,
        HOUR = 210,
        HOUR_MICROSECOND = 211,
        HOUR_MINUTE = 212,
        HOUR_SECOND = 213,
        IDENTIFIED = 214,
        IF = 215,
        IGNORE = 216,
        IGNORE_SERVER_IDS = 217,
        IMPORT = 218,
        IN = 219,
        INDEX = 220,
        INDEXES = 221,
        INFILE = 222,
        INITIAL_SIZE = 223,
        INNER = 224,
        INOUT = 225,
        INPLACE = 226,
        INSENSITIVE = 227,
        INSERT = 228,
        INSERT_METHOD = 229,
        INSTALL = 230,
        INSTANCE = 231,
        INT = 232,
        INT1 = 233,
        INT2 = 234,
        INT3 = 235,
        INT4 = 236,
        INT8 = 237,
        INTEGER = 238,
        INTERVAL = 239,
        INTO = 240,
        INVOKER = 241,
        IO = 242,
        IO_AFTER_GTIDS = 243,
        IO_BEFORE_GTIDS = 244,
        IO_THREAD = 245,
        IPC = 246,
        IS = 247,
        ISOLATION = 248,
        ISSUER = 249,
        ITERATE = 250,
        JOIN = 251,
        JSON = 252,
        KEY = 253,
        KEYS = 254,
        KEY_BLOCK_SIZE = 255,
        KILL = 256,
        LANGUAGE = 257,
        LAST = 258,
        LEADING = 259,
        LEAVE = 260,
        LEAVES = 261,
        LEFT = 262,
        LESS = 263,
        LEVEL = 264,
        LIKE = 265,
        LIMIT = 266,
        LINEAR = 267,
        LINES = 268,
        LINESTRING = 269,
        LIST = 270,
        LOAD = 271,
        LOCAL = 272,
        LOCALTIME = 273,
        LOCALTIMESTAMP = 274,
        LOCK = 275,
        LOCKS = 276,
        LOGFILE = 277,
        LOGS = 278,
        LONG = 279,
        LONGBLOB = 280,
        LONGTEXT = 281,
        LOOP = 282,
        LOW_PRIORITY = 283,
        MASTER = 284,
        MASTER_AUTO_POSITION = 285,
        MASTER_BIND = 286,
        MASTER_CONNECT_RETRY = 287,
        MASTER_DELAY = 288,
        MASTER_HEARTBEAT_PERIOD = 289,
        MASTER_HOST = 290,
        MASTER_LOG_FILE = 291,
        MASTER_LOG_POS = 292,
        MASTER_PASSWORD = 293,
        MASTER_PORT = 294,
        MASTER_RETRY_COUNT = 295,
        MASTER_SERVER_ID = 296,
        MASTER_SSL = 297,
        MASTER_SSL_CA = 298,
        MASTER_SSL_CAPATH = 299,
        MASTER_SSL_CERT = 300,
        MASTER_SSL_CIPHER = 301,
        MASTER_SSL_CRL = 302,
        MASTER_SSL_CRLPATH = 303,
        MASTER_SSL_KEY = 304,
        MASTER_SSL_VERIFY_SERVER_CERT = 305,
        MASTER_TLS_VERSION = 306,
        MASTER_USER = 307,
        MATCH = 308,
        MAXVALUE = 309,
        MAX_CONNECTIONS_PER_HOUR = 310,
        MAX_QUERIES_PER_HOUR = 311,
        MAX_ROWS = 312,
        MAX_SIZE = 313,
        MAX_STATEMENT_TIME = 314,
        MAX_UPDATES_PER_HOUR = 315,
        MAX_USER_CONNECTIONS = 316,
        MEDIUM = 317,
        MEDIUMBLOB = 318,
        MEDIUMINT = 319,
        MEDIUMTEXT = 320,
        MEMORY = 321,
        MERGE = 322,
        MESSAGE_TEXT = 323,
        MICROSECOND = 324,
        MIDDLEINT = 325,
        MIGRATE = 326,
        MINUTE = 327,
        MINUTE_MICROSECOND = 328,
        MINUTE_SECOND = 329,
        MIN_ROWS = 330,
        MOD = 331,
        MODE = 332,
        MODIFIES = 333,
        MODIFY = 334,
        MONTH = 335,
        MULTILINESTRING = 336,
        MULTIPOINT = 337,
        MULTIPOLYGON = 338,
        MUTEX = 339,
        MYSQL_ERRNO = 340,
        NAME = 341,
        NAMES = 342,
        NATIONAL = 343,
        NATURAL = 344,
        NCHAR = 345,
        NDB = 346,
        NDBCLUSTER = 347,
        NEVER = 348,
        NEW = 349,
        NEXT = 350,
        NO = 351,
        NODEGROUP = 352,
        NONBLOCKING = 353,
        NONE = 354,
        NOT = 355,
        NO_WAIT = 356,
        NO_WRITE_TO_BINLOG = 357,
        NULL = 358,
        NUMBER = 359,
        NUMERIC = 360,
        NVARCHAR = 361,
        OFFSET = 362,
        OLD_PASSWORD = 363,
        ON = 364,
        ONE = 365,
        ONLY = 366,
        OPEN = 367,
        OPTIMIZE = 368,
        OPTIMIZER_COSTS = 369,
        OPTION = 370,
        OPTIONALLY = 371,
        OPTIONS = 372,
        OR = 373,
        ORDER = 374,
        OUT = 375,
        OUTER = 376,
        OUTFILE = 377,
        OWNER = 378,
        PACK_KEYS = 379,
        PAGE = 380,
        PARSER = 381,
        PARSE_GCOL_EXPR = 382,
        PARTIAL = 383,
        PARTITION = 384,
        PARTITIONING = 385,
        PARTITIONS = 386,
        PASSWORD = 387,
        PHASE = 388,
        PLUGIN = 389,
        PLUGINS = 390,
        PLUGIN_DIR = 391,
        POINT = 392,
        POLYGON = 393,
        PORT = 394,
        PRECEDES = 395,
        PRECISION = 396,
        PREPARE = 397,
        PRESERVE = 398,
        PREV = 399,
        PRIMARY = 400,
        PRIVILEGES = 401,
        PROCEDURE = 402,
        PROCESSLIST = 403,
        PROFILE = 404,
        PROFILES = 405,
        PROXY = 406,
        PURGE = 407,
        QUARTER = 408,
        QUERY = 409,
        QUICK = 410,
        RANGE = 411,
        READ = 412,
        READS = 413,
        READ_ONLY = 414,
        READ_WRITE = 415,
        REAL = 416,
        REBUILD = 417,
        RECOVER = 418,
        REDOFILE = 419,
        REDO_BUFFER_SIZE = 420,
        REDUNDANT = 421,
        REFERENCES = 422,
        REGEXP = 423,
        RELAY = 424,
        RELAYLOG = 425,
        RELAY_LOG_FILE = 426,
        RELAY_LOG_POS = 427,
        RELAY_THREAD = 428,
        RELEASE = 429,
        RELOAD = 430,
        REMOVE = 431,
        RENAME = 432,
        REORGANIZE = 433,
        REPAIR = 434,
        REPEAT = 435,
        REPEATABLE = 436,
        REPLACE = 437,
        REPLICATE_DO_DB = 438,
        REPLICATE_DO_TABLE = 439,
        REPLICATE_IGNORE_DB = 440,
        REPLICATE_IGNORE_TABLE = 441,
        REPLICATE_REWRITE_DB = 442,
        REPLICATE_WILD_DO_TABLE = 443,
        REPLICATE_WILD_IGNORE_TABLE = 444,
        REPLICATION = 445,
        REQUIRE = 446,
        RESET = 447,
        RESIGNAL = 448,
        RESTORE = 449,
        RESTRICT = 450,
        RESUME = 451,
        RETURN = 452,
        RETURNED_SQLSTATE = 453,
        RETURNS = 454,
        REVERSE = 455,
        REVOKE = 456,
        RIGHT = 457,
        RLIKE = 458,
        ROLLBACK = 459,
        ROLLUP = 460,
        ROTATE = 461,
        ROUTINE = 462,
        ROW = 463,
        ROWS = 464,
        ROW_COUNT = 465,
        ROW_FORMAT = 466,
        RTREE = 467,
        SAVEPOINT = 468,
        SCHEDULE = 469,
        SCHEMA = 470,
        SCHEMAS = 471,
        SCHEMA_NAME = 472,
        SECOND = 473,
        SECOND_MICROSECOND = 474,
        SECURITY = 475,
        SELECT = 476,
        SENSITIVE = 477,
        SEPARATOR = 478,
        SERIAL = 479,
        SERIALIZABLE = 480,
        SERVER = 481,
        SESSION = 482,
        SET = 483,
        SHARE = 484,
        SHARED = 485,
        SHOW = 486,
        SHUTDOWN = 487,
        SIGNAL = 488,
        SIGNED = 489,
        SIMPLE = 490,
        SLAVE = 491,
        SLOW = 492,
        SMALLINT = 493,
        SNAPSHOT = 494,
        SOCKET = 495,
        SOME = 496,
        SONAME = 497,
        SOUNDS = 498,
        SOURCE = 499,
        SPATIAL = 500,
        SPECIFIC = 501,
        SQL = 502,
        SQLEXCEPTION = 503,
        SQLSTATE = 504,
        SQLWARNING = 505,
        SQL_AFTER_GTIDS = 506,
        SQL_AFTER_MTS_GAPS = 507,
        SQL_BEFORE_GTIDS = 508,
        SQL_BIG_RESULT = 509,
        SQL_BUFFER_RESULT = 510,
        SQL_CACHE = 511,
        SQL_CALC_FOUND_ROWS = 512,
        SQL_NO_CACHE = 513,
        SQL_SMALL_RESULT = 514,
        SQL_THREAD = 515,
        SQL_TSI_DAY = 516,
        SQL_TSI_HOUR = 517,
        SQL_TSI_MINUTE = 518,
        SQL_TSI_MONTH = 519,
        SQL_TSI_QUARTER = 520,
        SQL_TSI_SECOND = 521,
        SQL_TSI_WEEK = 522,
        SQL_TSI_YEAR = 523,
        SSL = 524,
        STACKED = 525,
        START = 526,
        STARTING = 527,
        STARTS = 528,
        STATS_AUTO_RECALC = 529,
        STATS_PERSISTENT = 530,
        STATS_SAMPLE_PAGES = 531,
        STATUS = 532,
        STOP = 533,
        STORAGE = 534,
        STORED = 535,
        STRAIGHT_JOIN = 536,
        STRING = 537,
        SUBCLASS_ORIGIN = 538,
        SUBJECT = 539,
        SUBPARTITION = 540,
        SUBPARTITIONS = 541,
        SUPER = 542,
        SUSPEND = 543,
        SWAPS = 544,
        SWITCHES = 545,
        TABLE = 546,
        TABLES = 547,
        TABLESPACE = 548,
        TABLE_CHECKSUM = 549,
        TABLE_NAME = 550,
        TEMPORARY = 551,
        TEMPTABLE = 552,
        TERMINATED = 553,
        TEXT = 554,
        THAN = 555,
        THEN = 556,
        TIME = 557,
        TIMESTAMP = 558,
        TIMESTAMPADD = 559,
        TIMESTAMPDIFF = 560,
        TINYBLOB = 561,
        TINYINT = 562,
        TINYTEXT = 563,
        TO = 564,
        TRAILING = 565,
        TRANSACTION = 566,
        TRIGGER = 567,
        TRIGGERS = 568,
        TRUE = 569,
        TRUNCATE = 570,
        TYPE = 571,
        TYPES = 572,
        UNCOMMITTED = 573,
        UNDEFINED = 574,
        UNDO = 575,
        UNDOFILE = 576,
        UNDO_BUFFER_SIZE = 577,
        UNICODE = 578,
        UNINSTALL = 579,
        UNION = 580,
        UNIQUE = 581,
        UNKNOWN = 582,
        UNLOCK = 583,
        UNSIGNED = 584,
        UNTIL = 585,
        UPDATE = 586,
        UPGRADE = 587,
        USAGE = 588,
        USE = 589,
        USER = 590,
        USER_RESOURCES = 591,
        USE_FRM = 592,
        USING = 593,
        UTC_DATE = 594,
        UTC_TIME = 595,
        UTC_TIMESTAMP = 596,
        VALIDATION = 597,
        VALUE = 598,
        VALUES = 599,
        VARBINARY = 600,
        VARCHAR = 601,
        VARCHARACTER = 602,
        VARIABLES = 603,
        VARYING = 604,
        VIEW = 605,
        VIRTUAL = 606,
        WAIT = 607,
        WARNINGS = 608,
        WEEK = 609,
        WEIGHT_STRING = 610,
        WHEN = 611,
        WHERE = 612,
        WHILE = 613,
        WITH = 614,
        WITHOUT = 615,
        WORK = 616,
        WRAPPER = 617,
        WRITE = 618,
        X509 = 619,
        XA = 620,
        XID = 621,
        XML = 622,
        XOR = 623,
        YEAR = 624,
        YEAR_MONTH = 625,
        ZEROFILL = 626,
        ID = 627,
        FLOAT_NUMBER = 628,
        INT_NUMBER = 629,
        SQUOTED_STRING = 630,
        DQUOTED_STRING = 631,
        BQUOTED_STRING = 632,
        NON_DIGIT = 633,
        BLOCK_COMMENT = 634,
        LINE_COMMENT = 635,
        WHITE_SPACE = 636,
        LPAREN = 637,
        RPAREN = 638,
        PERIOD = 639,
        COMMA = 640,
        COLON = 641,
        SEMI = 642,
        EQUAL = 643
    };

    enum
    {
        RuleParse = 0,
        RuleStatement = 1,
        RuleAssignment = 2,
        RuleDrop_table = 3,
        RuleTable_name_list = 4,
        RuleCreate_table = 5,
        RuleCreate_definition = 6,
        RuleIndex_definition = 7,
        RuleColumn_definition = 8,
        RuleColumn_options = 9,
        RuleGenerated_column_options = 10,
        RuleData_type = 11,
        RuleTable_option = 12,
        RulePartition_specification = 13,
        RulePartition_definition_list = 14,
        RulePartition_by = 15,
        RuleSubpartition_by = 16,
        RulePartition_definition = 17,
        RuleSubpartition_definition_list = 18,
        RulePartition_values = 19,
        RuleSubpartition_definition = 20,
        RulePartition_options = 21,
        RuleIndex_option = 22,
        RuleReference_definition = 23,
        RuleCreate_definition_list = 24,
        RuleTable_option_list = 25,
        RuleIndex_option_list = 26,
        RuleIndex_column_list = 27,
        RuleReference_column_list = 28,
        RuleLess_than_value_list = 29,
        RuleIn_value_list = 30,
        RuleEnum_value_list = 31,
        RuleKey_column_list = 32,
        RuleRange_column_list = 33,
        RuleList_column_list = 34,
        RuleTable_union_list = 35,
        RuleConstraint = 36,
        RuleCharset = 37,
        RuleCollation = 38,
        RuleIndex_structure = 39,
        RuleIndex_column = 40,
        RuleReference_column = 41,
        RuleFsp = 42,
        RuleLength = 43,
        RuleDecimals = 44,
        RulePartition_count = 45,
        RuleSubpartition_count = 46,
        RuleAuto_increment = 47,
        RuleAvg_row_length = 48,
        RuleKey_block_size = 49,
        RuleMax_number_of_rows = 50,
        RuleMin_number_of_rows = 51,
        RuleStats_sample_pages = 52,
        RuleChecksum = 53,
        RuleCompression = 54,
        RuleDelay_key_write = 55,
        RuleEncryption = 56,
        RuleInsert_method = 57,
        RulePack_keys = 58,
        RuleRow_format = 59,
        RuleStats_auto_recalc = 60,
        RuleStats_persistent = 61,
        RuleKey_algorithm = 62,
        RuleMatch_option = 63,
        RuleOn_delete_option = 64,
        RuleOn_update_option = 65,
        RuleColumn_format = 66,
        RuleColumn_storage = 67,
        RuleInteger_type = 68,
        RuleReal_type = 69,
        RuleText_type = 70,
        RuleBlob_type = 71,
        RuleSpatial_type = 72,
        RuleEnum_type = 73,
        RuleBinary_type = 74,
        RuleChar_type = 75,
        RuleDatetime_type = 76,
        RuleOn_update_set = 77,
        RuleDefault_value = 78,
        RuleComment = 79,
        RuleConnection = 80,
        RulePassword = 81,
        RuleData_directory = 82,
        RuleIndex_directory = 83,
        RuleAs_expression = 84,
        RuleQuery_expression = 85,
        RuleCheck_expression = 86,
        RuleHash_expression = 87,
        RuleRange_expression = 88,
        RuleList_expression = 89,
        RuleLess_than_expression = 90,
        RuleExpression = 91,
        RuleSymbol = 92,
        RuleEngine_name = 93,
        RuleOld_table_name = 94,
        RuleColumn_name = 95,
        RuleIndex_name = 96,
        RuleTablespace_name = 97,
        RuleTable_name = 98,
        RuleDatabase_name = 99,
        RuleParser_name = 100,
        RuleCharset_name = 101,
        RuleCollation_name = 102,
        RulePartition_name = 103,
        RuleLogical_name = 104,
        RuleLiteral = 105,
        RuleIdentifier = 106,
        RuleBool_literal = 107,
        RuleFloat_literal = 108,
        RuleInteger_literal = 109,
        RuleString_literal = 110,
        RuleDatetime_literal = 111,
        RuleAlter_table = 112,
        RuleAlter_specification = 113,
        RuleAlter_specification_list = 114,
        RuleColumn_name_list = 115,
        RulePartition_name_list = 116,
        RuleColumn_definition_list = 117,
        RuleTable_algorithm = 118,
        RuleTable_lock = 119,
        RuleFirst_after = 120,
        RuleFk_symbol = 121,
        RuleNew_table_name = 122,
        RuleOld_column_name = 123,
        RuleNew_column_name = 124,
        RuleOld_index_name = 125,
        RuleNew_index_name = 126,
        RulePartition_number = 127
    };

    mysqlParser(antlr4::TokenStream *input);
    ~mysqlParser();

    virtual std::string getGrammarFileName() const override;
    virtual const antlr4::atn::ATN &getATN() const override
    {
        return _atn;
    };
    virtual const std::vector<std::string> &getTokenNames() const override
    {
        return _tokenNames;
    }; // deprecated: use vocabulary instead.
    virtual const std::vector<std::string> &getRuleNames() const override;
    virtual antlr4::dfa::Vocabulary &getVocabulary() const override;

    class ParseContext;
    class StatementContext;
    class AssignmentContext;
    class Drop_tableContext;
    class Table_name_listContext;
    class Create_tableContext;
    class Create_definitionContext;
    class Index_definitionContext;
    class Column_definitionContext;
    class Column_optionsContext;
    class Generated_column_optionsContext;
    class Data_typeContext;
    class Table_optionContext;
    class Partition_specificationContext;
    class Partition_definition_listContext;
    class Partition_byContext;
    class Subpartition_byContext;
    class Partition_definitionContext;
    class Subpartition_definition_listContext;
    class Partition_valuesContext;
    class Subpartition_definitionContext;
    class Partition_optionsContext;
    class Index_optionContext;
    class Reference_definitionContext;
    class Create_definition_listContext;
    class Table_option_listContext;
    class Index_option_listContext;
    class Index_column_listContext;
    class Reference_column_listContext;
    class Less_than_value_listContext;
    class In_value_listContext;
    class Enum_value_listContext;
    class Key_column_listContext;
    class Range_column_listContext;
    class List_column_listContext;
    class Table_union_listContext;
    class ConstraintContext;
    class CharsetContext;
    class CollationContext;
    class Index_structureContext;
    class Index_columnContext;
    class Reference_columnContext;
    class FspContext;
    class LengthContext;
    class DecimalsContext;
    class Partition_countContext;
    class Subpartition_countContext;
    class Auto_incrementContext;
    class Avg_row_lengthContext;
    class Key_block_sizeContext;
    class Max_number_of_rowsContext;
    class Min_number_of_rowsContext;
    class Stats_sample_pagesContext;
    class ChecksumContext;
    class CompressionContext;
    class Delay_key_writeContext;
    class EncryptionContext;
    class Insert_methodContext;
    class Pack_keysContext;
    class Row_formatContext;
    class Stats_auto_recalcContext;
    class Stats_persistentContext;
    class Key_algorithmContext;
    class Match_optionContext;
    class On_delete_optionContext;
    class On_update_optionContext;
    class Column_formatContext;
    class Column_storageContext;
    class Integer_typeContext;
    class Real_typeContext;
    class Text_typeContext;
    class Blob_typeContext;
    class Spatial_typeContext;
    class Enum_typeContext;
    class Binary_typeContext;
    class Char_typeContext;
    class Datetime_typeContext;
    class On_update_setContext;
    class Default_valueContext;
    class CommentContext;
    class ConnectionContext;
    class PasswordContext;
    class Data_directoryContext;
    class Index_directoryContext;
    class As_expressionContext;
    class Query_expressionContext;
    class Check_expressionContext;
    class Hash_expressionContext;
    class Range_expressionContext;
    class List_expressionContext;
    class Less_than_expressionContext;
    class ExpressionContext;
    class SymbolContext;
    class Engine_nameContext;
    class Old_table_nameContext;
    class Column_nameContext;
    class Index_nameContext;
    class Tablespace_nameContext;
    class Table_nameContext;
    class Database_nameContext;
    class Parser_nameContext;
    class Charset_nameContext;
    class Collation_nameContext;
    class Partition_nameContext;
    class Logical_nameContext;
    class LiteralContext;
    class IdentifierContext;
    class Bool_literalContext;
    class Float_literalContext;
    class Integer_literalContext;
    class String_literalContext;
    class Datetime_literalContext;
    class Alter_tableContext;
    class Alter_specificationContext;
    class Alter_specification_listContext;
    class Column_name_listContext;
    class Partition_name_listContext;
    class Column_definition_listContext;
    class Table_algorithmContext;
    class Table_lockContext;
    class First_afterContext;
    class Fk_symbolContext;
    class New_table_nameContext;
    class Old_column_nameContext;
    class New_column_nameContext;
    class Old_index_nameContext;
    class New_index_nameContext;
    class Partition_numberContext;

    class ParseContext : public antlr4::ParserRuleContext
    {
    public:
        ParseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *EOF();
        std::vector<StatementContext *> statement();
        StatementContext *statement(size_t i);
        std::vector<antlr4::tree::TerminalNode *> SEMI();
        antlr4::tree::TerminalNode *SEMI(size_t i);

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    ParseContext *parse();

    class StatementContext : public antlr4::ParserRuleContext
    {
    public:
        StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        AssignmentContext *assignment();
        Drop_tableContext *drop_table();
        Alter_tableContext *alter_table();
        Create_tableContext *create_table();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    StatementContext *statement();

    class AssignmentContext : public antlr4::ParserRuleContext
    {
    public:
        AssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *SET();
        IdentifierContext *identifier();
        antlr4::tree::TerminalNode *EQUAL();
        LiteralContext *literal();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    AssignmentContext *assignment();

    class Drop_tableContext : public antlr4::ParserRuleContext
    {
    public:
        Drop_tableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *DROP();
        antlr4::tree::TerminalNode *TABLE();
        Table_name_listContext *table_name_list();
        antlr4::tree::TerminalNode *TEMPORARY();
        antlr4::tree::TerminalNode *IF();
        antlr4::tree::TerminalNode *EXISTS();
        antlr4::tree::TerminalNode *RESTRICT();
        antlr4::tree::TerminalNode *CASCADE();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Drop_tableContext *drop_table();

    class Table_name_listContext : public antlr4::ParserRuleContext
    {
    public:
        Table_name_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        std::vector<Table_nameContext *> table_name();
        Table_nameContext *table_name(size_t i);
        std::vector<antlr4::tree::TerminalNode *> COMMA();
        antlr4::tree::TerminalNode *COMMA(size_t i);

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Table_name_listContext *table_name_list();

    class Create_tableContext : public antlr4::ParserRuleContext
    {
    public:
        Create_tableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *CREATE();
        antlr4::tree::TerminalNode *TABLE();
        Table_nameContext *table_name();
        Create_definition_listContext *create_definition_list();
        antlr4::tree::TerminalNode *TEMPORARY();
        antlr4::tree::TerminalNode *IF();
        antlr4::tree::TerminalNode *NOT();
        antlr4::tree::TerminalNode *EXISTS();
        Table_option_listContext *table_option_list();
        Partition_specificationContext *partition_specification();
        antlr4::tree::TerminalNode *LIKE();
        Old_table_nameContext *old_table_name();
        antlr4::tree::TerminalNode *LPAREN();
        antlr4::tree::TerminalNode *RPAREN();
        Query_expressionContext *query_expression();
        antlr4::tree::TerminalNode *AS();
        antlr4::tree::TerminalNode *IGNORE();
        antlr4::tree::TerminalNode *REPLACE();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Create_tableContext *create_table();

    class Create_definitionContext : public antlr4::ParserRuleContext
    {
    public:
        Create_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        Column_nameContext *column_name();
        Column_definitionContext *column_definition();
        Index_definitionContext *index_definition();
        antlr4::tree::TerminalNode *CHECK();
        Check_expressionContext *check_expression();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Create_definitionContext *create_definition();

    class Index_definitionContext : public antlr4::ParserRuleContext
    {
    public:
        Index_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *PRIMARY();
        antlr4::tree::TerminalNode *KEY();
        Index_column_listContext *index_column_list();
        Index_option_listContext *index_option_list();
        ConstraintContext *constraint();
        Index_structureContext *index_structure();
        antlr4::tree::TerminalNode *INDEX();
        Index_nameContext *index_name();
        antlr4::tree::TerminalNode *UNIQUE();
        antlr4::tree::TerminalNode *FULLTEXT();
        antlr4::tree::TerminalNode *SPATIAL();
        antlr4::tree::TerminalNode *FOREIGN();
        Reference_definitionContext *reference_definition();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Index_definitionContext *index_definition();

    class Column_definitionContext : public antlr4::ParserRuleContext
    {
    public:
        Column_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        Data_typeContext *data_type();
        Column_optionsContext *column_options();
        Reference_definitionContext *reference_definition();
        Generated_column_optionsContext *generated_column_options();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Column_definitionContext *column_definition();

    class Column_optionsContext : public antlr4::ParserRuleContext
    {
    public:
        Column_optionsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *NOT();
        antlr4::tree::TerminalNode *NULL();
        antlr4::tree::TerminalNode *DEFAULT();
        Default_valueContext *default_value();
        antlr4::tree::TerminalNode *AUTO_INCREMENT();
        antlr4::tree::TerminalNode *UNIQUE();
        antlr4::tree::TerminalNode *KEY();
        antlr4::tree::TerminalNode *COMMENT();
        CommentContext *comment();
        antlr4::tree::TerminalNode *COLUMN_FORMAT();
        Column_formatContext *column_format();
        antlr4::tree::TerminalNode *STORAGE();
        Column_storageContext *column_storage();
        antlr4::tree::TerminalNode *ON();
        antlr4::tree::TerminalNode *UPDATE();
        On_update_setContext *on_update_set();
        antlr4::tree::TerminalNode *PRIMARY();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Column_optionsContext *column_options();

    class Generated_column_optionsContext : public antlr4::ParserRuleContext
    {
    public:
        Generated_column_optionsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *AS();
        As_expressionContext *as_expression();
        antlr4::tree::TerminalNode *GENERATED();
        antlr4::tree::TerminalNode *ALWAYS();
        antlr4::tree::TerminalNode *UNIQUE();
        antlr4::tree::TerminalNode *COMMENT();
        CommentContext *comment();
        antlr4::tree::TerminalNode *NOT();
        antlr4::tree::TerminalNode *NULL();
        std::vector<antlr4::tree::TerminalNode *> KEY();
        antlr4::tree::TerminalNode *KEY(size_t i);
        antlr4::tree::TerminalNode *VIRTUAL();
        antlr4::tree::TerminalNode *STORED();
        antlr4::tree::TerminalNode *PRIMARY();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Generated_column_optionsContext *generated_column_options();

    class Data_typeContext : public antlr4::ParserRuleContext
    {
    public:
        Data_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        Integer_typeContext *integer_type();
        antlr4::tree::TerminalNode *LPAREN();
        LengthContext *length();
        antlr4::tree::TerminalNode *RPAREN();
        antlr4::tree::TerminalNode *UNSIGNED();
        antlr4::tree::TerminalNode *ZEROFILL();
        Real_typeContext *real_type();
        antlr4::tree::TerminalNode *COMMA();
        DecimalsContext *decimals();
        Datetime_typeContext *datetime_type();
        FspContext *fsp();
        Char_typeContext *char_type();
        antlr4::tree::TerminalNode *BINARY();
        CharsetContext *charset();
        CollationContext *collation();
        Binary_typeContext *binary_type();
        Blob_typeContext *blob_type();
        Text_typeContext *text_type();
        Enum_typeContext *enum_type();
        Enum_value_listContext *enum_value_list();
        Spatial_typeContext *spatial_type();
        antlr4::tree::TerminalNode *JSON();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Data_typeContext *data_type();

    class Table_optionContext : public antlr4::ParserRuleContext
    {
    public:
        Table_optionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *ENGINE();
        Engine_nameContext *engine_name();
        antlr4::tree::TerminalNode *EQUAL();
        antlr4::tree::TerminalNode *AUTO_INCREMENT();
        Auto_incrementContext *auto_increment();
        antlr4::tree::TerminalNode *AVG_ROW_LENGTH();
        Avg_row_lengthContext *avg_row_length();
        CharsetContext *charset();
        antlr4::tree::TerminalNode *DEFAULT();
        antlr4::tree::TerminalNode *CHECKSUM();
        ChecksumContext *checksum();
        CollationContext *collation();
        antlr4::tree::TerminalNode *COMMENT();
        CommentContext *comment();
        antlr4::tree::TerminalNode *COMPRESSION();
        CompressionContext *compression();
        antlr4::tree::TerminalNode *CONNECTION();
        ConnectionContext *connection();
        antlr4::tree::TerminalNode *DATA();
        antlr4::tree::TerminalNode *DIRECTORY();
        Data_directoryContext *data_directory();
        antlr4::tree::TerminalNode *DELAY_KEY_WRITE();
        Delay_key_writeContext *delay_key_write();
        antlr4::tree::TerminalNode *ENCRYPTION();
        EncryptionContext *encryption();
        antlr4::tree::TerminalNode *INDEX();
        Index_directoryContext *index_directory();
        antlr4::tree::TerminalNode *INSERT_METHOD();
        Insert_methodContext *insert_method();
        antlr4::tree::TerminalNode *KEY_BLOCK_SIZE();
        Key_block_sizeContext *key_block_size();
        antlr4::tree::TerminalNode *MAX_ROWS();
        Max_number_of_rowsContext *max_number_of_rows();
        antlr4::tree::TerminalNode *MIN_ROWS();
        Min_number_of_rowsContext *min_number_of_rows();
        antlr4::tree::TerminalNode *PACK_KEYS();
        Pack_keysContext *pack_keys();
        antlr4::tree::TerminalNode *PASSWORD();
        PasswordContext *password();
        antlr4::tree::TerminalNode *ROW_FORMAT();
        Row_formatContext *row_format();
        antlr4::tree::TerminalNode *STATS_AUTO_RECALC();
        Stats_auto_recalcContext *stats_auto_recalc();
        antlr4::tree::TerminalNode *STATS_PERSISTENT();
        Stats_persistentContext *stats_persistent();
        antlr4::tree::TerminalNode *STATS_SAMPLE_PAGES();
        Stats_sample_pagesContext *stats_sample_pages();
        antlr4::tree::TerminalNode *TABLESPACE();
        Tablespace_nameContext *tablespace_name();
        antlr4::tree::TerminalNode *UNION();
        Table_union_listContext *table_union_list();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Table_optionContext *table_option();

    class Partition_specificationContext : public antlr4::ParserRuleContext
    {
    public:
        Partition_specificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *PARTITION();
        std::vector<antlr4::tree::TerminalNode *> BY();
        antlr4::tree::TerminalNode *BY(size_t i);
        Partition_byContext *partition_by();
        antlr4::tree::TerminalNode *PARTITIONS();
        Partition_countContext *partition_count();
        antlr4::tree::TerminalNode *SUBPARTITION();
        Subpartition_byContext *subpartition_by();
        Partition_definition_listContext *partition_definition_list();
        antlr4::tree::TerminalNode *SUBPARTITIONS();
        Subpartition_countContext *subpartition_count();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Partition_specificationContext *partition_specification();

    class Partition_definition_listContext : public antlr4::ParserRuleContext
    {
    public:
        Partition_definition_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *LPAREN();
        std::vector<Partition_definitionContext *> partition_definition();
        Partition_definitionContext *partition_definition(size_t i);
        antlr4::tree::TerminalNode *RPAREN();
        std::vector<antlr4::tree::TerminalNode *> COMMA();
        antlr4::tree::TerminalNode *COMMA(size_t i);

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Partition_definition_listContext *partition_definition_list();

    class Partition_byContext : public antlr4::ParserRuleContext
    {
    public:
        Partition_byContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *HASH();
        Hash_expressionContext *hash_expression();
        antlr4::tree::TerminalNode *LINEAR();
        antlr4::tree::TerminalNode *KEY();
        Key_column_listContext *key_column_list();
        antlr4::tree::TerminalNode *ALGORITHM();
        antlr4::tree::TerminalNode *EQUAL();
        Key_algorithmContext *key_algorithm();
        antlr4::tree::TerminalNode *RANGE();
        Range_expressionContext *range_expression();
        antlr4::tree::TerminalNode *COLUMNS();
        Range_column_listContext *range_column_list();
        antlr4::tree::TerminalNode *LIST();
        List_expressionContext *list_expression();
        List_column_listContext *list_column_list();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Partition_byContext *partition_by();

    class Subpartition_byContext : public antlr4::ParserRuleContext
    {
    public:
        Subpartition_byContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *HASH();
        Hash_expressionContext *hash_expression();
        antlr4::tree::TerminalNode *LINEAR();
        antlr4::tree::TerminalNode *KEY();
        Key_column_listContext *key_column_list();
        antlr4::tree::TerminalNode *ALGORITHM();
        antlr4::tree::TerminalNode *EQUAL();
        Key_algorithmContext *key_algorithm();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Subpartition_byContext *subpartition_by();

    class Partition_definitionContext : public antlr4::ParserRuleContext
    {
    public:
        Partition_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *PARTITION();
        Partition_nameContext *partition_name();
        Partition_optionsContext *partition_options();
        Partition_valuesContext *partition_values();
        Subpartition_definition_listContext *subpartition_definition_list();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Partition_definitionContext *partition_definition();

    class Subpartition_definition_listContext : public antlr4::ParserRuleContext
    {
    public:
        Subpartition_definition_listContext(
            antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *LPAREN();
        std::vector<Subpartition_definitionContext *> subpartition_definition();
        Subpartition_definitionContext *subpartition_definition(size_t i);
        antlr4::tree::TerminalNode *RPAREN();
        std::vector<antlr4::tree::TerminalNode *> COMMA();
        antlr4::tree::TerminalNode *COMMA(size_t i);

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Subpartition_definition_listContext *subpartition_definition_list();

    class Partition_valuesContext : public antlr4::ParserRuleContext
    {
    public:
        Partition_valuesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *VALUES();
        antlr4::tree::TerminalNode *LESS();
        antlr4::tree::TerminalNode *THAN();
        antlr4::tree::TerminalNode *IN();
        In_value_listContext *in_value_list();
        Less_than_expressionContext *less_than_expression();
        Less_than_value_listContext *less_than_value_list();
        antlr4::tree::TerminalNode *MAXVALUE();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Partition_valuesContext *partition_values();

    class Subpartition_definitionContext : public antlr4::ParserRuleContext
    {
    public:
        Subpartition_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *SUBPARTITION();
        Logical_nameContext *logical_name();
        Partition_optionsContext *partition_options();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Subpartition_definitionContext *subpartition_definition();

    class Partition_optionsContext : public antlr4::ParserRuleContext
    {
    public:
        Partition_optionsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *ENGINE();
        Engine_nameContext *engine_name();
        antlr4::tree::TerminalNode *COMMENT();
        CommentContext *comment();
        antlr4::tree::TerminalNode *DATA();
        std::vector<antlr4::tree::TerminalNode *> DIRECTORY();
        antlr4::tree::TerminalNode *DIRECTORY(size_t i);
        Data_directoryContext *data_directory();
        antlr4::tree::TerminalNode *INDEX();
        Index_directoryContext *index_directory();
        antlr4::tree::TerminalNode *MAX_ROWS();
        Max_number_of_rowsContext *max_number_of_rows();
        antlr4::tree::TerminalNode *MIN_ROWS();
        Min_number_of_rowsContext *min_number_of_rows();
        antlr4::tree::TerminalNode *TABLESPACE();
        Tablespace_nameContext *tablespace_name();
        antlr4::tree::TerminalNode *STORAGE();
        std::vector<antlr4::tree::TerminalNode *> EQUAL();
        antlr4::tree::TerminalNode *EQUAL(size_t i);

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Partition_optionsContext *partition_options();

    class Index_optionContext : public antlr4::ParserRuleContext
    {
    public:
        Index_optionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *KEY_BLOCK_SIZE();
        Key_block_sizeContext *key_block_size();
        antlr4::tree::TerminalNode *EQUAL();
        antlr4::tree::TerminalNode *USING();
        Index_structureContext *index_structure();
        antlr4::tree::TerminalNode *WITH();
        antlr4::tree::TerminalNode *PARSER();
        Parser_nameContext *parser_name();
        antlr4::tree::TerminalNode *COMMENT();
        CommentContext *comment();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Index_optionContext *index_option();

    class Reference_definitionContext : public antlr4::ParserRuleContext
    {
    public:
        Reference_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *REFERENCES();
        Table_nameContext *table_name();
        Reference_column_listContext *reference_column_list();
        antlr4::tree::TerminalNode *MATCH();
        Match_optionContext *match_option();
        std::vector<antlr4::tree::TerminalNode *> ON();
        antlr4::tree::TerminalNode *ON(size_t i);
        antlr4::tree::TerminalNode *DELETE();
        On_delete_optionContext *on_delete_option();
        antlr4::tree::TerminalNode *UPDATE();
        On_update_optionContext *on_update_option();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Reference_definitionContext *reference_definition();

    class Create_definition_listContext : public antlr4::ParserRuleContext
    {
    public:
        Create_definition_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *LPAREN();
        std::vector<Create_definitionContext *> create_definition();
        Create_definitionContext *create_definition(size_t i);
        antlr4::tree::TerminalNode *RPAREN();
        std::vector<antlr4::tree::TerminalNode *> COMMA();
        antlr4::tree::TerminalNode *COMMA(size_t i);

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Create_definition_listContext *create_definition_list();

    class Table_option_listContext : public antlr4::ParserRuleContext
    {
    public:
        Table_option_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        std::vector<Table_optionContext *> table_option();
        Table_optionContext *table_option(size_t i);
        std::vector<antlr4::tree::TerminalNode *> COMMA();
        antlr4::tree::TerminalNode *COMMA(size_t i);

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Table_option_listContext *table_option_list();

    class Index_option_listContext : public antlr4::ParserRuleContext
    {
    public:
        Index_option_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        std::vector<Index_optionContext *> index_option();
        Index_optionContext *index_option(size_t i);

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Index_option_listContext *index_option_list();

    class Index_column_listContext : public antlr4::ParserRuleContext
    {
    public:
        Index_column_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *LPAREN();
        std::vector<Index_columnContext *> index_column();
        Index_columnContext *index_column(size_t i);
        antlr4::tree::TerminalNode *RPAREN();
        std::vector<antlr4::tree::TerminalNode *> COMMA();
        antlr4::tree::TerminalNode *COMMA(size_t i);

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Index_column_listContext *index_column_list();

    class Reference_column_listContext : public antlr4::ParserRuleContext
    {
    public:
        Reference_column_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *LPAREN();
        std::vector<Reference_columnContext *> reference_column();
        Reference_columnContext *reference_column(size_t i);
        antlr4::tree::TerminalNode *RPAREN();
        std::vector<antlr4::tree::TerminalNode *> COMMA();
        antlr4::tree::TerminalNode *COMMA(size_t i);

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Reference_column_listContext *reference_column_list();

    class Less_than_value_listContext : public antlr4::ParserRuleContext
    {
    public:
        Less_than_value_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *LPAREN();
        std::vector<LiteralContext *> literal();
        LiteralContext *literal(size_t i);
        antlr4::tree::TerminalNode *RPAREN();
        std::vector<antlr4::tree::TerminalNode *> COMMA();
        antlr4::tree::TerminalNode *COMMA(size_t i);

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Less_than_value_listContext *less_than_value_list();

    class In_value_listContext : public antlr4::ParserRuleContext
    {
    public:
        In_value_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *LPAREN();
        std::vector<LiteralContext *> literal();
        LiteralContext *literal(size_t i);
        antlr4::tree::TerminalNode *RPAREN();
        std::vector<antlr4::tree::TerminalNode *> COMMA();
        antlr4::tree::TerminalNode *COMMA(size_t i);

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    In_value_listContext *in_value_list();

    class Enum_value_listContext : public antlr4::ParserRuleContext
    {
    public:
        Enum_value_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *LPAREN();
        std::vector<LiteralContext *> literal();
        LiteralContext *literal(size_t i);
        antlr4::tree::TerminalNode *RPAREN();
        std::vector<antlr4::tree::TerminalNode *> COMMA();
        antlr4::tree::TerminalNode *COMMA(size_t i);

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Enum_value_listContext *enum_value_list();

    class Key_column_listContext : public antlr4::ParserRuleContext
    {
    public:
        Key_column_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *LPAREN();
        std::vector<IdentifierContext *> identifier();
        IdentifierContext *identifier(size_t i);
        antlr4::tree::TerminalNode *RPAREN();
        std::vector<antlr4::tree::TerminalNode *> COMMA();
        antlr4::tree::TerminalNode *COMMA(size_t i);

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Key_column_listContext *key_column_list();

    class Range_column_listContext : public antlr4::ParserRuleContext
    {
    public:
        Range_column_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *LPAREN();
        std::vector<IdentifierContext *> identifier();
        IdentifierContext *identifier(size_t i);
        antlr4::tree::TerminalNode *RPAREN();
        std::vector<antlr4::tree::TerminalNode *> COMMA();
        antlr4::tree::TerminalNode *COMMA(size_t i);

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Range_column_listContext *range_column_list();

    class List_column_listContext : public antlr4::ParserRuleContext
    {
    public:
        List_column_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *LPAREN();
        std::vector<IdentifierContext *> identifier();
        IdentifierContext *identifier(size_t i);
        antlr4::tree::TerminalNode *RPAREN();
        std::vector<antlr4::tree::TerminalNode *> COMMA();
        antlr4::tree::TerminalNode *COMMA(size_t i);

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    List_column_listContext *list_column_list();

    class Table_union_listContext : public antlr4::ParserRuleContext
    {
    public:
        Table_union_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *LPAREN();
        std::vector<Table_nameContext *> table_name();
        Table_nameContext *table_name(size_t i);
        antlr4::tree::TerminalNode *RPAREN();
        std::vector<antlr4::tree::TerminalNode *> COMMA();
        antlr4::tree::TerminalNode *COMMA(size_t i);

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Table_union_listContext *table_union_list();

    class ConstraintContext : public antlr4::ParserRuleContext
    {
    public:
        ConstraintContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *CONSTRAINT();
        SymbolContext *symbol();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    ConstraintContext *constraint();

    class CharsetContext : public antlr4::ParserRuleContext
    {
    public:
        CharsetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        Charset_nameContext *charset_name();
        antlr4::tree::TerminalNode *CHARACTER();
        antlr4::tree::TerminalNode *SET();
        antlr4::tree::TerminalNode *CHARSET();
        antlr4::tree::TerminalNode *EQUAL();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    CharsetContext *charset();

    class CollationContext : public antlr4::ParserRuleContext
    {
    public:
        CollationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *COLLATE();
        Collation_nameContext *collation_name();
        antlr4::tree::TerminalNode *EQUAL();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    CollationContext *collation();

    class Index_structureContext : public antlr4::ParserRuleContext
    {
    public:
        Index_structureContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *BTREE();
        antlr4::tree::TerminalNode *HASH();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Index_structureContext *index_structure();

    class Index_columnContext : public antlr4::ParserRuleContext
    {
    public:
        Index_columnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        Column_nameContext *column_name();
        antlr4::tree::TerminalNode *LPAREN();
        LengthContext *length();
        antlr4::tree::TerminalNode *RPAREN();
        antlr4::tree::TerminalNode *ASC();
        antlr4::tree::TerminalNode *DESC();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Index_columnContext *index_column();

    class Reference_columnContext : public antlr4::ParserRuleContext
    {
    public:
        Reference_columnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        Column_nameContext *column_name();
        antlr4::tree::TerminalNode *LPAREN();
        LengthContext *length();
        antlr4::tree::TerminalNode *RPAREN();
        antlr4::tree::TerminalNode *ASC();
        antlr4::tree::TerminalNode *DESC();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Reference_columnContext *reference_column();

    class FspContext : public antlr4::ParserRuleContext
    {
    public:
        FspContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        Integer_literalContext *integer_literal();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    FspContext *fsp();

    class LengthContext : public antlr4::ParserRuleContext
    {
    public:
        LengthContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        Integer_literalContext *integer_literal();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    LengthContext *length();

    class DecimalsContext : public antlr4::ParserRuleContext
    {
    public:
        DecimalsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        Integer_literalContext *integer_literal();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    DecimalsContext *decimals();

    class Partition_countContext : public antlr4::ParserRuleContext
    {
    public:
        Partition_countContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        Integer_literalContext *integer_literal();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Partition_countContext *partition_count();

    class Subpartition_countContext : public antlr4::ParserRuleContext
    {
    public:
        Subpartition_countContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        Integer_literalContext *integer_literal();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Subpartition_countContext *subpartition_count();

    class Auto_incrementContext : public antlr4::ParserRuleContext
    {
    public:
        Auto_incrementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        Integer_literalContext *integer_literal();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Auto_incrementContext *auto_increment();

    class Avg_row_lengthContext : public antlr4::ParserRuleContext
    {
    public:
        Avg_row_lengthContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        Integer_literalContext *integer_literal();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Avg_row_lengthContext *avg_row_length();

    class Key_block_sizeContext : public antlr4::ParserRuleContext
    {
    public:
        Key_block_sizeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        Integer_literalContext *integer_literal();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Key_block_sizeContext *key_block_size();

    class Max_number_of_rowsContext : public antlr4::ParserRuleContext
    {
    public:
        Max_number_of_rowsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        Integer_literalContext *integer_literal();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Max_number_of_rowsContext *max_number_of_rows();

    class Min_number_of_rowsContext : public antlr4::ParserRuleContext
    {
    public:
        Min_number_of_rowsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        Integer_literalContext *integer_literal();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Min_number_of_rowsContext *min_number_of_rows();

    class Stats_sample_pagesContext : public antlr4::ParserRuleContext
    {
    public:
        Stats_sample_pagesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        Integer_literalContext *integer_literal();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Stats_sample_pagesContext *stats_sample_pages();

    class ChecksumContext : public antlr4::ParserRuleContext
    {
    public:
        ChecksumContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        Integer_literalContext *integer_literal();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    ChecksumContext *checksum();

    class CompressionContext : public antlr4::ParserRuleContext
    {
    public:
        CompressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        String_literalContext *string_literal();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    CompressionContext *compression();

    class Delay_key_writeContext : public antlr4::ParserRuleContext
    {
    public:
        Delay_key_writeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        Integer_literalContext *integer_literal();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Delay_key_writeContext *delay_key_write();

    class EncryptionContext : public antlr4::ParserRuleContext
    {
    public:
        EncryptionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        String_literalContext *string_literal();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    EncryptionContext *encryption();

    class Insert_methodContext : public antlr4::ParserRuleContext
    {
    public:
        Insert_methodContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *NO();
        antlr4::tree::TerminalNode *FIRST();
        antlr4::tree::TerminalNode *LAST();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Insert_methodContext *insert_method();

    class Pack_keysContext : public antlr4::ParserRuleContext
    {
    public:
        Pack_keysContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        Integer_literalContext *integer_literal();
        antlr4::tree::TerminalNode *DEFAULT();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Pack_keysContext *pack_keys();

    class Row_formatContext : public antlr4::ParserRuleContext
    {
    public:
        Row_formatContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *DEFAULT();
        antlr4::tree::TerminalNode *DYNAMIC();
        antlr4::tree::TerminalNode *FIXED();
        antlr4::tree::TerminalNode *COMPRESSED();
        antlr4::tree::TerminalNode *REDUNDANT();
        antlr4::tree::TerminalNode *COMPACT();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Row_formatContext *row_format();

    class Stats_auto_recalcContext : public antlr4::ParserRuleContext
    {
    public:
        Stats_auto_recalcContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *DEFAULT();
        Integer_literalContext *integer_literal();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Stats_auto_recalcContext *stats_auto_recalc();

    class Stats_persistentContext : public antlr4::ParserRuleContext
    {
    public:
        Stats_persistentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *DEFAULT();
        Integer_literalContext *integer_literal();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Stats_persistentContext *stats_persistent();

    class Key_algorithmContext : public antlr4::ParserRuleContext
    {
    public:
        Key_algorithmContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        Integer_literalContext *integer_literal();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Key_algorithmContext *key_algorithm();

    class Match_optionContext : public antlr4::ParserRuleContext
    {
    public:
        Match_optionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *FULL();
        antlr4::tree::TerminalNode *PARTIAL();
        antlr4::tree::TerminalNode *SIMPLE();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Match_optionContext *match_option();

    class On_delete_optionContext : public antlr4::ParserRuleContext
    {
    public:
        On_delete_optionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *RESTRICT();
        antlr4::tree::TerminalNode *CASCADE();
        antlr4::tree::TerminalNode *SET();
        antlr4::tree::TerminalNode *NULL();
        antlr4::tree::TerminalNode *NO();
        antlr4::tree::TerminalNode *ACTION();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    On_delete_optionContext *on_delete_option();

    class On_update_optionContext : public antlr4::ParserRuleContext
    {
    public:
        On_update_optionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *RESTRICT();
        antlr4::tree::TerminalNode *CASCADE();
        antlr4::tree::TerminalNode *SET();
        antlr4::tree::TerminalNode *NULL();
        antlr4::tree::TerminalNode *NO();
        antlr4::tree::TerminalNode *ACTION();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    On_update_optionContext *on_update_option();

    class Column_formatContext : public antlr4::ParserRuleContext
    {
    public:
        Column_formatContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *FIXED();
        antlr4::tree::TerminalNode *DYNAMIC();
        antlr4::tree::TerminalNode *DEFAULT();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Column_formatContext *column_format();

    class Column_storageContext : public antlr4::ParserRuleContext
    {
    public:
        Column_storageContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *DISK();
        antlr4::tree::TerminalNode *MEMORY();
        antlr4::tree::TerminalNode *DEFAULT();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Column_storageContext *column_storage();

    class Integer_typeContext : public antlr4::ParserRuleContext
    {
    public:
        Integer_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *TINYINT();
        antlr4::tree::TerminalNode *SMALLINT();
        antlr4::tree::TerminalNode *MEDIUMINT();
        antlr4::tree::TerminalNode *INT();
        antlr4::tree::TerminalNode *INTEGER();
        antlr4::tree::TerminalNode *BIGINT();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Integer_typeContext *integer_type();

    class Real_typeContext : public antlr4::ParserRuleContext
    {
    public:
        Real_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *REAL();
        antlr4::tree::TerminalNode *DOUBLE();
        antlr4::tree::TerminalNode *PRECISION();
        antlr4::tree::TerminalNode *FLOAT();
        antlr4::tree::TerminalNode *DECIMAL();
        antlr4::tree::TerminalNode *NUMERIC();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Real_typeContext *real_type();

    class Text_typeContext : public antlr4::ParserRuleContext
    {
    public:
        Text_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *TINYTEXT();
        antlr4::tree::TerminalNode *TEXT();
        antlr4::tree::TerminalNode *MEDIUMTEXT();
        antlr4::tree::TerminalNode *LONGTEXT();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Text_typeContext *text_type();

    class Blob_typeContext : public antlr4::ParserRuleContext
    {
    public:
        Blob_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *TINYBLOB();
        antlr4::tree::TerminalNode *BLOB();
        antlr4::tree::TerminalNode *MEDIUMBLOB();
        antlr4::tree::TerminalNode *LONGBLOB();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Blob_typeContext *blob_type();

    class Spatial_typeContext : public antlr4::ParserRuleContext
    {
    public:
        Spatial_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *GEOMETRY();
        antlr4::tree::TerminalNode *POINT();
        antlr4::tree::TerminalNode *LINESTRING();
        antlr4::tree::TerminalNode *POLYGON();
        antlr4::tree::TerminalNode *MULTIPOINT();
        antlr4::tree::TerminalNode *MULTILINESTRING();
        antlr4::tree::TerminalNode *MULTIPOLYGON();
        antlr4::tree::TerminalNode *GEOMETRYCOLLECTION();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Spatial_typeContext *spatial_type();

    class Enum_typeContext : public antlr4::ParserRuleContext
    {
    public:
        Enum_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *ENUM();
        antlr4::tree::TerminalNode *SET();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Enum_typeContext *enum_type();

    class Binary_typeContext : public antlr4::ParserRuleContext
    {
    public:
        Binary_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *BIT();
        antlr4::tree::TerminalNode *BINARY();
        antlr4::tree::TerminalNode *VARBINARY();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Binary_typeContext *binary_type();

    class Char_typeContext : public antlr4::ParserRuleContext
    {
    public:
        Char_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *CHAR();
        antlr4::tree::TerminalNode *VARCHAR();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Char_typeContext *char_type();

    class Datetime_typeContext : public antlr4::ParserRuleContext
    {
    public:
        Datetime_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *DATE();
        antlr4::tree::TerminalNode *TIME();
        antlr4::tree::TerminalNode *TIMESTAMP();
        antlr4::tree::TerminalNode *DATETIME();
        antlr4::tree::TerminalNode *YEAR();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Datetime_typeContext *datetime_type();

    class On_update_setContext : public antlr4::ParserRuleContext
    {
    public:
        On_update_setContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        LiteralContext *literal();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    On_update_setContext *on_update_set();

    class Default_valueContext : public antlr4::ParserRuleContext
    {
    public:
        Default_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        LiteralContext *literal();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Default_valueContext *default_value();

    class CommentContext : public antlr4::ParserRuleContext
    {
    public:
        CommentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        String_literalContext *string_literal();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    CommentContext *comment();

    class ConnectionContext : public antlr4::ParserRuleContext
    {
    public:
        ConnectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        String_literalContext *string_literal();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    ConnectionContext *connection();

    class PasswordContext : public antlr4::ParserRuleContext
    {
    public:
        PasswordContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        String_literalContext *string_literal();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    PasswordContext *password();

    class Data_directoryContext : public antlr4::ParserRuleContext
    {
    public:
        Data_directoryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        String_literalContext *string_literal();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Data_directoryContext *data_directory();

    class Index_directoryContext : public antlr4::ParserRuleContext
    {
    public:
        Index_directoryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        String_literalContext *string_literal();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Index_directoryContext *index_directory();

    class As_expressionContext : public antlr4::ParserRuleContext
    {
    public:
        As_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        ExpressionContext *expression();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    As_expressionContext *as_expression();

    class Query_expressionContext : public antlr4::ParserRuleContext
    {
    public:
        Query_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        ExpressionContext *expression();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Query_expressionContext *query_expression();

    class Check_expressionContext : public antlr4::ParserRuleContext
    {
    public:
        Check_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        ExpressionContext *expression();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Check_expressionContext *check_expression();

    class Hash_expressionContext : public antlr4::ParserRuleContext
    {
    public:
        Hash_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        ExpressionContext *expression();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Hash_expressionContext *hash_expression();

    class Range_expressionContext : public antlr4::ParserRuleContext
    {
    public:
        Range_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        ExpressionContext *expression();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Range_expressionContext *range_expression();

    class List_expressionContext : public antlr4::ParserRuleContext
    {
    public:
        List_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        ExpressionContext *expression();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    List_expressionContext *list_expression();

    class Less_than_expressionContext : public antlr4::ParserRuleContext
    {
    public:
        Less_than_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        ExpressionContext *expression();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Less_than_expressionContext *less_than_expression();

    class ExpressionContext : public antlr4::ParserRuleContext
    {
    public:
        ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *LPAREN();
        LiteralContext *literal();
        antlr4::tree::TerminalNode *RPAREN();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    ExpressionContext *expression();

    class SymbolContext : public antlr4::ParserRuleContext
    {
    public:
        SymbolContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        IdentifierContext *identifier();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    SymbolContext *symbol();

    class Engine_nameContext : public antlr4::ParserRuleContext
    {
    public:
        Engine_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        IdentifierContext *identifier();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Engine_nameContext *engine_name();

    class Old_table_nameContext : public antlr4::ParserRuleContext
    {
    public:
        Old_table_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        Table_nameContext *table_name();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Old_table_nameContext *old_table_name();

    class Column_nameContext : public antlr4::ParserRuleContext
    {
    public:
        Column_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        IdentifierContext *identifier();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Column_nameContext *column_name();

    class Index_nameContext : public antlr4::ParserRuleContext
    {
    public:
        Index_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        IdentifierContext *identifier();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Index_nameContext *index_name();

    class Tablespace_nameContext : public antlr4::ParserRuleContext
    {
    public:
        Tablespace_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        IdentifierContext *identifier();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Tablespace_nameContext *tablespace_name();

    class Table_nameContext : public antlr4::ParserRuleContext
    {
    public:
        Table_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        IdentifierContext *identifier();
        Database_nameContext *database_name();
        antlr4::tree::TerminalNode *PERIOD();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Table_nameContext *table_name();

    class Database_nameContext : public antlr4::ParserRuleContext
    {
    public:
        Database_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        IdentifierContext *identifier();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Database_nameContext *database_name();

    class Parser_nameContext : public antlr4::ParserRuleContext
    {
    public:
        Parser_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        IdentifierContext *identifier();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Parser_nameContext *parser_name();

    class Charset_nameContext : public antlr4::ParserRuleContext
    {
    public:
        Charset_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        IdentifierContext *identifier();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Charset_nameContext *charset_name();

    class Collation_nameContext : public antlr4::ParserRuleContext
    {
    public:
        Collation_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        IdentifierContext *identifier();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Collation_nameContext *collation_name();

    class Partition_nameContext : public antlr4::ParserRuleContext
    {
    public:
        Partition_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        IdentifierContext *identifier();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Partition_nameContext *partition_name();

    class Logical_nameContext : public antlr4::ParserRuleContext
    {
    public:
        Logical_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        IdentifierContext *identifier();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Logical_nameContext *logical_name();

    class LiteralContext : public antlr4::ParserRuleContext
    {
    public:
        LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *NULL();
        Bool_literalContext *bool_literal();
        Float_literalContext *float_literal();
        Integer_literalContext *integer_literal();
        String_literalContext *string_literal();
        Datetime_literalContext *datetime_literal();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    LiteralContext *literal();

    class IdentifierContext : public antlr4::ParserRuleContext
    {
    public:
        IdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *ID();
        antlr4::tree::TerminalNode *BQUOTED_STRING();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    IdentifierContext *identifier();

    class Bool_literalContext : public antlr4::ParserRuleContext
    {
    public:
        Bool_literalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *TRUE();
        antlr4::tree::TerminalNode *FALSE();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Bool_literalContext *bool_literal();

    class Float_literalContext : public antlr4::ParserRuleContext
    {
    public:
        Float_literalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *FLOAT_NUMBER();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Float_literalContext *float_literal();

    class Integer_literalContext : public antlr4::ParserRuleContext
    {
    public:
        Integer_literalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *INT_NUMBER();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Integer_literalContext *integer_literal();

    class String_literalContext : public antlr4::ParserRuleContext
    {
    public:
        String_literalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *SQUOTED_STRING();
        antlr4::tree::TerminalNode *DQUOTED_STRING();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    String_literalContext *string_literal();

    class Datetime_literalContext : public antlr4::ParserRuleContext
    {
    public:
        Datetime_literalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *CURRENT_DATE();
        antlr4::tree::TerminalNode *CURRENT_TIME();
        antlr4::tree::TerminalNode *CURRENT_TIMESTAMP();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Datetime_literalContext *datetime_literal();

    class Alter_tableContext : public antlr4::ParserRuleContext
    {
    public:
        Alter_tableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *ALTER();
        antlr4::tree::TerminalNode *TABLE();
        Table_nameContext *table_name();
        antlr4::tree::TerminalNode *IGNORE();
        Alter_specification_listContext *alter_specification_list();
        Partition_specificationContext *partition_specification();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Alter_tableContext *alter_table();

    class Alter_specificationContext : public antlr4::ParserRuleContext
    {
    public:
        Alter_specificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        Table_option_listContext *table_option_list();
        antlr4::tree::TerminalNode *ADD();
        Column_nameContext *column_name();
        Column_definitionContext *column_definition();
        antlr4::tree::TerminalNode *COLUMN();
        First_afterContext *first_after();
        Column_definition_listContext *column_definition_list();
        Index_definitionContext *index_definition();
        antlr4::tree::TerminalNode *ALGORITHM();
        Table_algorithmContext *table_algorithm();
        antlr4::tree::TerminalNode *EQUAL();
        antlr4::tree::TerminalNode *ALTER();
        antlr4::tree::TerminalNode *SET();
        antlr4::tree::TerminalNode *DEFAULT();
        Default_valueContext *default_value();
        antlr4::tree::TerminalNode *DROP();
        antlr4::tree::TerminalNode *CHANGE();
        Old_column_nameContext *old_column_name();
        New_column_nameContext *new_column_name();
        antlr4::tree::TerminalNode *LOCK();
        Table_lockContext *table_lock();
        antlr4::tree::TerminalNode *MODIFY();
        antlr4::tree::TerminalNode *PRIMARY();
        antlr4::tree::TerminalNode *KEY();
        Index_nameContext *index_name();
        antlr4::tree::TerminalNode *INDEX();
        antlr4::tree::TerminalNode *FOREIGN();
        Fk_symbolContext *fk_symbol();
        antlr4::tree::TerminalNode *DISABLE();
        antlr4::tree::TerminalNode *KEYS();
        antlr4::tree::TerminalNode *ENABLE();
        antlr4::tree::TerminalNode *RENAME();
        New_table_nameContext *new_table_name();
        antlr4::tree::TerminalNode *TO();
        antlr4::tree::TerminalNode *AS();
        Old_index_nameContext *old_index_name();
        New_index_nameContext *new_index_name();
        antlr4::tree::TerminalNode *ORDER();
        antlr4::tree::TerminalNode *BY();
        Column_name_listContext *column_name_list();
        antlr4::tree::TerminalNode *CONVERT();
        CharsetContext *charset();
        CollationContext *collation();
        antlr4::tree::TerminalNode *DISCARD();
        antlr4::tree::TerminalNode *TABLESPACE();
        antlr4::tree::TerminalNode *IMPORT();
        antlr4::tree::TerminalNode *FORCE();
        antlr4::tree::TerminalNode *VALIDATION();
        antlr4::tree::TerminalNode *WITHOUT();
        std::vector<antlr4::tree::TerminalNode *> WITH();
        antlr4::tree::TerminalNode *WITH(size_t i);
        antlr4::tree::TerminalNode *PARTITION();
        antlr4::tree::TerminalNode *LPAREN();
        Partition_definitionContext *partition_definition();
        antlr4::tree::TerminalNode *RPAREN();
        Partition_name_listContext *partition_name_list();
        antlr4::tree::TerminalNode *ALL();
        antlr4::tree::TerminalNode *TRUNCATE();
        antlr4::tree::TerminalNode *COALESCE();
        Partition_numberContext *partition_number();
        antlr4::tree::TerminalNode *REORGANIZE();
        antlr4::tree::TerminalNode *INTO();
        Partition_definition_listContext *partition_definition_list();
        antlr4::tree::TerminalNode *EXCHANGE();
        Partition_nameContext *partition_name();
        antlr4::tree::TerminalNode *TABLE();
        Table_nameContext *table_name();
        antlr4::tree::TerminalNode *ANALYZE();
        antlr4::tree::TerminalNode *CHECK();
        antlr4::tree::TerminalNode *OPTIMIZE();
        antlr4::tree::TerminalNode *REBUILD();
        antlr4::tree::TerminalNode *REPAIR();
        antlr4::tree::TerminalNode *REMOVE();
        antlr4::tree::TerminalNode *PARTITIONING();
        antlr4::tree::TerminalNode *UPGRADE();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Alter_specificationContext *alter_specification();

    class Alter_specification_listContext : public antlr4::ParserRuleContext
    {
    public:
        Alter_specification_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        std::vector<Alter_specificationContext *> alter_specification();
        Alter_specificationContext *alter_specification(size_t i);
        std::vector<antlr4::tree::TerminalNode *> COMMA();
        antlr4::tree::TerminalNode *COMMA(size_t i);

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Alter_specification_listContext *alter_specification_list();

    class Column_name_listContext : public antlr4::ParserRuleContext
    {
    public:
        Column_name_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        std::vector<Column_nameContext *> column_name();
        Column_nameContext *column_name(size_t i);
        std::vector<antlr4::tree::TerminalNode *> COMMA();
        antlr4::tree::TerminalNode *COMMA(size_t i);

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Column_name_listContext *column_name_list();

    class Partition_name_listContext : public antlr4::ParserRuleContext
    {
    public:
        Partition_name_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        std::vector<Partition_nameContext *> partition_name();
        Partition_nameContext *partition_name(size_t i);
        std::vector<antlr4::tree::TerminalNode *> COMMA();
        antlr4::tree::TerminalNode *COMMA(size_t i);

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Partition_name_listContext *partition_name_list();

    class Column_definition_listContext : public antlr4::ParserRuleContext
    {
    public:
        Column_definition_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *LPAREN();
        std::vector<Column_nameContext *> column_name();
        Column_nameContext *column_name(size_t i);
        std::vector<Column_definitionContext *> column_definition();
        Column_definitionContext *column_definition(size_t i);
        antlr4::tree::TerminalNode *RPAREN();
        std::vector<antlr4::tree::TerminalNode *> COMMA();
        antlr4::tree::TerminalNode *COMMA(size_t i);

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Column_definition_listContext *column_definition_list();

    class Table_algorithmContext : public antlr4::ParserRuleContext
    {
    public:
        Table_algorithmContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *DEFAULT();
        antlr4::tree::TerminalNode *INPLACE();
        antlr4::tree::TerminalNode *COPY();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Table_algorithmContext *table_algorithm();

    class Table_lockContext : public antlr4::ParserRuleContext
    {
    public:
        Table_lockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *DEFAULT();
        antlr4::tree::TerminalNode *NONE();
        antlr4::tree::TerminalNode *SHARED();
        antlr4::tree::TerminalNode *EXCLUSIVE();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Table_lockContext *table_lock();

    class First_afterContext : public antlr4::ParserRuleContext
    {
    public:
        First_afterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode *FIRST();
        antlr4::tree::TerminalNode *AFTER();
        Column_nameContext *column_name();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    First_afterContext *first_after();

    class Fk_symbolContext : public antlr4::ParserRuleContext
    {
    public:
        Fk_symbolContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        SymbolContext *symbol();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Fk_symbolContext *fk_symbol();

    class New_table_nameContext : public antlr4::ParserRuleContext
    {
    public:
        New_table_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        Table_nameContext *table_name();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    New_table_nameContext *new_table_name();

    class Old_column_nameContext : public antlr4::ParserRuleContext
    {
    public:
        Old_column_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        Column_nameContext *column_name();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Old_column_nameContext *old_column_name();

    class New_column_nameContext : public antlr4::ParserRuleContext
    {
    public:
        New_column_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        Column_nameContext *column_name();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    New_column_nameContext *new_column_name();

    class Old_index_nameContext : public antlr4::ParserRuleContext
    {
    public:
        Old_index_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        Index_nameContext *index_name();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Old_index_nameContext *old_index_name();

    class New_index_nameContext : public antlr4::ParserRuleContext
    {
    public:
        New_index_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        Index_nameContext *index_name();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    New_index_nameContext *new_index_name();

    class Partition_numberContext : public antlr4::ParserRuleContext
    {
    public:
        Partition_numberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        Integer_literalContext *integer_literal();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
    };

    Partition_numberContext *partition_number();

private:
    static std::vector<antlr4::dfa::DFA> _decisionToDFA;
    static antlr4::atn::PredictionContextCache _sharedContextCache;
    static std::vector<std::string> _ruleNames;
    static std::vector<std::string> _tokenNames;

    static std::vector<std::string> _literalNames;
    static std::vector<std::string> _symbolicNames;
    static antlr4::dfa::Vocabulary _vocabulary;
    static antlr4::atn::ATN _atn;
    static std::vector<uint16_t> _serializedATN;

    struct Initializer
    {
        Initializer();
    };
    static Initializer _init;
};

} // namespace mysql

#define NULL SAVED_NULL
#define TRUE SAVED_TRUE
#define UNICODE SAVED_UNICODE
