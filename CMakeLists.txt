cmake_minimum_required(VERSION 3.5)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules/")

file(STRINGS "VERSION" VERSION)
project(cpporm VERSION ${VERSION} LANGUAGES CXX)

include(setup)
init_project(
    DESC "Simple ORM library with SQL parser"
    CONFIG_FILE_NAME include/cpporm/config.h
    CONFIG_FILE_IN config.h.in
    OPTIONS
        USE_DUAL_ABI "whether to use C++ dual ABI (for compatibility)" ON END)

if(CPPORM_USE_DUAL_ABI)
    set(CONF_USE_DUAL_ABI 1)
else()
    set(CONF_USE_DUAL_ABI 0)
endif()

set(PUBLIC_OPTIONS -std=c++11)
if(APPLE)
    list(APPEND PUBLIC_OPTIONS -Wno-gnu-string-literal-operator-template)
endif()

if(WIN32)
    set(ODBC_SQLITE_DRIVER_NAME "SQLite3 ODBC Driver")
else()
    set(ODBC_SQLITE_DRIVER_NAME "SQLite3")
endif()
set(SOCI_SQLITE_DRIVER_NAME "sqlite3")

setup_target(
    NAME "cpporm"
    SOURCE_PREFIXES
        include/cpporm
        src/cpporm
    EXCLUDE_PREFIXES
        include/cpporm/backend/nanodbc
        include/cpporm/backend/soci
        src/cpporm/backend/nanodbc
        src/cpporm/backend/soci
    EXPORT_FILE_NAME include/cpporm/export.h
    INCLUDE_DIRS
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    OPTIONS
        PUBLIC
            ${PUBLIC_OPTIONS}
    IS_LIBRARY)

setup_target(
    NAME "cpporm_nanodbc"
    SOURCE_PREFIXES
        include/cpporm/backend/nanodbc
        src/cpporm/backend/nanodbc
    EXPORT_FILE_NAME include/cpporm/backend/nanodbc/export.h
    DEFINITIONS
        PUBLIC
            -DUNICODE
            -D_UNICODE
            -DNANODBC_USE_UNICODE
    DEPENDENCIES
        Boost REQUIRED END
        CUSTOM nanodbc LIBRARIES nanodbcu END
        INTERNAL cpporm END
    IS_LIBRARY)

setup_target(
    NAME "cpporm_soci"
    SOURCE_PREFIXES
        include/cpporm/backend/soci
        src/cpporm/backend/soci
    EXPORT_FILE_NAME include/cpporm/backend/soci/export.h
    DEFINITIONS
        PUBLIC
            -DUNICODE
            -D_UNICODE
    DEPENDENCIES
        INCLUDE PUBLIC Soci 3.2 REQUIRED END
        INTERNAL cpporm END
    IS_LIBRARY)

setup_target(
    NAME "ormc"
    SOURCE_PREFIXES
        src/ormc
    DEPENDENCIES
        Boost REQUIRED END
        Gflags REQUIRED END
        CUSTOM antlr4 HEADERS antlr4-common.h HEADER_SUFFIXES antlr4 LIBRARIES antlr4-runtime END
        INTERNAL cpporm END)

setup_project(
    DOCUMENTATION
        OUTPUT_DIR doc
        INPUT_FILE doc/Doxyfile.in
    INSTALLATION
        DATA_DIR data
        INCLUDE_DIRS
            include
        TARGETS
            cpporm
            cpporm_nanodbc
            cpporm_soci
            ormc)

setup_tests(
    NAME "cpporm"
    DATA_DIR tests/data
    EXTRA_SOURCES
        tests/cpporm/helpers.cpp
        tests/cpporm/sample1.mysql.cpp
    INCLUDE_DIRS
        tests/cpporm
    SOURCE_PREFIXES
        tests/cpporm
    OPTIONS
        PRIVATE
            -femit-class-debug-always
    DEFINITIONS
        PRIVATE
            -DODBC_SQLITE_DRIVER_NAME="${ODBC_SQLITE_DRIVER_NAME}"
            -DSOCI_SQLITE_DRIVER_NAME="${SOCI_SQLITE_DRIVER_NAME}"
    DEPENDENCIES
        GMock LIB_VAR_NAMES GMOCK_MAIN_LIBRARIES END
        INTERNAL cpporm_nanodbc END
        INTERNAL cpporm_soci END
        INTERNAL cpporm END)

setup_tests(
    NAME "ormc"
    DATA_DIR tests/data
    INCLUDE_DIRS
        tests/ormc
    SOURCE_PREFIXES
        tests/ormc/regression
        tests/ormc/unit
    OPTIONS
        PRIVATE
            -std=c++11
    DEPENDENCIES
        GMock LIB_VAR_NAMES GMOCK_MAIN_LIBRARIES END
        FlatBuffers REQUIRED END)
