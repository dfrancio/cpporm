#===================================================================================================
# MODULE:   setup
#
# PROVIDES:
#       download_project(...)
#       find_custom_package(...)
#       install_project(...)
#       init_project(...)
#       setup_project(...)
#       setup_target(...)
#       setup_test(...)
#
#===================================================================================================
include(CMakeParseArguments)
include(CMakePackageConfigHelpers)
include(FindPackageHandleStandardArgs)
include(GenerateExportHeader)
include(CTest)
include(cotire)

set(LIST_DIR "${CMAKE_CURRENT_LIST_DIR}")

macro(download_project _name)
    if(EXISTS "${LIST_DIR}/../Download/${_name}" AND NOT TARGET ${_name})
        add_custom_target(${_name})
        set(${_name}_DIR "${CMAKE_BINARY_DIR}/${_name}" CACHE INTERNAL "")
        file(MAKE_DIRECTORY ${${_name}_DIR})
        execute_process(
            COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}"
                "${LIST_DIR}/../Download/${_name}"
            WORKING_DIRECTORY "${${_name}_DIR}")
        execute_process(
            COMMAND ${CMAKE_COMMAND} --build .
            WORKING_DIRECTORY "${${_name}_DIR}")
        if(EXISTS "${LIST_DIR}/../Download/${_name}/postbuild.cmake")
            include("${LIST_DIR}/../Download/${_name}/postbuild.cmake")
        endif()
        set(${_name}_FOUND TRUE CACHE INTERNAL "")
    endif()
endmacro()

macro(get_relative_path _out _from _to)
    file(RELATIVE_PATH ${_out} ${${_from}} ${${_to}})
    if(NOT ${_out})
        set(${_out} ".")
    endif()
endmacro(get_relative_path)

macro(get_path_default _out _in _def _root)
    get_parameter_default(${_out} ${_in} ${_def})
    if(NOT IS_ABSOLUTE "${${_out}}")
        set(${_out} "${_root}/${${_out}}")
    endif()
endmacro(get_path_default)

macro(get_parameter_default _out _in _def)
    if(NOT ${_in})
        set(${_out} "${_def}")
    else()
        set(${_out} "${${_in}}")
    endif()
endmacro(get_parameter_default)

macro(exclude_from_listing _sources _exclude_prefixes _exclude_sources)
    foreach(exclude ${${_exclude_prefixes}})
        foreach(source ${${_sources}})
            if(source MATCHES "^.[/\\]${exclude}(.*)$" OR source MATCHES "^${exclude}/(.*)$")
                list(REMOVE_ITEM ${_sources} ${source})
            endif()
        endforeach()
    endforeach()
    foreach(exclude ${${_exclude_sources}})
        list(REMOVE_ITEM ${_sources} ${exclude})
    endforeach()
endmacro(exclude_from_listing)

#===================================================================================================
#
#   find_custom_package(NAME <lib>
#                       [HEADERS <file>...]
#                       [LIBRARIES <name>...]
#                       [HEADER_SUFFIXES <name>...]
#                       [LIBRARY_SUFFIXES <name>...]
#                       [ROOT_DIR <dir>]
#                       [NO_HEADER] [NO_LIBRARY])
#
#   This module defines
#       <LIB>_INCLUDE_DIRS  where to find the <lib-name> headers
#       <LIB>_LIBRARIES     libraries to link against to use <lib-name>
#       <LIB>_FOUND         if false, do not try to use <lib-name>
#
#   also defined, but not for general use are
#       <lib>_INCLUDE_DIR   where to find the <lib-name> headers
#       <lib>_LIBRARY       where to find the <lib-name> library
#
#===================================================================================================
macro(find_custom_package_set_search_dirs)

    if(NOT ARG_ROOT_DIR)
        if(${ARG_NAME}_ROOT_DIR)
            set(ARG_ROOT_DIR ${${ARG_NAME}_ROOT_DIR})
        elseif($ENV{${ARG_NAME}_ROOT_DIR})
            set(ARG_ROOT_DIR $ENV{${ARG_NAME}_ROOT_DIR})
        elseif($ENV{${ARG_NAME}_ROOT})
            set(ARG_ROOT_DIR $ENV{${ARG_NAME}_ROOT})
        endif()
    endif()

    set(SEARCH_DIRS
        ${ARG_ROOT_DIR}
        /usr/local
        /usr
        /sw
        /opt/local
        /opt/csw
        $ENV{LIB_DIR}
        $ENV{ProgramFiles}
        $ENV{SystemDrive}
        $ENV{OSGEO4W_ROOT})

endmacro(find_custom_package_set_search_dirs)

macro(find_custom_package_include_dir)

    if(NOT ARG_NO_HEADER)
        if(NOT ARG_HEADERS)
            set(ARG_HEADERS ${ARG_LOWERCASE_NAME}.h)
        endif()

        find_path(
            ${ARG_NAME}_INCLUDE_DIR
            NAMES ${ARG_HEADERS}
            HINTS ${SEARCH_DIRS}
            PATH_SUFFIXES include ${ARG_HEADER_SUFFIXES})
    endif()

endmacro(find_custom_package_include_dir)

macro(find_custom_package_library)

    if(NOT ARG_NO_LIBRARY)
        if(NOT ARG_LIBRARIES)
            set(ARG_LIBRARIES ${ARG_LOWERCASE_NAME})
        endif()

        find_library(
            ${ARG_NAME}_LIBRARY
            NAMES ${ARG_LIBRARIES}
            HINTS ${SEARCH_DIRS}
            PATH_SUFFIXES lib ${ARG_LIBRARY_SUFFIXES})
    endif()

endmacro(find_custom_package_library)

macro(find_custom_package_set_output_vars)

    set(STANDARD_ARGS ${ARG_NAME} DEFAULT_MSG)
    if(NOT ARG_NO_LIBRARY)
        list(APPEND STANDARD_ARGS ${ARG_NAME}_LIBRARY)
    endif()
    if(NOT ARG_NO_HEADER)
        list(APPEND STANDARD_ARGS ${ARG_NAME}_INCLUDE_DIR)
    endif()

    find_package_handle_standard_args(${STANDARD_ARGS})

    if(${ARG_UPPERCASE_NAME}_FOUND)
        if(NOT ARG_NO_HEADER)
            set(${ARG_UPPERCASE_NAME}_INCLUDE_DIRS ${${ARG_NAME}_INCLUDE_DIR} PARENT_SCOPE)
            mark_as_advanced(${ARG_NAME}_INCLUDE_DIR)
        endif()
        if(NOT ARG_NO_LIBRARY)
            set(${ARG_UPPERCASE_NAME}_LIBRARIES ${${ARG_NAME}_LIBRARY} PARENT_SCOPE)
            mark_as_advanced(${ARG_NAME}_LIBRARY)
        endif()
    elseif(ARG_REQUIRED)
        message(FATAL_ERROR "The ${ARG_NAME} package is required but was not found.")
    endif()

    set(${ARG_UPPERCASE_NAME}_FOUND ${${ARG_UPPERCASE_NAME}_FOUND} PARENT_SCOPE)

endmacro(find_custom_package_set_output_vars)

function(find_custom_package)

    set(options NO_HEADER NO_LIBRARY REQUIRED)
    set(oneValueArgs NAME ROOT_DIR)
    set(multiValueArgs HEADERS LIBRARIES HEADER_SUFFIXES LIBRARY_SUFFIXES)

    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    string(TOUPPER ${ARG_NAME} ARG_UPPERCASE_NAME)
    string(TOLOWER ${ARG_NAME} ARG_LOWERCASE_NAME)

    find_custom_package_set_search_dirs()
    find_custom_package_include_dir()
    find_custom_package_library()
    find_custom_package_set_output_vars()

endfunction(find_custom_package)

