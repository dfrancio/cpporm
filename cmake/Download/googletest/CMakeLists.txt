cmake_minimum_required(VERSION 3.5)

include(ExternalProject)

ExternalProject_Add(
    googletest
    GIT_REPOSITORY "https://github.com/google/googletest.git"
    GIT_TAG master
    PREFIX .
    UPDATE_DISCONNECTED 1
    CMAKE_ARGS
        -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
        -DBUILD_SHARED_LIBS=ON
        -Dgtest_disable_pthreads=ON
        -Wno-dev
)
