cmake_minimum_required(VERSION 3.5)

include(ExternalProject)

ExternalProject_Add(sphinx_rtd_theme
    GIT_REPOSITORY "https://github.com/rtfd/sphinx_rtd_theme.git"
    GIT_TAG master
    UPDATE_DISCONNECTED 1
    PREFIX .
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
    TEST_COMMAND ""
)