#===================================================================================================
#
#   install_project(TARGETS <target>...
#                   [CONFIG_IN <file>]
#                   [MACROS_IN <file>]
#                   [PATH_ARGS <var1> <var2> ... <varN>]
#                   [KEEP_PUBLIC_HEADER_HIERARCHY])
#
#===================================================================================================
macro(install_project_compose_header_dir)

    get_filename_component(HEADER_DIR "${HEADER}" DIRECTORY)
    if(HEADER_DIR MATCHES "^${CMAKE_CURRENT_BINARY_DIR}[/\\](.*)$")
        set(HEADER_DIR "${CMAKE_MATCH_1}")
    elseif(HEADER_DIR MATCHES "^${CMAKE_CURRENT_SOURCE_DIR}[/\\](.*)$")
        set(HEADER_DIR "${CMAKE_MATCH_1}")
    elseif(HEADER_DIR MATCHES "^.[/\\](.*)$")
        set(HEADER_DIR "${CMAKE_MATCH_1}")
    endif()
    if(NOT HEADER_DIR MATCHES "^${INSTALL_INC_DIR}[/\\](.*)$")
        set(HEADER_DIR "${INSTALL_INC_DIR}/${HEADER_DIR}")
    endif()

endmacro(install_project_compose_header_dir)

macro(install_project_install_public_headers)

    foreach(TARGET_NAME ${VALID_TARGETS})
        get_target_property(TARGET_TYPE ${TARGET_NAME} TYPE)
        if(TARGET_TYPE STREQUAL "INTERFACE_LIBRARY")
            get_target_property(HEADERS ${TARGET_NAME} INTERFACE_PUBLIC_HEADER)
        else()
            get_target_property(HEADERS ${TARGET_NAME} PUBLIC_HEADER)
        endif()

        if(NOT HEADERS MATCHES ".*NOTFOUND")
            foreach(HEADER ${HEADERS})
                install_project_compose_header_dir()
                install(FILES ${HEADER} DESTINATION ${HEADER_DIR})
            endforeach()
        endif()

        if(NOT TARGET_TYPE STREQUAL "INTERFACE_LIBRARY")
            set_target_properties(${TARGET_NAME} PROPERTIES PUBLIC_HEADER "")
        endif()
    endforeach()

endmacro(install_project_install_public_headers)

macro(install_project_install_targets)

    if(ARG_KEEP_PUBLIC_HEADER_HIERARCHY)
        install_project_install_public_headers()
        install(TARGETS ${VALID_TARGETS} EXPORT ${EXPORT_NAME}
            LIBRARY DESTINATION ${INSTALL_LIB_DIR}
            ARCHIVE DESTINATION ${INSTALL_LIB_DIR}
            RUNTIME DESTINATION ${INSTALL_BIN_DIR}
            INCLUDES DESTINATION ${INSTALL_INC_DIR})
    else()
        install(TARGETS ${VALID_TARGETS} EXPORT ${EXPORT_NAME}
            LIBRARY DESTINATION ${INSTALL_LIB_DIR}
            ARCHIVE DESTINATION ${INSTALL_LIB_DIR}
            RUNTIME DESTINATION ${INSTALL_BIN_DIR}
            INCLUDES DESTINATION ${INSTALL_INC_DIR}
            PUBLIC_HEADER DESTINATION ${INSTALL_INC_DIR})
    endif()

endmacro(install_project_install_targets)

macro(install_project_install_config_files)

    # Add targets to the build tree export set
    export(TARGETS ${VALID_TARGETS}
        FILE "${CMAKE_CURRENT_BINARY_DIR}/${EXPORT_FILE_NAME}")

    # Create the config file for the install tree
    list(GET VALID_TARGETS 0 PACKAGE_FIRST_TARGET)
    set(PACKAGE_EXPORT_FILE_NAME ${EXPORT_FILE_NAME})
    configure_package_config_file(
        "${CONFIG_IN_FILE}"
        "${CMAKE_CURRENT_BINARY_DIR}/${CONFIG_OUT_NAME}"
         INSTALL_DESTINATION ${INSTALL_CMAKE_DIR}
         PATH_VARS ${ARG_PATH_VARS})

    # Create the version file for the install tree
    write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/${VERSION_OUT_NAME}"
        COMPATIBILITY AnyNewerVersion)

    # Create the macros file for the install tree
    configure_file(${MACROS_IN_FILE}
        "${CMAKE_CURRENT_BINARY_DIR}/${MACROS_OUT_NAME}" @ONLY)

    # Install the config and version files
    install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/${CONFIG_OUT_NAME}"
        "${CMAKE_CURRENT_BINARY_DIR}/${VERSION_OUT_NAME}"
        "${CMAKE_CURRENT_BINARY_DIR}/${MACROS_OUT_NAME}"
        DESTINATION "${INSTALL_CMAKE_DIR}")

    # Install the export targets file
    install(EXPORT ${EXPORT_NAME} DESTINATION "${INSTALL_CMAKE_DIR}")

endmacro(install_project_install_config_files)

macro(install_project_process_args)

    if(PROJECT_NAME MATCHES "^[A-Z].*")
        set(EXPORT_NAME ${PROJECT_NAME}Targets)
        set(EXPORT_FILE_NAME ${EXPORT_NAME}.cmake)
        set(CONFIG_OUT_NAME ${PROJECT_NAME}Config.cmake)
        set(VERSION_OUT_NAME ${PROJECT_NAME}ConfigVersion.cmake)
        set(MACROS_OUT_NAME ${PROJECT_NAME}Macros.cmake)
    else()
        set(EXPORT_NAME ${PROJECT_NAME}-targets)
        set(EXPORT_FILE_NAME ${EXPORT_NAME}.cmake)
        set(CONFIG_OUT_NAME ${PROJECT_NAME}-config.cmake)
        set(VERSION_OUT_NAME ${PROJECT_NAME}-config-version.cmake)
        set(MACROS_OUT_NAME ${PROJECT_NAME}-macros.cmake)
    endif()

    get_parameter_default(PROJECT_VERSION PROJECT_VERSION "0.1.0")
    get_parameter_default(CONFIG_IN ARG_CONFIG_IN "${LIST_DIR}/config.cmake.in")
    get_parameter_default(MACROS_IN ARG_MACROS_IN "${LIST_DIR}/macros.cmake.in")
    get_parameter_default(INSTALL_BIN_DIR ${PROJECT_NAME_UPPERCASE}_INSTALL_BIN_DIR bin)
    get_parameter_default(INSTALL_LIB_DIR ${PROJECT_NAME_UPPERCASE}_INSTALL_LIB_DIR lib)
    get_parameter_default(INSTALL_INC_DIR ${PROJECT_NAME_UPPERCASE}_INSTALL_INC_DIR include)
    get_parameter_default(INSTALL_CMAKE_DIR
        ${PROJECT_NAME_UPPERCASE}_INSTALL_CMAKE_DIR ${INSTALL_LIB_DIR}/cmake/${PROJECT_NAME})

    get_filename_component(CONFIG_IN_FILE "${CONFIG_IN}" ABSOLUTE)
    get_filename_component(MACROS_IN_FILE "${MACROS_IN}" ABSOLUTE)

endmacro(install_project_process_args)

function(install_project)

    set(options KEEP_PUBLIC_HEADER_HIERARCHY)
    set(oneValueArgs CONFIG_IN MACROS_IN)
    set(multiValueArgs TARGETS PATH_VARS)

    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    install_project_process_args()
    foreach(TARGET_NAME ${ARG_TARGETS})
        if (NOT TARGET ${TARGET_NAME})
            message(WARNING "install_project: ${TARGET_NAME} is not a target.")
        else()
            set(VALID_TARGETS ${VALID_TARGETS} ${TARGET_NAME})
        endif()
    endforeach()
    install_project_install_config_files()
    install_project_install_targets()

endfunction(install_project)

