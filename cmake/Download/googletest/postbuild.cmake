if(WIN32)
    set(gtest_disable_pthreads ON CACHE INTERNAL "")
endif()

FILE(READ ${googletest_DIR}/src/googletest/CMakeLists.txt CONTENT)
if(NOT CONTENT MATCHES "cmake_policy")
    STRING(REGEX REPLACE "(cmake_minimum_required[^\n]*)" "\\1\ncmake_policy(SET CMP0048 NEW)" CONTENT ${CONTENT})
    FILE(WRITE ${googletest_DIR}/src/googletest/CMakeLists.txt ${CONTENT})
endif()

if(APPLE)
    FILE(READ ${googletest_DIR}/src/googletest/googletest/CMakeLists.txt CONTENT)
    if(NOT CONTENT MATCHES "cmake_policy")
        STRING(REGEX REPLACE "(cmake_minimum_required[^\n]*)" "\\1\ncmake_policy(SET CMP0042 NEW)" CONTENT ${CONTENT})
        FILE(WRITE ${googletest_DIR}/src/googletest/googletest/CMakeLists.txt ${CONTENT})
    endif()

    FILE(READ ${googletest_DIR}/src/googletest/googlemock/CMakeLists.txt CONTENT)
    if(NOT CONTENT MATCHES "cmake_policy")
        STRING(REGEX REPLACE "(cmake_minimum_required[^\n]*)" "\\1\ncmake_policy(SET CMP0042 NEW)" CONTENT ${CONTENT})
        FILE(WRITE ${googletest_DIR}/src/googletest/googlemock/CMakeLists.txt ${CONTENT})
    endif()
endif()

add_subdirectory(${googletest_DIR}/src/googletest
                 ${googletest_DIR}/src/googletest-build
                 EXCLUDE_FROM_ALL)
