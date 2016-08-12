
// Generated from ./mysql.g4 by ANTLR 4.5.3

#pragma once

#include "antlr4-runtime.h"

#define SAVED_NULL NULL
#undef NULL
#define SAVED_UNICODE UNICODE
#undef UNICODE

using namespace antlr4;

namespace mysql
{

class mysqlParser : public Parser
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
        RuleLess_than_value_list = 28,
        RuleIn_value_list = 29,
        RuleEnum_value_list = 30,
        RuleKey_column_list = 31,
        RuleRange_column_list = 32,
        RuleList_column_list = 33,
        RuleTable_union_list = 34,
        RuleConstraint = 35,
        RuleCharset = 36,
        RuleCollation = 37,
        RuleIndex_structure = 38,
        RuleIndex_column = 39,
        RuleFsp = 40,
        RuleLength = 41,
        RuleDecimals = 42,
        RulePartition_count = 43,
        RuleSubpartition_count = 44,
        RuleAuto_increment = 45,
        RuleAvg_row_length = 46,
        RuleKey_block_size = 47,
        RuleMax_number_of_rows = 48,
        RuleMin_number_of_rows = 49,
        RuleStats_sample_pages = 50,
        RuleChecksum = 51,
        RuleCompression = 52,
        RuleDelay_key_write = 53,
        RuleEncryption = 54,
        RuleInsert_method = 55,
        RulePack_keys = 56,
        RuleRow_format = 57,
        RuleStats_auto_recalc = 58,
        RuleStats_persistent = 59,
        RuleKey_algorithm = 60,
        RuleMatch_option = 61,
        RuleOn_delete_option = 62,
        RuleOn_update_option = 63,
        RuleColumn_format = 64,
        RuleColumn_storage = 65,
        RuleInteger_type = 66,
        RuleReal_type = 67,
        RuleText_type = 68,
        RuleBlob_type = 69,
        RuleSpatial_type = 70,
        RuleEnum_type = 71,
        RuleBinary_type = 72,
        RuleChar_type = 73,
        RuleDatetime_type = 74,
        RuleOn_update_set = 75,
        RuleDefault_value = 76,
        RuleComment = 77,
        RuleConnection = 78,
        RulePassword = 79,
        RuleData_directory = 80,
        RuleIndex_directory = 81,
        RuleAs_expression = 82,
        RuleQuery_expression = 83,
        RuleCheck_expression = 84,
        RuleHash_expression = 85,
        RuleRange_expression = 86,
        RuleList_expression = 87,
        RuleLess_than_expression = 88,
        RuleExpression = 89,
        RuleSymbol = 90,
        RuleEngine_name = 91,
        RuleOld_table_name = 92,
        RuleColumn_name = 93,
        RuleIndex_name = 94,
        RuleTablespace_name = 95,
        RuleTable_name = 96,
        RuleDatabase_name = 97,
        RuleParser_name = 98,
        RuleCharset_name = 99,
        RuleCollation_name = 100,
        RulePartition_name = 101,
        RuleLogical_name = 102,
        RuleLiteral = 103,
        RuleIdentifier = 104,
        RuleBool_literal = 105,
        RuleFloat_literal = 106,
        RuleInteger_literal = 107,
        RuleString_literal = 108,
        RuleDatetime_literal = 109,
        RuleAlter_table = 110,
        RuleAlter_specification = 111,
        RuleAlter_specification_list = 112,
        RuleColumn_name_list = 113,
        RulePartition_name_list = 114,
        RuleColumn_definition_list = 115,
        RuleTable_algorithm = 116,
        RuleTable_lock = 117,
        RuleFirst_after = 118,
        RuleFk_symbol = 119,
        RuleNew_table_name = 120,
        RuleOld_column_name = 121,
        RuleNew_column_name = 122,
        RuleOld_index_name = 123,
        RuleNew_index_name = 124,
        RulePartition_number = 125
    };

    mysqlParser(TokenStream *input);
    ~mysqlParser();

    virtual std::string getGrammarFileName() const override;
    virtual const atn::ATN &getATN() const override
    {
        return _atn;
    };
    virtual const std::vector<std::string> &getTokenNames() const override
    {
        return _tokenNames;
    }; // deprecated: use vocabulary instead.
    virtual const std::vector<std::string> &getRuleNames() const override;
    virtual dfa::Vocabulary &getVocabulary() const override;

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

    class ParseContext : public ParserRuleContext
    {
    public:
        ParseContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> EOF();
        std::vector<Ref<StatementContext>> statement();
        Ref<StatementContext> statement(int i);
        std::vector<Ref<tree::TerminalNode>> SEMI();
        Ref<tree::TerminalNode> SEMI(int i);

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<ParseContext> parse();

    class StatementContext : public ParserRuleContext
    {
    public:
        StatementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<AssignmentContext> assignment();
        Ref<Drop_tableContext> drop_table();
        Ref<Alter_tableContext> alter_table();
        Ref<Create_tableContext> create_table();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<StatementContext> statement();

    class AssignmentContext : public ParserRuleContext
    {
    public:
        AssignmentContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> SET();
        Ref<IdentifierContext> identifier();
        Ref<tree::TerminalNode> EQUAL();
        Ref<LiteralContext> literal();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<AssignmentContext> assignment();

    class Drop_tableContext : public ParserRuleContext
    {
    public:
        Drop_tableContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> DROP();
        Ref<tree::TerminalNode> TABLE();
        Ref<Table_name_listContext> table_name_list();
        Ref<tree::TerminalNode> TEMPORARY();
        Ref<tree::TerminalNode> IF();
        Ref<tree::TerminalNode> EXISTS();
        Ref<tree::TerminalNode> RESTRICT();
        Ref<tree::TerminalNode> CASCADE();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Drop_tableContext> drop_table();

    class Table_name_listContext : public ParserRuleContext
    {
    public:
        Table_name_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        std::vector<Ref<Table_nameContext>> table_name();
        Ref<Table_nameContext> table_name(int i);
        std::vector<Ref<tree::TerminalNode>> COMMA();
        Ref<tree::TerminalNode> COMMA(int i);

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Table_name_listContext> table_name_list();

    class Create_tableContext : public ParserRuleContext
    {
    public:
        Create_tableContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> CREATE();
        Ref<tree::TerminalNode> TABLE();
        Ref<Table_nameContext> table_name();
        Ref<Create_definition_listContext> create_definition_list();
        Ref<tree::TerminalNode> TEMPORARY();
        Ref<tree::TerminalNode> IF();
        Ref<tree::TerminalNode> NOT();
        Ref<tree::TerminalNode> EXISTS();
        Ref<Table_option_listContext> table_option_list();
        Ref<Partition_specificationContext> partition_specification();
        Ref<tree::TerminalNode> LIKE();
        Ref<Old_table_nameContext> old_table_name();
        Ref<tree::TerminalNode> LPAREN();
        Ref<tree::TerminalNode> RPAREN();
        Ref<Query_expressionContext> query_expression();
        Ref<tree::TerminalNode> AS();
        Ref<tree::TerminalNode> IGNORE();
        Ref<tree::TerminalNode> REPLACE();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Create_tableContext> create_table();

    class Create_definitionContext : public ParserRuleContext
    {
    public:
        Create_definitionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<Column_nameContext> column_name();
        Ref<Column_definitionContext> column_definition();
        Ref<Index_definitionContext> index_definition();
        Ref<tree::TerminalNode> CHECK();
        Ref<Check_expressionContext> check_expression();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Create_definitionContext> create_definition();

    class Index_definitionContext : public ParserRuleContext
    {
    public:
        Index_definitionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> PRIMARY();
        Ref<tree::TerminalNode> KEY();
        Ref<Index_column_listContext> index_column_list();
        Ref<Index_option_listContext> index_option_list();
        Ref<ConstraintContext> constraint();
        Ref<Index_structureContext> index_structure();
        Ref<tree::TerminalNode> INDEX();
        Ref<Index_nameContext> index_name();
        Ref<tree::TerminalNode> UNIQUE();
        Ref<tree::TerminalNode> FULLTEXT();
        Ref<tree::TerminalNode> SPATIAL();
        Ref<tree::TerminalNode> FOREIGN();
        Ref<Reference_definitionContext> reference_definition();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Index_definitionContext> index_definition();

    class Column_definitionContext : public ParserRuleContext
    {
    public:
        Column_definitionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<Data_typeContext> data_type();
        Ref<Column_optionsContext> column_options();
        Ref<Reference_definitionContext> reference_definition();
        Ref<Generated_column_optionsContext> generated_column_options();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Column_definitionContext> column_definition();

    class Column_optionsContext : public ParserRuleContext
    {
    public:
        Column_optionsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> NOT();
        Ref<tree::TerminalNode> NULL();
        Ref<tree::TerminalNode> DEFAULT();
        Ref<Default_valueContext> default_value();
        Ref<tree::TerminalNode> AUTO_INCREMENT();
        Ref<tree::TerminalNode> UNIQUE();
        Ref<tree::TerminalNode> KEY();
        Ref<tree::TerminalNode> COMMENT();
        Ref<CommentContext> comment();
        Ref<tree::TerminalNode> COLUMN_FORMAT();
        Ref<Column_formatContext> column_format();
        Ref<tree::TerminalNode> STORAGE();
        Ref<Column_storageContext> column_storage();
        Ref<tree::TerminalNode> ON();
        Ref<tree::TerminalNode> UPDATE();
        Ref<On_update_setContext> on_update_set();
        Ref<tree::TerminalNode> PRIMARY();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Column_optionsContext> column_options();

    class Generated_column_optionsContext : public ParserRuleContext
    {
    public:
        Generated_column_optionsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> AS();
        Ref<As_expressionContext> as_expression();
        Ref<tree::TerminalNode> GENERATED();
        Ref<tree::TerminalNode> ALWAYS();
        Ref<tree::TerminalNode> UNIQUE();
        Ref<tree::TerminalNode> COMMENT();
        Ref<CommentContext> comment();
        Ref<tree::TerminalNode> NOT();
        Ref<tree::TerminalNode> NULL();
        std::vector<Ref<tree::TerminalNode>> KEY();
        Ref<tree::TerminalNode> KEY(int i);
        Ref<tree::TerminalNode> VIRTUAL();
        Ref<tree::TerminalNode> STORED();
        Ref<tree::TerminalNode> PRIMARY();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Generated_column_optionsContext> generated_column_options();

    class Data_typeContext : public ParserRuleContext
    {
    public:
        Data_typeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<Integer_typeContext> integer_type();
        Ref<tree::TerminalNode> LPAREN();
        Ref<LengthContext> length();
        Ref<tree::TerminalNode> RPAREN();
        Ref<tree::TerminalNode> UNSIGNED();
        Ref<tree::TerminalNode> ZEROFILL();
        Ref<Real_typeContext> real_type();
        Ref<tree::TerminalNode> COMMA();
        Ref<DecimalsContext> decimals();
        Ref<Datetime_typeContext> datetime_type();
        Ref<FspContext> fsp();
        Ref<Char_typeContext> char_type();
        Ref<tree::TerminalNode> BINARY();
        Ref<CharsetContext> charset();
        Ref<CollationContext> collation();
        Ref<Binary_typeContext> binary_type();
        Ref<Blob_typeContext> blob_type();
        Ref<Text_typeContext> text_type();
        Ref<Enum_typeContext> enum_type();
        Ref<Enum_value_listContext> enum_value_list();
        Ref<Spatial_typeContext> spatial_type();
        Ref<tree::TerminalNode> JSON();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Data_typeContext> data_type();

    class Table_optionContext : public ParserRuleContext
    {
    public:
        Table_optionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> ENGINE();
        Ref<Engine_nameContext> engine_name();
        Ref<tree::TerminalNode> EQUAL();
        Ref<tree::TerminalNode> AUTO_INCREMENT();
        Ref<Auto_incrementContext> auto_increment();
        Ref<tree::TerminalNode> AVG_ROW_LENGTH();
        Ref<Avg_row_lengthContext> avg_row_length();
        Ref<CharsetContext> charset();
        Ref<tree::TerminalNode> DEFAULT();
        Ref<tree::TerminalNode> CHECKSUM();
        Ref<ChecksumContext> checksum();
        Ref<CollationContext> collation();
        Ref<tree::TerminalNode> COMMENT();
        Ref<CommentContext> comment();
        Ref<tree::TerminalNode> COMPRESSION();
        Ref<CompressionContext> compression();
        Ref<tree::TerminalNode> CONNECTION();
        Ref<ConnectionContext> connection();
        Ref<tree::TerminalNode> DATA();
        Ref<tree::TerminalNode> DIRECTORY();
        Ref<Data_directoryContext> data_directory();
        Ref<tree::TerminalNode> DELAY_KEY_WRITE();
        Ref<Delay_key_writeContext> delay_key_write();
        Ref<tree::TerminalNode> ENCRYPTION();
        Ref<EncryptionContext> encryption();
        Ref<tree::TerminalNode> INDEX();
        Ref<Index_directoryContext> index_directory();
        Ref<tree::TerminalNode> INSERT_METHOD();
        Ref<Insert_methodContext> insert_method();
        Ref<tree::TerminalNode> KEY_BLOCK_SIZE();
        Ref<Key_block_sizeContext> key_block_size();
        Ref<tree::TerminalNode> MAX_ROWS();
        Ref<Max_number_of_rowsContext> max_number_of_rows();
        Ref<tree::TerminalNode> MIN_ROWS();
        Ref<Min_number_of_rowsContext> min_number_of_rows();
        Ref<tree::TerminalNode> PACK_KEYS();
        Ref<Pack_keysContext> pack_keys();
        Ref<tree::TerminalNode> PASSWORD();
        Ref<PasswordContext> password();
        Ref<tree::TerminalNode> ROW_FORMAT();
        Ref<Row_formatContext> row_format();
        Ref<tree::TerminalNode> STATS_AUTO_RECALC();
        Ref<Stats_auto_recalcContext> stats_auto_recalc();
        Ref<tree::TerminalNode> STATS_PERSISTENT();
        Ref<Stats_persistentContext> stats_persistent();
        Ref<tree::TerminalNode> STATS_SAMPLE_PAGES();
        Ref<Stats_sample_pagesContext> stats_sample_pages();
        Ref<tree::TerminalNode> TABLESPACE();
        Ref<Tablespace_nameContext> tablespace_name();
        Ref<tree::TerminalNode> UNION();
        Ref<Table_union_listContext> table_union_list();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Table_optionContext> table_option();

    class Partition_specificationContext : public ParserRuleContext
    {
    public:
        Partition_specificationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> PARTITION();
        std::vector<Ref<tree::TerminalNode>> BY();
        Ref<tree::TerminalNode> BY(int i);
        Ref<Partition_byContext> partition_by();
        Ref<tree::TerminalNode> PARTITIONS();
        Ref<Partition_countContext> partition_count();
        Ref<tree::TerminalNode> SUBPARTITION();
        Ref<Subpartition_byContext> subpartition_by();
        Ref<Partition_definition_listContext> partition_definition_list();
        Ref<tree::TerminalNode> SUBPARTITIONS();
        Ref<Subpartition_countContext> subpartition_count();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Partition_specificationContext> partition_specification();

    class Partition_definition_listContext : public ParserRuleContext
    {
    public:
        Partition_definition_listContext(
            std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> LPAREN();
        std::vector<Ref<Partition_definitionContext>> partition_definition();
        Ref<Partition_definitionContext> partition_definition(int i);
        Ref<tree::TerminalNode> RPAREN();
        std::vector<Ref<tree::TerminalNode>> COMMA();
        Ref<tree::TerminalNode> COMMA(int i);

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Partition_definition_listContext> partition_definition_list();

    class Partition_byContext : public ParserRuleContext
    {
    public:
        Partition_byContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> HASH();
        Ref<Hash_expressionContext> hash_expression();
        Ref<tree::TerminalNode> LINEAR();
        Ref<tree::TerminalNode> KEY();
        Ref<Key_column_listContext> key_column_list();
        Ref<tree::TerminalNode> ALGORITHM();
        Ref<tree::TerminalNode> EQUAL();
        Ref<Key_algorithmContext> key_algorithm();
        Ref<tree::TerminalNode> RANGE();
        Ref<Range_expressionContext> range_expression();
        Ref<tree::TerminalNode> COLUMNS();
        Ref<Range_column_listContext> range_column_list();
        Ref<tree::TerminalNode> LIST();
        Ref<List_expressionContext> list_expression();
        Ref<List_column_listContext> list_column_list();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Partition_byContext> partition_by();

    class Subpartition_byContext : public ParserRuleContext
    {
    public:
        Subpartition_byContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> HASH();
        Ref<Hash_expressionContext> hash_expression();
        Ref<tree::TerminalNode> LINEAR();
        Ref<tree::TerminalNode> KEY();
        Ref<Key_column_listContext> key_column_list();
        Ref<tree::TerminalNode> ALGORITHM();
        Ref<tree::TerminalNode> EQUAL();
        Ref<Key_algorithmContext> key_algorithm();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Subpartition_byContext> subpartition_by();

    class Partition_definitionContext : public ParserRuleContext
    {
    public:
        Partition_definitionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> PARTITION();
        Ref<Partition_nameContext> partition_name();
        Ref<Partition_optionsContext> partition_options();
        Ref<Partition_valuesContext> partition_values();
        Ref<Subpartition_definition_listContext> subpartition_definition_list();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Partition_definitionContext> partition_definition();

    class Subpartition_definition_listContext : public ParserRuleContext
    {
    public:
        Subpartition_definition_listContext(
            std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> LPAREN();
        std::vector<Ref<Subpartition_definitionContext>> subpartition_definition();
        Ref<Subpartition_definitionContext> subpartition_definition(int i);
        Ref<tree::TerminalNode> RPAREN();
        std::vector<Ref<tree::TerminalNode>> COMMA();
        Ref<tree::TerminalNode> COMMA(int i);

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Subpartition_definition_listContext> subpartition_definition_list();

    class Partition_valuesContext : public ParserRuleContext
    {
    public:
        Partition_valuesContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> VALUES();
        Ref<tree::TerminalNode> LESS();
        Ref<tree::TerminalNode> THAN();
        Ref<tree::TerminalNode> IN();
        Ref<In_value_listContext> in_value_list();
        Ref<Less_than_expressionContext> less_than_expression();
        Ref<Less_than_value_listContext> less_than_value_list();
        Ref<tree::TerminalNode> MAXVALUE();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Partition_valuesContext> partition_values();

    class Subpartition_definitionContext : public ParserRuleContext
    {
    public:
        Subpartition_definitionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> SUBPARTITION();
        Ref<Logical_nameContext> logical_name();
        Ref<Partition_optionsContext> partition_options();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Subpartition_definitionContext> subpartition_definition();

    class Partition_optionsContext : public ParserRuleContext
    {
    public:
        Partition_optionsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> ENGINE();
        Ref<Engine_nameContext> engine_name();
        Ref<tree::TerminalNode> COMMENT();
        Ref<CommentContext> comment();
        Ref<tree::TerminalNode> DATA();
        std::vector<Ref<tree::TerminalNode>> DIRECTORY();
        Ref<tree::TerminalNode> DIRECTORY(int i);
        Ref<Data_directoryContext> data_directory();
        Ref<tree::TerminalNode> INDEX();
        Ref<Index_directoryContext> index_directory();
        Ref<tree::TerminalNode> MAX_ROWS();
        Ref<Max_number_of_rowsContext> max_number_of_rows();
        Ref<tree::TerminalNode> MIN_ROWS();
        Ref<Min_number_of_rowsContext> min_number_of_rows();
        Ref<tree::TerminalNode> TABLESPACE();
        Ref<Tablespace_nameContext> tablespace_name();
        Ref<tree::TerminalNode> STORAGE();
        std::vector<Ref<tree::TerminalNode>> EQUAL();
        Ref<tree::TerminalNode> EQUAL(int i);

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Partition_optionsContext> partition_options();

    class Index_optionContext : public ParserRuleContext
    {
    public:
        Index_optionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> KEY_BLOCK_SIZE();
        Ref<Key_block_sizeContext> key_block_size();
        Ref<tree::TerminalNode> EQUAL();
        Ref<tree::TerminalNode> USING();
        Ref<Index_structureContext> index_structure();
        Ref<tree::TerminalNode> WITH();
        Ref<tree::TerminalNode> PARSER();
        Ref<Parser_nameContext> parser_name();
        Ref<tree::TerminalNode> COMMENT();
        Ref<CommentContext> comment();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Index_optionContext> index_option();

    class Reference_definitionContext : public ParserRuleContext
    {
    public:
        Reference_definitionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> REFERENCES();
        Ref<Table_nameContext> table_name();
        Ref<Index_column_listContext> index_column_list();
        Ref<tree::TerminalNode> MATCH();
        Ref<Match_optionContext> match_option();
        std::vector<Ref<tree::TerminalNode>> ON();
        Ref<tree::TerminalNode> ON(int i);
        Ref<tree::TerminalNode> DELETE();
        Ref<On_delete_optionContext> on_delete_option();
        Ref<tree::TerminalNode> UPDATE();
        Ref<On_update_optionContext> on_update_option();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Reference_definitionContext> reference_definition();

    class Create_definition_listContext : public ParserRuleContext
    {
    public:
        Create_definition_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> LPAREN();
        std::vector<Ref<Create_definitionContext>> create_definition();
        Ref<Create_definitionContext> create_definition(int i);
        Ref<tree::TerminalNode> RPAREN();
        std::vector<Ref<tree::TerminalNode>> COMMA();
        Ref<tree::TerminalNode> COMMA(int i);

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Create_definition_listContext> create_definition_list();

    class Table_option_listContext : public ParserRuleContext
    {
    public:
        Table_option_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        std::vector<Ref<Table_optionContext>> table_option();
        Ref<Table_optionContext> table_option(int i);
        std::vector<Ref<tree::TerminalNode>> COMMA();
        Ref<tree::TerminalNode> COMMA(int i);

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Table_option_listContext> table_option_list();

    class Index_option_listContext : public ParserRuleContext
    {
    public:
        Index_option_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        std::vector<Ref<Index_optionContext>> index_option();
        Ref<Index_optionContext> index_option(int i);

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Index_option_listContext> index_option_list();

    class Index_column_listContext : public ParserRuleContext
    {
    public:
        Index_column_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> LPAREN();
        std::vector<Ref<Index_columnContext>> index_column();
        Ref<Index_columnContext> index_column(int i);
        Ref<tree::TerminalNode> RPAREN();
        std::vector<Ref<tree::TerminalNode>> COMMA();
        Ref<tree::TerminalNode> COMMA(int i);

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Index_column_listContext> index_column_list();

    class Less_than_value_listContext : public ParserRuleContext
    {
    public:
        Less_than_value_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> LPAREN();
        std::vector<Ref<LiteralContext>> literal();
        Ref<LiteralContext> literal(int i);
        Ref<tree::TerminalNode> RPAREN();
        std::vector<Ref<tree::TerminalNode>> COMMA();
        Ref<tree::TerminalNode> COMMA(int i);

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Less_than_value_listContext> less_than_value_list();

    class In_value_listContext : public ParserRuleContext
    {
    public:
        In_value_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> LPAREN();
        std::vector<Ref<LiteralContext>> literal();
        Ref<LiteralContext> literal(int i);
        Ref<tree::TerminalNode> RPAREN();
        std::vector<Ref<tree::TerminalNode>> COMMA();
        Ref<tree::TerminalNode> COMMA(int i);

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<In_value_listContext> in_value_list();

    class Enum_value_listContext : public ParserRuleContext
    {
    public:
        Enum_value_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> LPAREN();
        std::vector<Ref<LiteralContext>> literal();
        Ref<LiteralContext> literal(int i);
        Ref<tree::TerminalNode> RPAREN();
        std::vector<Ref<tree::TerminalNode>> COMMA();
        Ref<tree::TerminalNode> COMMA(int i);

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Enum_value_listContext> enum_value_list();

    class Key_column_listContext : public ParserRuleContext
    {
    public:
        Key_column_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> LPAREN();
        std::vector<Ref<IdentifierContext>> identifier();
        Ref<IdentifierContext> identifier(int i);
        Ref<tree::TerminalNode> RPAREN();
        std::vector<Ref<tree::TerminalNode>> COMMA();
        Ref<tree::TerminalNode> COMMA(int i);

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Key_column_listContext> key_column_list();

    class Range_column_listContext : public ParserRuleContext
    {
    public:
        Range_column_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> LPAREN();
        std::vector<Ref<IdentifierContext>> identifier();
        Ref<IdentifierContext> identifier(int i);
        Ref<tree::TerminalNode> RPAREN();
        std::vector<Ref<tree::TerminalNode>> COMMA();
        Ref<tree::TerminalNode> COMMA(int i);

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Range_column_listContext> range_column_list();

    class List_column_listContext : public ParserRuleContext
    {
    public:
        List_column_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> LPAREN();
        std::vector<Ref<IdentifierContext>> identifier();
        Ref<IdentifierContext> identifier(int i);
        Ref<tree::TerminalNode> RPAREN();
        std::vector<Ref<tree::TerminalNode>> COMMA();
        Ref<tree::TerminalNode> COMMA(int i);

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<List_column_listContext> list_column_list();

    class Table_union_listContext : public ParserRuleContext
    {
    public:
        Table_union_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> LPAREN();
        std::vector<Ref<Table_nameContext>> table_name();
        Ref<Table_nameContext> table_name(int i);
        Ref<tree::TerminalNode> RPAREN();
        std::vector<Ref<tree::TerminalNode>> COMMA();
        Ref<tree::TerminalNode> COMMA(int i);

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Table_union_listContext> table_union_list();

    class ConstraintContext : public ParserRuleContext
    {
    public:
        ConstraintContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> CONSTRAINT();
        Ref<SymbolContext> symbol();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<ConstraintContext> constraint();

    class CharsetContext : public ParserRuleContext
    {
    public:
        CharsetContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> CHARACTER();
        Ref<tree::TerminalNode> SET();
        Ref<Charset_nameContext> charset_name();
        Ref<tree::TerminalNode> EQUAL();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<CharsetContext> charset();

    class CollationContext : public ParserRuleContext
    {
    public:
        CollationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> COLLATE();
        Ref<Collation_nameContext> collation_name();
        Ref<tree::TerminalNode> EQUAL();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<CollationContext> collation();

    class Index_structureContext : public ParserRuleContext
    {
    public:
        Index_structureContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> BTREE();
        Ref<tree::TerminalNode> HASH();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Index_structureContext> index_structure();

    class Index_columnContext : public ParserRuleContext
    {
    public:
        Index_columnContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<Column_nameContext> column_name();
        Ref<tree::TerminalNode> LPAREN();
        Ref<LengthContext> length();
        Ref<tree::TerminalNode> RPAREN();
        Ref<tree::TerminalNode> ASC();
        Ref<tree::TerminalNode> DESC();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Index_columnContext> index_column();

    class FspContext : public ParserRuleContext
    {
    public:
        FspContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<Integer_literalContext> integer_literal();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<FspContext> fsp();

    class LengthContext : public ParserRuleContext
    {
    public:
        LengthContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<Integer_literalContext> integer_literal();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<LengthContext> length();

    class DecimalsContext : public ParserRuleContext
    {
    public:
        DecimalsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<Integer_literalContext> integer_literal();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<DecimalsContext> decimals();

    class Partition_countContext : public ParserRuleContext
    {
    public:
        Partition_countContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<Integer_literalContext> integer_literal();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Partition_countContext> partition_count();

    class Subpartition_countContext : public ParserRuleContext
    {
    public:
        Subpartition_countContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<Integer_literalContext> integer_literal();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Subpartition_countContext> subpartition_count();

    class Auto_incrementContext : public ParserRuleContext
    {
    public:
        Auto_incrementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<Integer_literalContext> integer_literal();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Auto_incrementContext> auto_increment();

    class Avg_row_lengthContext : public ParserRuleContext
    {
    public:
        Avg_row_lengthContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<Integer_literalContext> integer_literal();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Avg_row_lengthContext> avg_row_length();

    class Key_block_sizeContext : public ParserRuleContext
    {
    public:
        Key_block_sizeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<Integer_literalContext> integer_literal();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Key_block_sizeContext> key_block_size();

    class Max_number_of_rowsContext : public ParserRuleContext
    {
    public:
        Max_number_of_rowsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<Integer_literalContext> integer_literal();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Max_number_of_rowsContext> max_number_of_rows();

    class Min_number_of_rowsContext : public ParserRuleContext
    {
    public:
        Min_number_of_rowsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<Integer_literalContext> integer_literal();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Min_number_of_rowsContext> min_number_of_rows();

    class Stats_sample_pagesContext : public ParserRuleContext
    {
    public:
        Stats_sample_pagesContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<Integer_literalContext> integer_literal();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Stats_sample_pagesContext> stats_sample_pages();

    class ChecksumContext : public ParserRuleContext
    {
    public:
        ChecksumContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<Integer_literalContext> integer_literal();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<ChecksumContext> checksum();

    class CompressionContext : public ParserRuleContext
    {
    public:
        CompressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<String_literalContext> string_literal();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<CompressionContext> compression();

    class Delay_key_writeContext : public ParserRuleContext
    {
    public:
        Delay_key_writeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<Integer_literalContext> integer_literal();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Delay_key_writeContext> delay_key_write();

    class EncryptionContext : public ParserRuleContext
    {
    public:
        EncryptionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<String_literalContext> string_literal();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<EncryptionContext> encryption();

    class Insert_methodContext : public ParserRuleContext
    {
    public:
        Insert_methodContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> NO();
        Ref<tree::TerminalNode> FIRST();
        Ref<tree::TerminalNode> LAST();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Insert_methodContext> insert_method();

    class Pack_keysContext : public ParserRuleContext
    {
    public:
        Pack_keysContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<Integer_literalContext> integer_literal();
        Ref<tree::TerminalNode> DEFAULT();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Pack_keysContext> pack_keys();

    class Row_formatContext : public ParserRuleContext
    {
    public:
        Row_formatContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> DEFAULT();
        Ref<tree::TerminalNode> DYNAMIC();
        Ref<tree::TerminalNode> FIXED();
        Ref<tree::TerminalNode> COMPRESSED();
        Ref<tree::TerminalNode> REDUNDANT();
        Ref<tree::TerminalNode> COMPACT();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Row_formatContext> row_format();

    class Stats_auto_recalcContext : public ParserRuleContext
    {
    public:
        Stats_auto_recalcContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> DEFAULT();
        Ref<Integer_literalContext> integer_literal();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Stats_auto_recalcContext> stats_auto_recalc();

    class Stats_persistentContext : public ParserRuleContext
    {
    public:
        Stats_persistentContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> DEFAULT();
        Ref<Integer_literalContext> integer_literal();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Stats_persistentContext> stats_persistent();

    class Key_algorithmContext : public ParserRuleContext
    {
    public:
        Key_algorithmContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<Integer_literalContext> integer_literal();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Key_algorithmContext> key_algorithm();

    class Match_optionContext : public ParserRuleContext
    {
    public:
        Match_optionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> FULL();
        Ref<tree::TerminalNode> PARTIAL();
        Ref<tree::TerminalNode> SIMPLE();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Match_optionContext> match_option();

    class On_delete_optionContext : public ParserRuleContext
    {
    public:
        On_delete_optionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> RESTRICT();
        Ref<tree::TerminalNode> CASCADE();
        Ref<tree::TerminalNode> SET();
        Ref<tree::TerminalNode> NULL();
        Ref<tree::TerminalNode> NO();
        Ref<tree::TerminalNode> ACTION();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<On_delete_optionContext> on_delete_option();

    class On_update_optionContext : public ParserRuleContext
    {
    public:
        On_update_optionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> RESTRICT();
        Ref<tree::TerminalNode> CASCADE();
        Ref<tree::TerminalNode> SET();
        Ref<tree::TerminalNode> NULL();
        Ref<tree::TerminalNode> NO();
        Ref<tree::TerminalNode> ACTION();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<On_update_optionContext> on_update_option();

    class Column_formatContext : public ParserRuleContext
    {
    public:
        Column_formatContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> FIXED();
        Ref<tree::TerminalNode> DYNAMIC();
        Ref<tree::TerminalNode> DEFAULT();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Column_formatContext> column_format();

    class Column_storageContext : public ParserRuleContext
    {
    public:
        Column_storageContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> DISK();
        Ref<tree::TerminalNode> MEMORY();
        Ref<tree::TerminalNode> DEFAULT();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Column_storageContext> column_storage();

    class Integer_typeContext : public ParserRuleContext
    {
    public:
        Integer_typeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> TINYINT();
        Ref<tree::TerminalNode> SMALLINT();
        Ref<tree::TerminalNode> MEDIUMINT();
        Ref<tree::TerminalNode> INT();
        Ref<tree::TerminalNode> INTEGER();
        Ref<tree::TerminalNode> BIGINT();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Integer_typeContext> integer_type();

    class Real_typeContext : public ParserRuleContext
    {
    public:
        Real_typeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> REAL();
        Ref<tree::TerminalNode> DOUBLE();
        Ref<tree::TerminalNode> FLOAT();
        Ref<tree::TerminalNode> DECIMAL();
        Ref<tree::TerminalNode> NUMERIC();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Real_typeContext> real_type();

    class Text_typeContext : public ParserRuleContext
    {
    public:
        Text_typeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> TINYTEXT();
        Ref<tree::TerminalNode> TEXT();
        Ref<tree::TerminalNode> MEDIUMTEXT();
        Ref<tree::TerminalNode> LONGTEXT();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Text_typeContext> text_type();

    class Blob_typeContext : public ParserRuleContext
    {
    public:
        Blob_typeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> TINYBLOB();
        Ref<tree::TerminalNode> BLOB();
        Ref<tree::TerminalNode> MEDIUMBLOB();
        Ref<tree::TerminalNode> LONGBLOB();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Blob_typeContext> blob_type();

    class Spatial_typeContext : public ParserRuleContext
    {
    public:
        Spatial_typeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> GEOMETRY();
        Ref<tree::TerminalNode> POINT();
        Ref<tree::TerminalNode> LINESTRING();
        Ref<tree::TerminalNode> POLYGON();
        Ref<tree::TerminalNode> MULTIPOINT();
        Ref<tree::TerminalNode> MULTILINESTRING();
        Ref<tree::TerminalNode> MULTIPOLYGON();
        Ref<tree::TerminalNode> GEOMETRYCOLLECTION();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Spatial_typeContext> spatial_type();

    class Enum_typeContext : public ParserRuleContext
    {
    public:
        Enum_typeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> ENUM();
        Ref<tree::TerminalNode> SET();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Enum_typeContext> enum_type();

    class Binary_typeContext : public ParserRuleContext
    {
    public:
        Binary_typeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> BIT();
        Ref<tree::TerminalNode> BINARY();
        Ref<tree::TerminalNode> VARBINARY();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Binary_typeContext> binary_type();

    class Char_typeContext : public ParserRuleContext
    {
    public:
        Char_typeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> CHAR();
        Ref<tree::TerminalNode> VARCHAR();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Char_typeContext> char_type();

    class Datetime_typeContext : public ParserRuleContext
    {
    public:
        Datetime_typeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> DATE();
        Ref<tree::TerminalNode> TIME();
        Ref<tree::TerminalNode> TIMESTAMP();
        Ref<tree::TerminalNode> DATETIME();
        Ref<tree::TerminalNode> YEAR();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Datetime_typeContext> datetime_type();

    class On_update_setContext : public ParserRuleContext
    {
    public:
        On_update_setContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<LiteralContext> literal();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<On_update_setContext> on_update_set();

    class Default_valueContext : public ParserRuleContext
    {
    public:
        Default_valueContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<LiteralContext> literal();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Default_valueContext> default_value();

    class CommentContext : public ParserRuleContext
    {
    public:
        CommentContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<String_literalContext> string_literal();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<CommentContext> comment();

    class ConnectionContext : public ParserRuleContext
    {
    public:
        ConnectionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<String_literalContext> string_literal();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<ConnectionContext> connection();

    class PasswordContext : public ParserRuleContext
    {
    public:
        PasswordContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<String_literalContext> string_literal();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<PasswordContext> password();

    class Data_directoryContext : public ParserRuleContext
    {
    public:
        Data_directoryContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<String_literalContext> string_literal();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Data_directoryContext> data_directory();

    class Index_directoryContext : public ParserRuleContext
    {
    public:
        Index_directoryContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<String_literalContext> string_literal();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Index_directoryContext> index_directory();

    class As_expressionContext : public ParserRuleContext
    {
    public:
        As_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<ExpressionContext> expression();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<As_expressionContext> as_expression();

    class Query_expressionContext : public ParserRuleContext
    {
    public:
        Query_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<ExpressionContext> expression();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Query_expressionContext> query_expression();

    class Check_expressionContext : public ParserRuleContext
    {
    public:
        Check_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<ExpressionContext> expression();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Check_expressionContext> check_expression();

    class Hash_expressionContext : public ParserRuleContext
    {
    public:
        Hash_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<ExpressionContext> expression();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Hash_expressionContext> hash_expression();

    class Range_expressionContext : public ParserRuleContext
    {
    public:
        Range_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<ExpressionContext> expression();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Range_expressionContext> range_expression();

    class List_expressionContext : public ParserRuleContext
    {
    public:
        List_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<ExpressionContext> expression();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<List_expressionContext> list_expression();

    class Less_than_expressionContext : public ParserRuleContext
    {
    public:
        Less_than_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<ExpressionContext> expression();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Less_than_expressionContext> less_than_expression();

    class ExpressionContext : public ParserRuleContext
    {
    public:
        ExpressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> LPAREN();
        Ref<LiteralContext> literal();
        Ref<tree::TerminalNode> RPAREN();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<ExpressionContext> expression();

    class SymbolContext : public ParserRuleContext
    {
    public:
        SymbolContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<IdentifierContext> identifier();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<SymbolContext> symbol();

    class Engine_nameContext : public ParserRuleContext
    {
    public:
        Engine_nameContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<IdentifierContext> identifier();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Engine_nameContext> engine_name();

    class Old_table_nameContext : public ParserRuleContext
    {
    public:
        Old_table_nameContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<Table_nameContext> table_name();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Old_table_nameContext> old_table_name();

    class Column_nameContext : public ParserRuleContext
    {
    public:
        Column_nameContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<IdentifierContext> identifier();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Column_nameContext> column_name();

    class Index_nameContext : public ParserRuleContext
    {
    public:
        Index_nameContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<IdentifierContext> identifier();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Index_nameContext> index_name();

    class Tablespace_nameContext : public ParserRuleContext
    {
    public:
        Tablespace_nameContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<IdentifierContext> identifier();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Tablespace_nameContext> tablespace_name();

    class Table_nameContext : public ParserRuleContext
    {
    public:
        Table_nameContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<IdentifierContext> identifier();
        Ref<Database_nameContext> database_name();
        Ref<tree::TerminalNode> PERIOD();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Table_nameContext> table_name();

    class Database_nameContext : public ParserRuleContext
    {
    public:
        Database_nameContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<IdentifierContext> identifier();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Database_nameContext> database_name();

    class Parser_nameContext : public ParserRuleContext
    {
    public:
        Parser_nameContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<IdentifierContext> identifier();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Parser_nameContext> parser_name();

    class Charset_nameContext : public ParserRuleContext
    {
    public:
        Charset_nameContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<IdentifierContext> identifier();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Charset_nameContext> charset_name();

    class Collation_nameContext : public ParserRuleContext
    {
    public:
        Collation_nameContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<IdentifierContext> identifier();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Collation_nameContext> collation_name();

    class Partition_nameContext : public ParserRuleContext
    {
    public:
        Partition_nameContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<IdentifierContext> identifier();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Partition_nameContext> partition_name();

    class Logical_nameContext : public ParserRuleContext
    {
    public:
        Logical_nameContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<IdentifierContext> identifier();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Logical_nameContext> logical_name();

    class LiteralContext : public ParserRuleContext
    {
    public:
        LiteralContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> NULL();
        Ref<Bool_literalContext> bool_literal();
        Ref<Float_literalContext> float_literal();
        Ref<Integer_literalContext> integer_literal();
        Ref<String_literalContext> string_literal();
        Ref<Datetime_literalContext> datetime_literal();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<LiteralContext> literal();

    class IdentifierContext : public ParserRuleContext
    {
    public:
        IdentifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> ID();
        Ref<tree::TerminalNode> BQUOTED_STRING();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<IdentifierContext> identifier();

    class Bool_literalContext : public ParserRuleContext
    {
    public:
        Bool_literalContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> TRUE();
        Ref<tree::TerminalNode> FALSE();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Bool_literalContext> bool_literal();

    class Float_literalContext : public ParserRuleContext
    {
    public:
        Float_literalContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> FLOAT_NUMBER();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Float_literalContext> float_literal();

    class Integer_literalContext : public ParserRuleContext
    {
    public:
        Integer_literalContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> INT_NUMBER();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Integer_literalContext> integer_literal();

    class String_literalContext : public ParserRuleContext
    {
    public:
        String_literalContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> SQUOTED_STRING();
        Ref<tree::TerminalNode> DQUOTED_STRING();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<String_literalContext> string_literal();

    class Datetime_literalContext : public ParserRuleContext
    {
    public:
        Datetime_literalContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> CURRENT_DATE();
        Ref<tree::TerminalNode> CURRENT_TIME();
        Ref<tree::TerminalNode> CURRENT_TIMESTAMP();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Datetime_literalContext> datetime_literal();

    class Alter_tableContext : public ParserRuleContext
    {
    public:
        Alter_tableContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> ALTER();
        Ref<tree::TerminalNode> TABLE();
        Ref<Table_nameContext> table_name();
        Ref<tree::TerminalNode> IGNORE();
        Ref<Alter_specification_listContext> alter_specification_list();
        Ref<Partition_specificationContext> partition_specification();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Alter_tableContext> alter_table();

    class Alter_specificationContext : public ParserRuleContext
    {
    public:
        Alter_specificationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<Table_option_listContext> table_option_list();
        Ref<tree::TerminalNode> ADD();
        Ref<Column_nameContext> column_name();
        Ref<Column_definitionContext> column_definition();
        Ref<tree::TerminalNode> COLUMN();
        Ref<First_afterContext> first_after();
        Ref<Column_definition_listContext> column_definition_list();
        Ref<Index_definitionContext> index_definition();
        Ref<tree::TerminalNode> ALGORITHM();
        Ref<Table_algorithmContext> table_algorithm();
        Ref<tree::TerminalNode> EQUAL();
        Ref<tree::TerminalNode> ALTER();
        Ref<tree::TerminalNode> SET();
        Ref<tree::TerminalNode> DEFAULT();
        Ref<Default_valueContext> default_value();
        Ref<tree::TerminalNode> DROP();
        Ref<tree::TerminalNode> CHANGE();
        Ref<Old_column_nameContext> old_column_name();
        Ref<New_column_nameContext> new_column_name();
        Ref<tree::TerminalNode> LOCK();
        Ref<Table_lockContext> table_lock();
        Ref<tree::TerminalNode> MODIFY();
        Ref<tree::TerminalNode> PRIMARY();
        Ref<tree::TerminalNode> KEY();
        Ref<Index_nameContext> index_name();
        Ref<tree::TerminalNode> INDEX();
        Ref<tree::TerminalNode> FOREIGN();
        Ref<Fk_symbolContext> fk_symbol();
        Ref<tree::TerminalNode> DISABLE();
        Ref<tree::TerminalNode> KEYS();
        Ref<tree::TerminalNode> ENABLE();
        Ref<tree::TerminalNode> RENAME();
        Ref<New_table_nameContext> new_table_name();
        Ref<tree::TerminalNode> TO();
        Ref<tree::TerminalNode> AS();
        Ref<Old_index_nameContext> old_index_name();
        Ref<New_index_nameContext> new_index_name();
        Ref<tree::TerminalNode> ORDER();
        Ref<tree::TerminalNode> BY();
        Ref<Column_name_listContext> column_name_list();
        Ref<tree::TerminalNode> CONVERT();
        Ref<CharsetContext> charset();
        Ref<CollationContext> collation();
        Ref<tree::TerminalNode> DISCARD();
        Ref<tree::TerminalNode> TABLESPACE();
        Ref<tree::TerminalNode> IMPORT();
        Ref<tree::TerminalNode> FORCE();
        Ref<tree::TerminalNode> VALIDATION();
        Ref<tree::TerminalNode> WITHOUT();
        std::vector<Ref<tree::TerminalNode>> WITH();
        Ref<tree::TerminalNode> WITH(int i);
        Ref<tree::TerminalNode> PARTITION();
        Ref<tree::TerminalNode> LPAREN();
        Ref<Partition_definitionContext> partition_definition();
        Ref<tree::TerminalNode> RPAREN();
        Ref<Partition_name_listContext> partition_name_list();
        Ref<tree::TerminalNode> ALL();
        Ref<tree::TerminalNode> TRUNCATE();
        Ref<tree::TerminalNode> COALESCE();
        Ref<Partition_numberContext> partition_number();
        Ref<tree::TerminalNode> REORGANIZE();
        Ref<tree::TerminalNode> INTO();
        Ref<Partition_definition_listContext> partition_definition_list();
        Ref<tree::TerminalNode> EXCHANGE();
        Ref<Partition_nameContext> partition_name();
        Ref<tree::TerminalNode> TABLE();
        Ref<Table_nameContext> table_name();
        Ref<tree::TerminalNode> ANALYZE();
        Ref<tree::TerminalNode> CHECK();
        Ref<tree::TerminalNode> OPTIMIZE();
        Ref<tree::TerminalNode> REBUILD();
        Ref<tree::TerminalNode> REPAIR();
        Ref<tree::TerminalNode> REMOVE();
        Ref<tree::TerminalNode> PARTITIONING();
        Ref<tree::TerminalNode> UPGRADE();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Alter_specificationContext> alter_specification();

    class Alter_specification_listContext : public ParserRuleContext
    {
    public:
        Alter_specification_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        std::vector<Ref<Alter_specificationContext>> alter_specification();
        Ref<Alter_specificationContext> alter_specification(int i);
        std::vector<Ref<tree::TerminalNode>> COMMA();
        Ref<tree::TerminalNode> COMMA(int i);

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Alter_specification_listContext> alter_specification_list();

    class Column_name_listContext : public ParserRuleContext
    {
    public:
        Column_name_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        std::vector<Ref<Column_nameContext>> column_name();
        Ref<Column_nameContext> column_name(int i);
        std::vector<Ref<tree::TerminalNode>> COMMA();
        Ref<tree::TerminalNode> COMMA(int i);

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Column_name_listContext> column_name_list();

    class Partition_name_listContext : public ParserRuleContext
    {
    public:
        Partition_name_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        std::vector<Ref<Partition_nameContext>> partition_name();
        Ref<Partition_nameContext> partition_name(int i);
        std::vector<Ref<tree::TerminalNode>> COMMA();
        Ref<tree::TerminalNode> COMMA(int i);

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Partition_name_listContext> partition_name_list();

    class Column_definition_listContext : public ParserRuleContext
    {
    public:
        Column_definition_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> LPAREN();
        std::vector<Ref<Column_nameContext>> column_name();
        Ref<Column_nameContext> column_name(int i);
        std::vector<Ref<Column_definitionContext>> column_definition();
        Ref<Column_definitionContext> column_definition(int i);
        Ref<tree::TerminalNode> RPAREN();
        std::vector<Ref<tree::TerminalNode>> COMMA();
        Ref<tree::TerminalNode> COMMA(int i);

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Column_definition_listContext> column_definition_list();

    class Table_algorithmContext : public ParserRuleContext
    {
    public:
        Table_algorithmContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> DEFAULT();
        Ref<tree::TerminalNode> INPLACE();
        Ref<tree::TerminalNode> COPY();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Table_algorithmContext> table_algorithm();

    class Table_lockContext : public ParserRuleContext
    {
    public:
        Table_lockContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> DEFAULT();
        Ref<tree::TerminalNode> NONE();
        Ref<tree::TerminalNode> SHARED();
        Ref<tree::TerminalNode> EXCLUSIVE();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Table_lockContext> table_lock();

    class First_afterContext : public ParserRuleContext
    {
    public:
        First_afterContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<tree::TerminalNode> FIRST();
        Ref<tree::TerminalNode> AFTER();
        Ref<Column_nameContext> column_name();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<First_afterContext> first_after();

    class Fk_symbolContext : public ParserRuleContext
    {
    public:
        Fk_symbolContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<SymbolContext> symbol();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Fk_symbolContext> fk_symbol();

    class New_table_nameContext : public ParserRuleContext
    {
    public:
        New_table_nameContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<Table_nameContext> table_name();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<New_table_nameContext> new_table_name();

    class Old_column_nameContext : public ParserRuleContext
    {
    public:
        Old_column_nameContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<Column_nameContext> column_name();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Old_column_nameContext> old_column_name();

    class New_column_nameContext : public ParserRuleContext
    {
    public:
        New_column_nameContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<Column_nameContext> column_name();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<New_column_nameContext> new_column_name();

    class Old_index_nameContext : public ParserRuleContext
    {
    public:
        Old_index_nameContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<Index_nameContext> index_name();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Old_index_nameContext> old_index_name();

    class New_index_nameContext : public ParserRuleContext
    {
    public:
        New_index_nameContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<Index_nameContext> index_name();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<New_index_nameContext> new_index_name();

    class Partition_numberContext : public ParserRuleContext
    {
    public:
        Partition_numberContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
        virtual ssize_t getRuleIndex() const override;
        Ref<Integer_literalContext> integer_literal();

        virtual void enterRule(tree::ParseTreeListener *listener) override;
        virtual void exitRule(tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
    };

    Ref<Partition_numberContext> partition_number();

private:
    static std::vector<dfa::DFA> _decisionToDFA;
    static atn::PredictionContextCache _sharedContextCache;
    static std::vector<std::string> _ruleNames;
    static std::vector<std::string> _tokenNames;

    static std::vector<std::string> _literalNames;
    static std::vector<std::string> _symbolicNames;
    static dfa::Vocabulary _vocabulary;
    static atn::ATN _atn;
    static std::vector<uint16_t> _serializedATN;

    struct Initializer
    {
        Initializer();
    };
    static Initializer _init;
};

} // namespace mysql

#define NULL SAVED_NULL
#define UNICODE SAVED_UNICODE