#===================================================================================================
#
#   init_project(NAME <project>
#                [VERSION <version>]
#                [LANGUAGES <lang>...]
#                [CONFIG_FILE_NAME <path>]
#                [CONFIG_FILE_IN <path>]
#                [OPTIONS [<option>... END]...])
#
#===================================================================================================
macro(init_project_options)

    message(STATUS "Configuring project: ${PROJECT_NAME} (version ${PROJECT_VERSION})")
    string(TOUPPER ${PROJECT_NAME} PROJECT_NAME_UPPERCASE)
    set(PROJECT_NAME_UPPERCASE ${PROJECT_NAME_UPPERCASE} PARENT_SCOPE)
    set(PROJECT_DESCRIPTION ${ARG_DESC} PARENT_SCOPE)

    option(BUILD_SHARED_LIBS
        "whether to build the shared version of the library" ON)
    option(${PROJECT_NAME_UPPERCASE}_ENABLE_INSTALL
        "whether to configure the installation rules" ON)
    option(${PROJECT_NAME_UPPERCASE}_ENABLE_DOCS
        "whether to build the documentation (requires Doxygen)" OFF)
    option(${PROJECT_NAME_UPPERCASE}_ENABLE_PCH
        "whether to use precompiled headers" ON)
    option(${PROJECT_NAME_UPPERCASE}_EXCLUDE_DEPRECATED
        "whether to exclude deprecated symbols" OFF)
    option(${PROJECT_NAME_UPPERCASE}_BUILD_EXAMPLES
        "whether to build the examples" OFF)

    set(CURRENT_OPT)
    foreach(opt ${ARG_OPTIONS})
        if(opt STREQUAL "END")
            list(GET CURRENT_OPT 0 OPTION_NAME)
            list(REMOVE_AT CURRENT_OPT 0)
            option(${PROJECT_NAME_UPPERCASE}_${OPTION_NAME} ${CURRENT_OPT})
            set(CURRENT_OPT)
        else()
            list(APPEND CURRENT_OPT ${opt})
        endif()
    endforeach()

endmacro(init_project_options)

macro(init_project_install_paths)

    set(${PROJECT_NAME_UPPERCASE}_OUTPUT_BIN_DIR bin CACHE STRING
        "Output directory for executables (relative to the build prefix)")
    set(${PROJECT_NAME_UPPERCASE}_OUTPUT_LIB_DIR lib CACHE STRING
        "Output directory for libraries (relative to the build prefix)")
    set(${PROJECT_NAME_UPPERCASE}_INSTALL_BIN_DIR bin CACHE STRING
        "Installation directory for executables (relative to the install prefix)")
    set(${PROJECT_NAME_UPPERCASE}_INSTALL_LIB_DIR lib CACHE STRING
        "Installation directory for libraries (relative to the install prefix)")
    set(${PROJECT_NAME_UPPERCASE}_INSTALL_INC_DIR include CACHE STRING
        "Installation directory for headers (relative to the install prefix)")
    set(${PROJECT_NAME_UPPERCASE}_INSTALL_DOC_DIR share/doc/${PROJECT_NAME} CACHE STRING
        "Installation directory for documentation files (relative to the install prefix)")
    set(${PROJECT_NAME_UPPERCASE}_INSTALL_DATA_DIR share/${PROJECT_NAME} CACHE STRING
        "Installation directory for read-only data files (relative to the install prefix)")
    set(${PROJECT_NAME_UPPERCASE}_INSTALL_VAR_DIR /var/lib/${PROJECT_NAME} CACHE PATH
        "Installation directory for state data files")

    if(WIN32 AND NOT CYGWIN AND NOT MINGW)
        set(${PROJECT_NAME_UPPERCASE}_INSTALL_CMAKE_DIR CMake)
    else()
        set(${PROJECT_NAME_UPPERCASE}_INSTALL_CMAKE_DIR
            ${${PROJECT_NAME_UPPERCASE}_INSTALL_LIB_DIR}/cmake/${PROJECT_NAME} CACHE STRING
            "Installation directory for CMake config files (relative to the install prefix)")
    endif()

    mark_as_advanced(
        ${PROJECT_NAME_UPPERCASE}_OUTPUT_BIN_DIR
        ${PROJECT_NAME_UPPERCASE}_OUTPUT_LIB_DIR
        ${PROJECT_NAME_UPPERCASE}_INSTALL_BIN_DIR
        ${PROJECT_NAME_UPPERCASE}_INSTALL_LIB_DIR
        ${PROJECT_NAME_UPPERCASE}_INSTALL_INC_DIR
        ${PROJECT_NAME_UPPERCASE}_INSTALL_DOC_DIR
        ${PROJECT_NAME_UPPERCASE}_INSTALL_DATA_DIR
        ${PROJECT_NAME_UPPERCASE}_INSTALL_VAR_DIR
        ${PROJECT_NAME_UPPERCASE}_INSTALL_CMAKE_DIR)

endmacro(init_project_install_paths)

macro(init_project_configuration)

    get_path_default(CONFIG_FILE_NAME ARG_CONFIG_FILE_NAME "config.h" ${CMAKE_CURRENT_BINARY_DIR})
    get_path_default(CONFIG_FILE_IN ARG_CONFIG_FILE_IN "config.h.in" ${CMAKE_CURRENT_SOURCE_DIR})
    get_path_default(VERSION_FILE_NAME ARG_VERSION_FILE_NAME "version.h" ${CMAKE_CURRENT_BINARY_DIR})
    get_path_default(VERSION_FILE_IN ARG_VERSION_FILE_IN "version.h.in" ${CMAKE_CURRENT_SOURCE_DIR})

    if(EXISTS ${CONFIG_FILE_IN})
        set(${PROJECT_NAME}_CONFIG_FILE_IN ${CONFIG_FILE_IN} CACHE INTERNAL "")
        set(${PROJECT_NAME}_CONFIG_FILE_NAME ${CONFIG_FILE_NAME} CACHE INTERNAL "")
    endif()

    if(EXISTS ${VERSION_FILE_IN})
        set(${PROJECT_NAME}_VERSION_FILE_IN ${VERSION_FILE_IN} CACHE INTERNAL "")
        set(${PROJECT_NAME}_VERSION_FILE_NAME ${VERSION_FILE_NAME} CACHE INTERNAL "")
    endif()

endmacro(init_project_configuration)

function(init_project)

    set(options)
    set(oneValueArgs DESC CONFIG_FILE_IN CONFIG_FILE_NAME VERSION_FILE_IN VERSION_FILE_NAME)
    set(multiValueArgs OPTIONS)

    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    init_project_options()
    init_project_install_paths()
    init_project_configuration()

endfunction(init_project)

#===================================================================================================
#
#   setup_database(NAME <database>
#                  [BUILD_OUTPUT <path>]
#                  [INSTALL_DIR <path>]
#                  [EXTRA_SOURCES <path>...]
#                  [EXCLUDE_SOURCES <path>...]
#                  [SOURCE_PREFIXES <path>...]
#                  [EXCLUDE_PREFIXES <path>...])
#
#===================================================================================================
function(setup_database)

    set(options)
    set(oneValueArgs NAME BUILD_OUTPUT INSTALL_DIR)
    set(multiValueArgs EXTRA_SOURCES EXCLUDE_SOURCES SOURCE_PREFIXES EXCLUDE_PREFIXES)

    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    get_path_default(BUILD_OUTPUT ARG_BUILD_OUTPUT
        "db/${ARG_NAME}.sqlite" ${CMAKE_CURRENT_BINARY_DIR})
    get_parameter_default(INSTALL_DIR ARG_INSTALL_DIR "db")

    foreach(prefix ${ARG_SOURCE_PREFIXES})
        file(STRINGS "${PROJECT_SOURCE_DIR}/SOURCES" SOURCES REGEX ".*${prefix}[/\\].*")
        list(APPEND ${ARG_NAME}_DB_SOURCES ${SOURCES})
    endforeach()
    exclude_from_listing(${ARG_NAME}_DB_SOURCES ARG_EXCLUDE_PREFIXES ARG_EXCLUDE_SOURCES)
    list(APPEND ${ARG_NAME}_DB_SOURCES ${ARG_EXTRA_SOURCES})

    find_program(CAT_EXECUTABLE cat)
    file(TO_NATIVE_PATH ${CAT_EXECUTABLE} CAT_EXECUTABLE)

    find_program(SQLITE3_EXECUTABLE sqlite3)
    file(TO_NATIVE_PATH ${SQLITE3_EXECUTABLE} SQLITE3_EXECUTABLE)

    get_filename_component(BUILD_OUTPUT_DIR ${BUILD_OUTPUT} DIRECTORY)
    add_custom_command(
        OUTPUT "${BUILD_OUTPUT}"
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMAND ${CMAKE_COMMAND} -E make_directory ${BUILD_OUTPUT_DIR}
        COMMAND ${CAT_EXECUTABLE} ${${ARG_NAME}_DB_SOURCES} |
                ${SQLITE3_EXECUTABLE} ${BUILD_OUTPUT}
        DEPENDS "${${ARG_NAME}_DB_SOURCES}")
    add_custom_target(database_${PROJECT_NAME}_${ARG_NAME} ALL SOURCES "${BUILD_OUTPUT}")

    if(${PROJECT_NAME_UPPERCASE}_ENABLE_INSTALL)
        install(FILES ${BUILD_OUTPUT} DESTINATION
            "${${PROJECT_NAME_UPPERCASE}_INSTALL_VAR_DIR}/${INSTALL_DIR}")
    endif()

