if(WIN32)
    set(gtest_disable_pthreads ON CACHE INTERNAL "")
endif()

FILE(READ ${googletest_DIR}/src/googletest/CMakeLists.txt CONTENT)
if(NOT CONTENT MATCHES "cmake_policy")
    STRING(REGEX REPLACE "project\\(" "cmake_policy(SET CMP0048 NEW)\nproject(" CONTENT ${CONTENT})
    FILE(WRITE ${googletest_DIR}/src/googletest/CMakeLists.txt ${CONTENT})
endif()

add_subdirectory(${googletest_DIR}/src/googletest
                 ${googletest_DIR}/src/googletest-build)

set(googletest_INCLUDE_DIR
    "${gmock_SOURCE_DIR}/include"
    "${gtest_SOURCE_DIR}/include"
    CACHE INTERNAL "")
set(googletest_INCLUDE_DIRS ${googletest_INCLUDE_DIR} CACHE INTERNAL "")
set(googletest_LIBRARY gmock CACHE INTERNAL "")
set(googletest_LIBRARIES gmock CACHE INTERNAL "")
set(googletest_MAIN_LIBRARY gmock_main CACHE INTERNAL "")
set(googletest_MAIN_LIBRARIES gmock_main CACHE INTERNAL "")
set(googletest_FOUND TRUE CACHE INTERNAL "")
