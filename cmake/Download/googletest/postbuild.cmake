
if(WIN32)
    set(EXTENSION ".dll.a")
elseif(APPLE)
    set(EXTENSION ".dylib")
else()
    set(EXTENSION ".so")
endif()

set(GMOCK_INCLUDE_DIR "${CMAKE_BINARY_DIR}/googletest/include")
set(GMOCK_LIB "${CMAKE_BINARY_DIR}/googletest/lib/libgmock${EXTENSION}")
set(GMOCK_MAIN_LIB "${CMAKE_BINARY_DIR}/googletest/lib/libgmock_main${EXTENSION}")

set(googletest_INCLUDE_DIR ${GMOCK_INCLUDE_DIR} CACHE INTERNAL "")
set(googletest_INCLUDE_DIRS ${GMOCK_INCLUDE_DIR} CACHE STRING "" FORCE)
set(googletest_LIBRARY ${GMOCK_LIB} CACHE INTERNAL "")
set(googletest_LIBRARIES ${GMOCK_LIB} CACHE STRING "" FORCE)
set(googletest_MAIN_LIBRARY ${GMOCK_MAIN_LIB} CACHE INTERNAL "")
set(googletest_MAIN_LIBRARIES ${GMOCK_MAIN_LIB} CACHE STRING "" FORCE)

if(WIN32)
    file(COPY
        "${CMAKE_BINARY_DIR}/googletest/lib/libgmock.dll"
        "${CMAKE_BINARY_DIR}/googletest/lib/libgmock_main.dll"
        DESTINATION ${${PROJECT_NAME_UPPERCASE}_OUTPUT_BIN_DIR})
endif()