endfunction(setup_database)

#===================================================================================================
#
#   setup_locale(NAME <locale>
#                [DOMAIN <domain>]
#                [BUILD_OUTPUT <path>]
#                [INSTALL_DIR <path>]
#                [EXTRA_SOURCES <path>...]
#                [EXCLUDE_SOURCES <path>...]
#                [SOURCE_PREFIXES <path>...]
#                [EXCLUDE_PREFIXES <path>...])
#
#===================================================================================================
function(setup_locale)

    set(options)
    set(oneValueArgs NAME DOMAIN BUILD_OUTPUT INSTALL_DIR)
    set(multiValueArgs EXTRA_SOURCES EXCLUDE_SOURCES SOURCE_PREFIXES EXCLUDE_PREFIXES)

    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    get_parameter_default(DOMAIN ARG_DOMAIN ${PROJECT_NAME})
    get_path_default(BUILD_OUTPUT ARG_BUILD_OUTPUT
        "locale/${ARG_NAME}/LC_MESSAGES/${DOMAIN}.mo" ${CMAKE_CURRENT_BINARY_DIR})
    get_parameter_default(INSTALL_DIR ARG_INSTALL_DIR "locale/${ARG_NAME}/LC_MESSAGES")

    foreach(prefix ${ARG_SOURCE_PREFIXES})
        file(STRINGS "${PROJECT_SOURCE_DIR}/SOURCES" SOURCES REGEX ".*${prefix}[/\\].*")
        list(APPEND ${ARG_NAME}_LOCALE_SOURCES ${SOURCES})
    endforeach()
    exclude_from_listing(${ARG_NAME}_LOCALE_SOURCES ARG_EXCLUDE_PREFIXES ARG_EXCLUDE_SOURCES)
    list(APPEND ${ARG_NAME}_LOCALE_SOURCES ${ARG_EXTRA_SOURCES})

    find_program(MSGCAT_EXECUTABLE msgcat)
    file(TO_NATIVE_PATH ${MSGCAT_EXECUTABLE} MSGCAT_EXECUTABLE)

    find_program(MSGFMT_EXECUTABLE msgfmt)
    file(TO_NATIVE_PATH ${MSGFMT_EXECUTABLE} MSGFMT_EXECUTABLE)

    get_filename_component(BUILD_OUTPUT_DIR ${BUILD_OUTPUT} DIRECTORY)
    add_custom_command(
        OUTPUT "${BUILD_OUTPUT}"
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMAND ${CMAKE_COMMAND} -E make_directory ${BUILD_OUTPUT_DIR}
        COMMAND ${MSGCAT_EXECUTABLE} --force-po ${${ARG_NAME}_LOCALE_SOURCES} |
                ${MSGFMT_EXECUTABLE} -o ${BUILD_OUTPUT} -
        DEPENDS "${${ARG_NAME}_LOCALE_SOURCES}")
    add_custom_target(locale_${PROJECT_NAME}_${ARG_NAME} ALL SOURCES ${BUILD_OUTPUT})

    if(${PROJECT_NAME_UPPERCASE}_ENABLE_INSTALL)
        install(FILES ${BUILD_OUTPUT} DESTINATION
            "${${PROJECT_NAME_UPPERCASE}_INSTALL_DATA_DIR}/${INSTALL_DIR}")
    endif()

endfunction(setup_locale)

#===================================================================================================
#
#   setup_documentation([INPUT_DIR <path>]
#                       [BUILD_OUTPUT <path>]
#                       [OUTPUT_FORMAT <format>]
#                       [HTML_THEME <name>])
#
#===================================================================================================
function(setup_documentation)

    set(options)
    set(oneValueArgs INPUT_DIR BUILD_OUTPUT OUTPUT_FORMAT HTML_THEME)
    set(multiValueArgs)

    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    get_path_default(INPUT_DIR ARG_INPUT_DIR "doc" ${CMAKE_CURRENT_SOURCE_DIR})
    get_path_default(BUILD_OUTPUT ARG_BUILD_OUTPUT "doc" ${CMAKE_CURRENT_BINARY_DIR})
    get_parameter_default(OUTPUT_FORMAT ARG_OUTPUT_FORMAT "html")
    get_parameter_default(HTML_THEME ARG_HTML_THEME "alabaster")

    if(${PROJECT_NAME_UPPERCASE}_ENABLE_DOCS)

        find_package(Doxygen REQUIRED)
        find_package(PythonInterp)

        find_program(BREATHE_EXECUTABLE breathe-apidoc)
        file(TO_NATIVE_PATH ${BREATHE_EXECUTABLE} BREATHE_EXECUTABLE)

        find_program(SPHINX_EXECUTABLE sphinx-build)
        file(TO_NATIVE_PATH ${SPHINX_EXECUTABLE} SPHINX_EXECUTABLE)

        set(DOXYGEN_OUTPUT_DIR "${BUILD_OUTPUT}/doxygen")
        set(DOXYGEN_OUTPUT_FILE "${DOXYGEN_OUTPUT_DIR}/xml/index.xml")

        get_relative_path(CONF_PROJECT_SOURCE_DIR CMAKE_CURRENT_BINARY_DIR PROJECT_SOURCE_DIR)
        get_relative_path(CONF_DOC_SOURCE_DIR CMAKE_CURRENT_BINARY_DIR INPUT_DIR)
        get_relative_path(CONF_DOXYGEN_OUTPUT_DIR CMAKE_CURRENT_BINARY_DIR DOXYGEN_OUTPUT_DIR)

        set(DOXYFILE_IN "${INPUT_DIR}/Doxyfile.in")
        set(DOXYFILE_OUT "${BUILD_OUTPUT}/source/Doxyfile")
        configure_file(${DOXYFILE_IN} ${DOXYFILE_OUT} @ONLY)

        add_custom_command(
            OUTPUT ${DOXYGEN_OUTPUT_FILE}
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYFILE_OUT}
            COMMENT "Generating documentation with Doxygen"
            DEPENDS ${DOXYFILE_OUT} ${${PROJECT_NAME_UPPERCASE}_SOURCES}
            VERBATIM)
        add_custom_target(doc_doxygen_${PROJECT_NAME} ALL SOURCES ${DOXYGEN_OUTPUT_FILE})

        if(${PROJECT_NAME_UPPERCASE}_ENABLE_INSTALL)
            install(DIRECTORY "${DOXYGEN_OUTPUT}/"
                DESTINATION "${${PROJECT_NAME_UPPERCASE}_INSTALL_DOC_DIR}/doxygen")
        endif()

        if(PYTHONINTERP_FOUND AND BREATHE_EXECUTABLE AND SPHINX_EXECUTABLE)
            set(BREATHE_OUTPUT_DIR "${BUILD_OUTPUT}/breathe")
            set(BREATHE_OUTPUT_FILE "${BREATHE_OUTPUT_DIR}/classlist.rst")

            set(SPHINX_OUTPUT_DIR "${BUILD_OUTPUT}/sphinx/${OUTPUT_FORMAT}")
            if(OUTPUT_FORMAT STREQUAL "html")
                set(SPHINX_OUTPUT_FILE "${SPHINX_OUTPUT_DIR}/classlist.html")
            elseif(OUTPUT_FORMAT STREQUAL "latex")
                set(SPHINX_OUTPUT_FILE "${SPHINX_OUTPUT_DIR}/sphinx.sty")
            else()
                set(SPHINX_OUTPUT_FILE ${SPHINX_OUTPUT_DIR})
            endif()

            set(SPHINX_HTML_THEME ${HTML_THEME})
            set(SPHINX_THEME_DIR "${BUILD_OUTPUT}/_themes")

            execute_process(
                COMMAND ${PYTHON_EXECUTABLE} -c
                    "import breathe, os; print os.path.dirname(breathe.__file__)"
                OUTPUT_VARIABLE PYTHON_BREATHE_ROOT
                OUTPUT_STRIP_TRAILING_WHITESPACE)

            set(CONF_PY_IN "${INPUT_DIR}/conf.py.in")
            set(CONF_PY_OUT "${BUILD_OUTPUT}/source/conf.py")
            configure_file(${CONF_PY_IN} ${CONF_PY_OUT} @ONLY)

            set(CONTENTS_IN "${INPUT_DIR}/contents.rst")
            set(CONTENTS_OUT "${BREATHE_OUTPUT_DIR}/contents.rst")
            configure_file(${CONTENTS_IN} ${CONTENTS_OUT} COPYONLY)

            add_custom_command(
                OUTPUT ${BREATHE_OUTPUT_FILE}
                COMMAND ${BREATHE_EXECUTABLE} -o ${BREATHE_OUTPUT_DIR} "${DOXYGEN_OUTPUT_DIR}/xml"
                COMMENT "Generating documentation with Breathe"
                DEPENDS doc_doxygen_${PROJECT_NAME} ${DOXYGEN_OUTPUT_FILE}
                VERBATIM)
            add_custom_target(doc_breathe_${PROJECT_NAME} ALL SOURCES ${BREATHE_OUTPUT_FILE})

            add_custom_command(
                OUTPUT "${SPHINX_OUTPUT_FILE}"
                COMMAND ${SPHINX_EXECUTABLE} -b ${OUTPUT_FORMAT}
                    -c "${BUILD_OUTPUT}/source" ${BREATHE_OUTPUT_DIR} ${SPHINX_OUTPUT_DIR}
                COMMENT "Generating documentation with Sphinx"
                DEPENDS doc_breathe_${PROJECT_NAME} ${DOXYGEN_OUTPUT_FILE} ${CONF_PY_OUT} ${CONTENTS_OUT}
                VERBATIM)
            add_custom_target(doc_sphinx_${OUTPUT_FORMAT}_${PROJECT_NAME} ALL SOURCES ${SPHINX_OUTPUT_FILE})

            download_project(${HTML_THEME})

            if(${PROJECT_NAME_UPPERCASE}_ENABLE_INSTALL)
                install(DIRECTORY "${SPHINX_OUTPUT}/"
                    DESTINATION "${${PROJECT_NAME_UPPERCASE}_INSTALL_DOC_DIR}/sphinx")
            endif()
        endif()
    endif()

