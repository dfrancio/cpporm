if(WIN32)
    set(gtest_disable_pthreads ON CACHE INTERNAL "")
endif()
message(STATUS ${googletest_DIR})
add_subdirectory(${googletest_DIR}/src/googletest
                 ${googletest_DIR}/src/googletest-build)

set(googletest_INCLUDE_DIR
    "${gmock_SOURCE_DIR}/include"
    "${gtest_SOURCE_DIR}/include"
    CACHE INTERNAL "")
set(googletest_INCLUDE_DIRS ${googletest_INCLUDE_DIR} CACHE STRING "" FORCE)
set(googletest_LIBRARY gmock CACHE INTERNAL "")
set(googletest_LIBRARIES gmock CACHE STRING "" FORCE)
set(googletest_MAIN_LIBRARY gmock_main CACHE INTERNAL "")
set(googletest_MAIN_LIBRARIES gmock_main CACHE STRING "" FORCE)
