cmake_minimum_required(VERSION 3.5)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules/")

if(POLICY CMP0048)
    cmake_policy(SET CMP0048 NEW)
endif()

file(STRINGS "VERSION" VERSION)
project(cpporm VERSION ${VERSION} LANGUAGES CXX)

include(setup)
init_project(
    DESC "Simple ORM library with SQL parser"
    CONFIG_FILE_NAME include/cpporm/config.h
    VERSION_FILE_NAME include/cpporm/version.h
    OPTIONS
        USE_DUAL_ABI "whether to use C++ dual ABI (for compatibility)" ON END)

if(CPPORM_USE_DUAL_ABI)
    set(CONF_USE_DUAL_ABI 1)
else()
    set(CONF_USE_DUAL_ABI 0)
endif()

set(CXX_STANDARD_11 -std=c++11)

if(NOT CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(EMIT_ABI_TAG_WARNING -Wabi-tag)
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        set(EMIT_CLASS_DEBUG_ALWAYS -femit-class-debug-always)
    endif()
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
        include/cpporm/backend/soci
        src/cpporm/backend/soci
    EXPORT_FILE_NAME include/cpporm/export.h
    INCLUDE_DIRS
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    OPTIONS
        PRIVATE
            ${CXX_STANDARD_11}
            ${EMIT_ABI_TAG_WARNING}
            ${EMIT_CLASS_DEBUG_ALWAYS}
    DEPENDENCIES
        Boost REQUIRED END
    IS_LIBRARY)

setup_target(
    NAME "cpporm_soci"
    SOURCE_PREFIXES
        include/cpporm/backend/soci
        src/cpporm/backend/soci
    EXPORT_FILE_NAME include/cpporm/backend/soci/export.h
    OPTIONS
        PRIVATE
            ${CXX_STANDARD_11}
            ${EMIT_ABI_TAG_WARNING}
            ${EMIT_CLASS_DEBUG_ALWAYS}
    DEPENDENCIES
        INCLUDE PUBLIC SOCI REQUIRED END
        INTERNAL SOCI::soci_core END
        INTERNAL cpporm END
    IS_LIBRARY)

setup_target(
    NAME "ormc"
    SOURCE_PREFIXES
        src/ormc
    OPTIONS
        PRIVATE
            ${CXX_STANDARD_11}
            ${EMIT_CLASS_DEBUG_ALWAYS}
    DEPENDENCIES
        Boost REQUIRED END
        Gflags REQUIRED END
        CUSTOM antlr4 HEADERS antlr4-runtime.h
            HEADER_SUFFIXES antlr4-runtime LIBRARIES antlr4-runtime END
        INTERNAL cpporm END)

setup_doxygen(
    NAME "html_and_xml"
    CONFIG_FILE doxygen/Doxyfile.in)

setup_installation(
    INCLUDE_DIRS
        include
    TARGETS
        cpporm
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
            ${CXX_STANDARD_11}
            ${EMIT_CLASS_DEBUG_ALWAYS}
    DEFINITIONS
        PRIVATE
            -DODBC_SQLITE_DRIVER_NAME="${ODBC_SQLITE_DRIVER_NAME}"
            -DSOCI_SQLITE_DRIVER_NAME="${SOCI_SQLITE_DRIVER_NAME}"
    DEPENDENCIES
        EXTERNAL googletest USE_TARGETS gmock_main gtest END
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
            ${CXX_STANDARD_11}
            ${EMIT_CLASS_DEBUG_ALWAYS}
    DEPENDENCIES
        EXTERNAL googletest USE_TARGETS gmock_main gtest END)