endfunction(setup_documentation)

#===================================================================================================
#
#   setup_installation([DATA_DIR <path>]
#                      [VAR_DIR <path>]
#                      [INCLUDE_DIRS <path>...]
#                      [TARGETS <name>...])
#
#===================================================================================================
function(setup_installation)

    set(options)
    set(oneValueArgs DATA_DIR VAR_DIR)
    set(multiValueArgs INCLUDE_DIRS TARGETS)

    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    if(EXISTS ${${PROJECT_NAME}_CONFIG_FILE_IN})
        configure_file("${${PROJECT_NAME}_CONFIG_FILE_IN}"
            "${${PROJECT_NAME}_CONFIG_FILE_NAME}" @ONLY)
    endif()

    if(EXISTS ${${PROJECT_NAME}_VERSION_FILE_IN})
        configure_file("${${PROJECT_NAME}_VERSION_FILE_IN}"
            "${${PROJECT_NAME}_VERSION_FILE_NAME}" @ONLY)
    endif()

    if(${PROJECT_NAME_UPPERCASE}_ENABLE_INSTALL)
        get_path_default(DATA_DIR ARG_DATA_DIR "data" ${CMAKE_CURRENT_SOURCE_DIR})
        get_path_default(VAR_DIR ARG_VAR_DIR "var" ${CMAKE_CURRENT_SOURCE_DIR})

        if(EXISTS "${DATA_DIR}")
            install(DIRECTORY "${DATA_DIR}/"
                DESTINATION "${${PROJECT_NAME_UPPERCASE}_INSTALL_DATA_DIR}")
        endif()
        if(EXISTS "${VAR_DIR}")
            install(DIRECTORY "${VAR_DIR}/"
                DESTINATION "${${PROJECT_NAME_UPPERCASE}_INSTALL_VAR_DIR}")
        endif()

        set(PATH_VARS)
        list(LENGTH ARG_INCLUDE_DIRS TOTAL)
        foreach(index RANGE ${TOTAL})
            list(GET ARG_INCLUDE_DIRS index INCLUDE_DIR${index})
            list(APPEND PATH_VARS INCLUDE_DIR${index})
        endforeach()
        if(NOT PATH_VARS)
            install_project(TARGETS ${ARG_TARGETS} KEEP_PUBLIC_HEADER_HIERARCHY)
        else()
            install_project(TARGETS ${ARG_TARGETS}
                PATH_VARS ${PATH_VARS} KEEP_PUBLIC_HEADER_HIERARCHY)
        endif()
    endif()

endfunction(setup_installation)

#===================================================================================================
#
#   setup_target(NAME <target>
#                [INCLUDE_DIRS <path>...]
#                [EXTRA_SOURCES <path>...]
#                [EXCLUDE_SOURCES <path>...]
#                [SOURCE_PREFIXES <path>...]
#                [EXCLUDE_PREFIXES <path>...]
#                [EXPORT_FILE_NAME <path>]
#                [OPTIONS [PUBLIC <def>...] [PRIVATE <def>...] [INTERFACE <def>...]]
#                [DEFINITIONS [PUBLIC <def>...] [PRIVATE <def>...] [INTERFACE <def>...]]
#                [DEPENDENCIES [
#                   [INCLUDE <mode>] [LINK <mode>]
#                   [<CUSTOM|INTERNAL|EXTERNAL>] <package-params>...
#                   [USE_TARGETS <target>...]
#                   [ONLY_IF <expr>...] END]...]
#                [IS_LIBRARY|IS_TEST|IS_EXAMPLE|HEADER_ONLY|NO_SHARED|NO_LINK|TEST_NO_SHARED])
#
#===================================================================================================
macro(setup_target_listings)

    if(NOT ${TARGET_NAME}_SOURCES)
        foreach(prefix ${TARGET_SOURCE_PREFIXES})
            file(STRINGS "${PROJECT_SOURCE_DIR}/SOURCES" SOURCES REGEX ".*${prefix}[/\\].*")
            list(APPEND TARGET_SOURCES ${SOURCES})
            if(TARGET_IS_LIBRARY)
                file(STRINGS "${PROJECT_SOURCE_DIR}/PUBLIC_HEADERS"
                    PUBLIC_HEADERS REGEX ".*${prefix}[/\\].*")
                list(APPEND TARGET_PUBLIC_HEADERS ${PUBLIC_HEADERS})
            endif()
        endforeach()
        exclude_from_listing(TARGET_SOURCES TARGET_EXCLUDE_PREFIXES TARGET_EXCLUDE_SOURCES)
        exclude_from_listing(TARGET_PUBLIC_HEADERS TARGET_EXCLUDE_PREFIXES TARGET_EXCLUDE_SOURCES)
    else()
        set(TARGET_SOURCES ${${TARGET_NAME}_SOURCES})
    endif()

    list(APPEND TARGET_SOURCES ${TARGET_EXTRA_SOURCES})

    if(NOT TARGET_IS_TEST AND NOT TARGET_IS_EXAMPLE)
        list(APPEND ${PROJECT_NAME_UPPERCASE}_SOURCES ${TARGET_SOURCES})
    endif()

    if(TARGET_IS_LIBRARY)
        if(EXISTS ${${PROJECT_NAME}_CONFIG_FILE_IN})
            list(APPEND TARGET_SOURCES ${${PROJECT_NAME}_CONFIG_FILE_NAME})
            list(APPEND TARGET_PUBLIC_HEADERS ${${PROJECT_NAME}_CONFIG_FILE_NAME})
        endif()

        if(EXISTS ${${PROJECT_NAME}_VERSION_FILE_IN})
            list(APPEND TARGET_SOURCES ${${PROJECT_NAME}_VERSION_FILE_NAME})
            list(APPEND TARGET_PUBLIC_HEADERS ${${PROJECT_NAME}_VERSION_FILE_NAME})
        endif()

        if(NOT TARGET_HEADER_ONLY)
            get_path_default(EXPORT_FILE_NAME TARGET_EXPORT_FILE_NAME
                "${TARGET_NAME}-export.h" ${CMAKE_CURRENT_BINARY_DIR})
            list(APPEND TARGET_SOURCES ${EXPORT_FILE_NAME})
            list(APPEND TARGET_PUBLIC_HEADERS ${EXPORT_FILE_NAME})
        endif()
    endif()

