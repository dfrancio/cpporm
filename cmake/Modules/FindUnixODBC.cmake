# Copyright (c) 2008, OpenCog.org (http://opencog.org)
#
# Redistribution and use is allowed according to the terms of the BSD license.
# For details see the accompanying COPYING-CMAKE-SCRIPTS file.

# - Try to find the UnixODBC library; Once done this will define
#
# UNIXODBC_FOUND - system has the UnixODBC library
# UNIXODBC_INCLUDE_DIRS - the UnixODBC include directory
# UNIXODBC_LIBRARIES - The libraries needed to use UnixODBC

# If UnixODBC_ROOT_DIR was defined in the environment, use it.
IF(NOT UnixODBC_ROOT_DIR AND NOT $ENV{UnixODBC_ROOT_DIR} STREQUAL "")
    SET(UnixODBC_ROOT_DIR $ENV{UnixODBC_ROOT_DIR})
ENDIF()

SET(_UnixODBC_SEARCH_DIRS
    ${UnixODBC_ROOT_DIR}
    /usr
    /usr/local
    /sw # Fink
    /opt/local # DarwinPorts
    /opt/csw # Blastwave
)

# Look for the header file
FIND_PATH(UnixODBC_INCLUDE_DIR
  NAMES
    uodbc_stats.h
  HINTS
    ${_UnixODBC_SEARCH_DIRS}
  PATH_SUFFIXES
    include
    include/odbc
    include/libodbc
)

# Look for the library
FIND_LIBRARY(UnixODBC_LIBRARY
  NAMES
    odbc
  HINTS
    ${_UnixODBC_SEARCH_DIRS}
  PATH_SUFFIXES
    lib64 lib
)

# handle the QUIETLY and REQUIRED arguments and set UNIXODBC_FOUND to TRUE
INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(
    UnixODBC DEFAULT_MSG
    UnixODBC_LIBRARY
    UnixODBC_INCLUDE_DIR
)

IF(UNIXODBC_FOUND)
    SET(UNIXODBC_LIBRARIES ${UnixODBC_LIBRARY})
    SET(UNIXODBC_INCLUDE_DIRS ${UnixODBC_INCLUDE_DIR})
ENDIF(UNIXODBC_FOUND)

MARK_AS_ADVANCED(
    UnixODBC_LIBRARY
    UnixODBC_INCLUDE_DIR
)