endmacro(setup_target_listings)

macro(setup_target_dependency)

    list(GET DEP_UNPARSED_ARGUMENTS 0 DEP_TYPE)
    if(DEP_TYPE STREQUAL "CUSTOM" OR DEP_TYPE STREQUAL "EXTERNAL")
        list(GET DEP_UNPARSED_ARGUMENTS 1 DEP_NAME)
        list(REMOVE_AT DEP_UNPARSED_ARGUMENTS 0)
    elseif(DEP_TYPE STREQUAL "INTERNAL")
        list(GET DEP_UNPARSED_ARGUMENTS 1 DEP_NAME)
        if(DEP_NAME MATCHES "\\$<(.*)>")
            set(DEP_NAME ${${CMAKE_MATCH_1}})
        endif()
    else()
        set(DEP_NAME ${DEP_TYPE})
    endif()

    string(TOUPPER ${DEP_NAME} DEP_NAME_UPPERCASE)

    if(DEP_TYPE STREQUAL "EXTERNAL")
        download_project(${DEP_NAME})
    elseif(NOT ${DEP_NAME}_FOUND AND NOT ${DEP_NAME_UPPERCASE}_FOUND)
        if(DEP_TYPE STREQUAL "CUSTOM")
            find_custom_package(NAME ${DEP_UNPARSED_ARGUMENTS})
        elseif(DEP_TYPE STREQUAL "INTERNAL")
            set(${DEP_NAME}_LIBRARIES ${DEP_NAME} CACHE INTERNAL "")
            set(${DEP_NAME}_FOUND TRUE CACHE INTERNAL "")
        else()
            find_package(${DEP_UNPARSED_ARGUMENTS})
        endif()
    endif()

    if(${DEP_NAME}_FOUND OR ${DEP_NAME_UPPERCASE}_FOUND)
        set(DEP_INCLUDE_DIRS
            ${${DEP_NAME}_INCLUDE_DIRS}
            ${${DEP_NAME}_INCLUDE_DIR}
            ${${DEP_NAME_UPPERCASE}_INCLUDE_DIRS}
            ${${DEP_NAME_UPPERCASE}_INCLUDE_DIR})

        if(NOT DEP_USE_TARGETS)
            set(DEP_LIBRARIES
                ${${DEP_NAME}_LIBRARIES}
                ${${DEP_NAME}_LIBRARY}
                ${${DEP_NAME_UPPERCASE}_LIBRARIES}
                ${${DEP_NAME_UPPERCASE}_LIBRARY})
        else()
            foreach(target ${DEP_USE_TARGETS})
                list(APPEND DEP_LIBRARIES ${target})
            endforeach()
        endif()

        if(NOT DEP_INCLUDE OR DEP_INCLUDE STREQUAL "PRIVATE")
            list(APPEND TARGET_PRIVATE_INCLUDE_DIRS ${DEP_INCLUDE_DIRS})
        elseif(DEP_INCLUDE STREQUAL "PUBLIC")
            list(APPEND TARGET_PUBLIC_INCLUDE_DIRS ${DEP_INCLUDE_DIRS})
        elseif(DEP_INCLUDE STREQUAL "INTERFACE")
            list(APPEND TARGET_INTERFACE_INCLUDE_DIRS ${DEP_INCLUDE_DIRS})
        endif()

        if(NOT DEP_LINK OR DEP_LINK STREQUAL "PUBLIC")
            list(APPEND TARGET_PUBLIC_LIBRARIES ${DEP_LIBRARIES})
        elseif(DEP_LINK STREQUAL "PRIVATE")
            list(APPEND TARGET_PRIVATE_LIBRARIES ${DEP_LIBRARIES})
        elseif(DEP_LINK STREQUAL "INTERFACE")
            list(APPEND TARGET_INTERFACE_LIBRARIES ${DEP_LIBRARIES})
        endif()
    endif()

endmacro(setup_target_dependency)

macro(setup_target_dependencies)

    set(TARGET_PUBLIC_INCLUDE_DIRS "")
    set(TARGET_PRIVATE_INCLUDE_DIRS "")
    set(TARGET_INTERFACE_INCLUDE_DIRS "")
    set(TARGET_PUBLIC_LIBRARIES "")
    set(TARGET_PRIVATE_LIBRARIES "")
    set(TARGET_INTERFACE_LIBRARIES "")

    set(CURRENT_DEP)
    foreach(dep ${TARGET_DEPENDENCIES})
        if(dep STREQUAL "END")
            set(options)
            set(oneValueArgs INCLUDE LINK)
            set(multiValueArgs ONLY_IF USE_TARGETS)
            cmake_parse_arguments(DEP
                "${options}" "${oneValueArgs}" "${multiValueArgs}" ${CURRENT_DEP})
            if(NOT DEP_ONLY_IF)
                setup_target_dependency()
            elseif(${DEP_ONLY_IF})
                setup_target_dependency()
            endif()
            set(CURRENT_DEP)
        else()
            list(APPEND CURRENT_DEP ${dep})
        endif()
    endforeach()

    if(TARGET_PUBLIC_INCLUDE_DIRS)
        list(REMOVE_DUPLICATES TARGET_PUBLIC_INCLUDE_DIRS)
    endif()
    if(TARGET_PRIVATE_INCLUDE_DIRS)
        list(REMOVE_DUPLICATES TARGET_PRIVATE_INCLUDE_DIRS)
    endif()
    if(TARGET_INTERFACE_INCLUDE_DIRS)
        list(REMOVE_DUPLICATES TARGET_INTERFACE_INCLUDE_DIRS)
    endif()
    if(TARGET_PUBLIC_LIBRARIES)
        list(REMOVE_DUPLICATES TARGET_PUBLIC_LIBRARIES)
    endif()
    if(TARGET_PRIVATE_LIBRARIES)
        list(REMOVE_DUPLICATES TARGET_PRIVATE_LIBRARIES)
    endif()
    if(TARGET_INTERFACE_LIBRARIES)
        list(REMOVE_DUPLICATES TARGET_INTERFACE_LIBRARIES)
    endif()

endmacro(setup_target_dependencies)

macro(setup_target_flags)

    set(options)
    set(oneValueArgs)
    set(multiValueArgs PUBLIC PRIVATE INTERFACE)

    cmake_parse_arguments(TARGET_OPTIONS
        "${options}" "${oneValueArgs}" "${multiValueArgs}" ${TARGET_OPTIONS})

    cmake_parse_arguments(TARGET_DEFINITIONS
        "${options}" "${oneValueArgs}" "${multiValueArgs}" ${TARGET_DEFINITIONS})

endmacro(setup_target_flags)

macro(setup_target_target)

    if(NOT TARGET_IS_LIBRARY)
        if(TARGET_NO_LINK)
            add_library(${TARGET_NAME} OBJECT ${TARGET_SOURCES})
        else()
            add_executable(${TARGET_NAME} ${TARGET_SOURCES})
        endif()
        set_target_properties(${TARGET_NAME} PROPERTIES
            CXX_VISIBILITY_PRESET hidden
            VISIBILITY_INLINES_HIDDEN 1
            RUNTIME_OUTPUT_DIRECTORY
                "${CMAKE_BINARY_DIR}/${${PROJECT_NAME_UPPERCASE}_OUTPUT_BIN_DIR}")
        if(TARGET_IS_TEST)
            add_test(NAME ${TARGET_NAME} COMMAND ${TARGET_NAME})
        endif()
    elseif(TARGET_HEADER_ONLY)
        add_library(${TARGET_NAME} INTERFACE)
        set(TARGET_SOURCES_ABSOLUTE "")
        foreach(source ${TARGET_SOURCES})
            if(NOT IS_ABSOLUTE ${source})
                get_filename_component(source ${source} ABSOLUTE)
            endif()
            list(APPEND TARGET_SOURCES_ABSOLUTE "$<BUILD_INTERFACE:${source}>")
        endforeach()
        target_sources(${TARGET_NAME} INTERFACE ${TARGET_SOURCES_ABSOLUTE})
        set_target_properties(${TARGET_NAME} PROPERTIES
            INTERFACE_PUBLIC_HEADER "${TARGET_PUBLIC_HEADERS}")
    elseif(TARGET_NO_SHARED AND BUILD_SHARED_LIBS)
        message(FATAL_ERROR "Cannot build shared version of ${TARGET_NAME}.")
    elseif(TARGET_TEST_NO_SHARED AND BUILD_SHARED_LIBS AND BUILD_TESTING)
        message(FATAL_ERROR "Cannot build tests using shared version of ${TARGET_NAME}.")
    else()
        add_library(${TARGET_NAME} ${TARGET_SOURCES})
        set_target_properties(${TARGET_NAME} PROPERTIES
            CXX_VISIBILITY_PRESET hidden
            VISIBILITY_INLINES_HIDDEN 1
            VERSION ${PROJECT_VERSION}
            SOVERSION ${PROJECT_VERSION_MAJOR}
            PUBLIC_HEADER "${TARGET_PUBLIC_HEADERS}"
            INTERFACE_${TARGET_NAME}_MAJOR_VERSION ${PROJECT_VERSION_MAJOR}
            ARCHIVE_OUTPUT_DIRECTORY
                "${CMAKE_BINARY_DIR}/${${PROJECT_NAME_UPPERCASE}_OUTPUT_LIB_DIR}"
            LIBRARY_OUTPUT_DIRECTORY
                "${CMAKE_BINARY_DIR}/${${PROJECT_NAME_UPPERCASE}_OUTPUT_LIB_DIR}"
            RUNTIME_OUTPUT_DIRECTORY
                "${CMAKE_BINARY_DIR}/${${PROJECT_NAME_UPPERCASE}_OUTPUT_BIN_DIR}")

        set_property(TARGET ${TARGET_NAME}
            APPEND PROPERTY COMPATIBLE_INTERFACE_STRING ${TARGET_NAME}_MAJOR_VERSION)
    endif()

    if(NOT TARGET_HEADER_ONLY)
        target_compile_options(${TARGET_NAME} PUBLIC ${TARGET_OPTIONS_PUBLIC})
        target_compile_options(${TARGET_NAME} PRIVATE ${TARGET_OPTIONS_PRIVATE})
        target_compile_definitions(${TARGET_NAME} PUBLIC ${TARGET_DEFINITIONS_PUBLIC})
        target_compile_definitions(${TARGET_NAME} PRIVATE ${TARGET_DEFINITIONS_PRIVATE})
        target_include_directories(${TARGET_NAME} SYSTEM PUBLIC ${TARGET_PUBLIC_INCLUDE_DIRS})
        target_include_directories(${TARGET_NAME} SYSTEM PRIVATE ${TARGET_PRIVATE_INCLUDE_DIRS})
        target_include_directories(${TARGET_NAME} PUBLIC ${TARGET_INCLUDE_DIRS})
        if(NOT TARGET_NO_LINK)
            target_link_libraries(${TARGET_NAME} PUBLIC ${TARGET_PUBLIC_LIBRARIES})
            target_link_libraries(${TARGET_NAME} PRIVATE ${TARGET_PRIVATE_LIBRARIES})
        endif()
    else()
        target_include_directories(${TARGET_NAME} INTERFACE ${TARGET_INCLUDE_DIRS})
    endif()
    target_compile_options(${TARGET_NAME} INTERFACE ${TARGET_OPTIONS_INTERFACE})
    target_compile_definitions(${TARGET_NAME} INTERFACE ${TARGET_DEFINITIONS_INTERFACE})
    target_include_directories(${TARGET_NAME} SYSTEM INTERFACE ${TARGET_INTERFACE_INCLUDE_DIRS})
    if(NOT TARGET_NO_LINK)
        target_link_libraries(${TARGET_NAME} INTERFACE ${TARGET_INTERFACE_LIBRARIES})
    endif()

    if(NOT TARGET_HEADER_ONLY AND ${PROJECT_NAME_UPPERCASE}_ENABLE_PCH)
        set_target_properties(${TARGET_NAME} PROPERTIES COTIRE_ADD_UNITY_BUILD FALSE)
        cotire(${TARGET_NAME})
    endif()

endmacro(setup_target_target)

macro(setup_target_export)

    if(TARGET_IS_LIBRARY AND NOT TARGET_HEADER_ONLY)
        if(${PROJECT_NAME}_EXCLUDE_DEPRECATED)
            set(NO_BUILD_DEPRECATED DEFINE_NO_DEPRECATED)
        endif()
        generate_export_header(${TARGET_NAME}
            ${NO_BUILD_DEPRECATED} EXPORT_FILE_NAME ${EXPORT_FILE_NAME})
    endif()

endmacro(setup_target_export)

function(setup_target)

    set(options IS_LIBRARY IS_TEST IS_EXAMPLE HEADER_ONLY NO_SHARED NO_LINK TEST_NO_SHARED)
    set(oneValueArgs NAME EXPORT_FILE_NAME)
    set(multiValueArgs
        EXTRA_SOURCES
        EXCLUDE_SOURCES
        SOURCE_PREFIXES
        EXCLUDE_PREFIXES
        OPTIONS
        DEFINITIONS
        INCLUDE_DIRS
        DEPENDENCIES)

    cmake_parse_arguments(TARGET "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    setup_target_listings()
    setup_target_dependencies()
    setup_target_flags()
    setup_target_target()
    setup_target_export()

    set(${PROJECT_NAME_UPPERCASE}_SOURCES ${${PROJECT_NAME_UPPERCASE}_SOURCES} PARENT_SCOPE)

endfunction(setup_target)

#===================================================================================================
#
#   setup_tests(NAME <name>
#               [INPUT_DATA_DIRS <path>...]
#               [OUTPUT_DATA_DIR <path>]
#               [INCLUDE_DIRS <path>...]
#               [EXTRA_SOURCES <path>...]
#               [EXCLUDE_SOURCES <path>...]
#               [SOURCE_PREFIXES <path>...]
#               [EXCLUDE_PREFIXES <path>...]
#               [OPTIONS [PUBLIC <def>...] [PRIVATE <def>...] [INTERFACE <def>...]]
#               [DEFINITIONS [PUBLIC <def>...] [PRIVATE <def>...] [INTERFACE <def>...]]
#               [DEPENDENCIES [
#                   [INCLUDE <mode>] [LINK <mode>]
#                   [<CUSTOM|INTERNAL|EXTERNAL>] <package-params>...
#                   [ONLY_IF <expr>...] [USE_TARGETS <var>...] END]...]
#               [ONE_PER_FILE])
#
#===================================================================================================
macro(setup_tests_listings)

    foreach(prefix ${ARG_SOURCE_PREFIXES})
        file(STRINGS "${PROJECT_SOURCE_DIR}/SOURCES" SOURCES REGEX ".*${prefix}[/\\].*")
        list(APPEND ${ARG_NAME}_TEST_SOURCES ${SOURCES})
    endforeach()
    exclude_from_listing(${ARG_NAME}_TEST_SOURCES ARG_EXCLUDE_PREFIXES ARG_EXCLUDE_SOURCES)
    list(APPEND ${ARG_NAME}_TEST_SOURCES ${ARG_EXTRA_SOURCES})

    foreach(source ${${ARG_NAME}_TEST_SOURCES})
        foreach(prefix ${ARG_SOURCE_PREFIXES})
            if(source MATCHES ".*${prefix}[/\\](.*)$")
                set(TEST_NAME ${CMAKE_MATCH_1})
                break()
            endif()
        endforeach()

        get_filename_component(DIR ${TEST_NAME} DIRECTORY)
        if(DIR)
            string(REPLACE "/" "_" DIR ${DIR})
            set(DIR "_${DIR}")
        endif()
        if(ARG_ONE_PER_FILE)
            get_filename_component(NAME ${TEST_NAME} NAME_WE)
            set(TEST_NAME "test_${ARG_NAME}${DIR}_${NAME}")
        else()
            set(TEST_NAME "tests_${ARG_NAME}${DIR}")
        endif()
        list(APPEND ${TEST_NAME}_SOURCES ${source})

        if(NOT ${TEST_NAME} IN_LIST ${ARG_NAME}_TESTS)
            list(APPEND ${ARG_NAME}_TESTS ${TEST_NAME})
        endif()
    endforeach()

endmacro(setup_tests_listings)

macro(setup_tests_flags)

    set(options)
    set(oneValueArgs)
    set(multiValueArgs PUBLIC PRIVATE INTERFACE)

    cmake_parse_arguments(ARG_OPTIONS
        "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARG_OPTIONS})

    cmake_parse_arguments(ARG_DEFINITIONS
        "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARG_DEFINITIONS})

endmacro(setup_tests_flags)

macro(setup_tests_data)

    get_path_default(OUTPUT_DATA_DIR ARG_OUTPUT_DATA_DIR "data" ${CMAKE_CURRENT_BINARY_DIR})
    list(APPEND ARG_DEFINITIONS_PRIVATE -DDATADIR="${OUTPUT_DATA_DIR}")

    if (NOT ARG_INPUT_DATA_DIRS)
        list(APPEND ARG_INPUT_DATA_DIRS "tests/data")
    endif()

    message(STATUS "Copying ${ARG_NAME} test data files to build tree...")
    foreach(data_dir ${ARG_INPUT_DATA_DIRS})
        if(NOT IS_ABSOLUTE "${data_dir}")
            set(data_dir "${CMAKE_CURRENT_SOURCE_DIR}/${data_dir}")
        endif()
        if(EXISTS "${data_dir}")
            file(COPY "${data_dir}/" DESTINATION "${OUTPUT_DATA_DIR}")
        endif()
    endforeach()

endmacro(setup_tests_data)

macro(setup_tests_targets)

    foreach(test_name ${${ARG_NAME}_TESTS})
        setup_target(
            NAME ${test_name}
            INCLUDE_DIRS
                ${ARG_INCLUDE_DIRS}
            EXTRA_SOURCES
                ${ARG_EXTRA_SOURCES}
            EXCLUDE_SOURCES
                ${ARG_EXCLUDE_SOURCES}
            OPTIONS
                PUBLIC ${ARG_OPTIONS_PUBLIC}
                PRIVATE ${ARG_OPTIONS_PRIVATE}
            DEFINITIONS
                PUBLIC ${ARG_DEFINITIONS_PUBLIC}
                PRIVATE ${ARG_DEFINITIONS_PRIVATE}
            DEPENDENCIES ${ARG_DEPENDENCIES}
            IS_TEST)
    endforeach()

endmacro(setup_tests_targets)

function(setup_tests)

    if(NOT BUILD_TESTING)
        return()
    endif()

    set(options ONE_PER_FILE)
    set(oneValueArgs NAME OUTPUT_DATA_DIR)
    set(multiValueArgs
        INPUT_DATA_DIRS
        EXTRA_SOURCES
        EXCLUDE_SOURCES
        SOURCE_PREFIXES
        EXCLUDE_PREFIXES
        OPTIONS
        DEFINITIONS
        INCLUDE_DIRS
        DEPENDENCIES)

    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    setup_tests_listings()
    setup_tests_flags()
    setup_tests_data()
    setup_tests_targets()

endfunction(setup_tests)

#===================================================================================================
#
#   setup_examples(NAME <name>
#                  [INCLUDE_DIRS <path>...]
#                  [EXTRA_SOURCES <path>...]
#                  [EXCLUDE_SOURCES <path>...]
#                  [SOURCE_PREFIXES <path>...]
#                  [EXCLUDE_PREFIXES <path>...]
#                  [OPTIONS [PUBLIC <def>...] [PRIVATE <def>...] [INTERFACE <def>...]]
#                  [DEFINITIONS [PUBLIC <def>...] [PRIVATE <def>...] [INTERFACE <def>...]]
#                  [DEPENDENCIES [
#                      [INCLUDE <mode>] [LINK <mode>]
#                      [<CUSTOM|INTERNAL|EXTERNAL>] <package-params>...
#                      [ONLY_IF <expr>...] [USE_TARGETS <var>...] END]...]
#                  [NO_LINK|ONE_PER_FILE])
#
#===================================================================================================
macro(setup_examples_listings)

    foreach(prefix ${ARG_SOURCE_PREFIXES})
        file(STRINGS "${PROJECT_SOURCE_DIR}/SOURCES" SOURCES REGEX ".*${prefix}[/\\].*")
        list(APPEND ${ARG_NAME}_EXAMPLE_SOURCES ${SOURCES})
    endforeach()
    exclude_from_listing(${ARG_NAME}_EXAMPLE_SOURCES ARG_EXCLUDE_PREFIXES ARG_EXCLUDE_SOURCES)
    list(APPEND ${ARG_NAME}_EXAMPLE_SOURCES ${ARG_EXTRA_SOURCES})

    foreach(source ${${ARG_NAME}_EXAMPLE_SOURCES})
        foreach(prefix ${ARG_SOURCE_PREFIXES})
            if(source MATCHES ".*${prefix}[/\\](.*)$")
                set(EXAMPLE_NAME ${CMAKE_MATCH_1})
                break()
            endif()
        endforeach()

        get_filename_component(DIR ${EXAMPLE_NAME} DIRECTORY)
        if(DIR)
            string(REPLACE "/" "_" DIR ${DIR})
            set(DIR "_${DIR}")
        endif()
        if(ARG_ONE_PER_FILE)
            get_filename_component(NAME ${EXAMPLE_NAME} NAME_WE)
            set(EXAMPLE_NAME "example_${ARG_NAME}${DIR}_${NAME}")
        else()
            set(EXAMPLE_NAME "examples_${ARG_NAME}${DIR}")
        endif()
        list(APPEND ${EXAMPLE_NAME}_SOURCES ${source})

        if(NOT ${EXAMPLE_NAME} IN_LIST ${ARG_NAME}_EXAMPLES)
            list(APPEND ${ARG_NAME}_EXAMPLES ${EXAMPLE_NAME})
        endif()
    endforeach()

endmacro(setup_examples_listings)

macro(setup_examples_flags)

    set(options)
    set(oneValueArgs)
    set(multiValueArgs PUBLIC PRIVATE INTERFACE)

    cmake_parse_arguments(ARG_OPTIONS
        "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARG_OPTIONS})

    cmake_parse_arguments(ARG_DEFINITIONS
        "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARG_DEFINITIONS})

    if(ARG_NO_LINK)
        set(ARG_NO_LINK NO_LINK)
    else()
        set(ARG_NO_LINK "")
    endif()

endmacro(setup_examples_flags)

macro(setup_examples_targets)

    foreach(example_name ${${ARG_NAME}_EXAMPLES})
        setup_target(
            NAME ${example_name}
            INCLUDE_DIRS
                ${ARG_INCLUDE_DIRS}
            EXTRA_SOURCES
                ${ARG_EXTRA_SOURCES}
            EXCLUDE_SOURCES
                ${ARG_EXCLUDE_SOURCES}
            OPTIONS
                PUBLIC ${ARG_OPTIONS_PUBLIC}
                PRIVATE ${ARG_OPTIONS_PRIVATE}
            DEFINITIONS
                PUBLIC ${ARG_DEFINITIONS_PUBLIC}
                PRIVATE ${ARG_DEFINITIONS_PRIVATE}
            DEPENDENCIES ${ARG_DEPENDENCIES}
            IS_EXAMPLE ${ARG_NO_LINK})
    endforeach()

endmacro(setup_examples_targets)

function(setup_examples)

    if(NOT ${PROJECT_NAME_UPPERCASE}_BUILD_EXAMPLES)
        return()
    endif()

    set(options NO_LINK ONE_PER_FILE)
    set(oneValueArgs NAME)
    set(multiValueArgs
        EXTRA_SOURCES
        EXCLUDE_SOURCES
        SOURCE_PREFIXES
        EXCLUDE_PREFIXES
        OPTIONS
        DEFINITIONS
        INCLUDE_DIRS
        DEPENDENCIES)

    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    setup_examples_listings()
    setup_examples_flags()
    setup_examples_targets()

endfunction(setup_examples)
