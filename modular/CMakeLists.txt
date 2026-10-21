cmake_minimum_required(VERSION 3.24)

project(MyProject VERSION 1.1 LANGUAGES CXX)

# Project ID will be used as a prefix for all
# targets and their aliases.
# Since it is also used in the actual C++ code
# for namespaces and subdirs, make sure it
# is a valid C/C++ identifier.
# You can also set PROJECT_ID manually:
# set(PROJECT_ID "some_prefix")
string(TOLOWER "${CMAKE_PROJECT_NAME}" PROJECT_ID)
string(MAKE_C_IDENTIFIER "${PROJECT_ID}" PROJECT_ID)

# Shared build settings and general-purpose dependencies
include(cmake/ProjectSettings.cmake)
include(cmake/Dependencies.cmake)

# CTest defines BUILD_TESTING (ON by default) and calls enable_testing().
include(CTest)

if(BUILD_TESTING)
    include(cmake/Testing.cmake)
endif()

# Each module owns its targets and its tests.
add_subdirectory(modules)

# Application targets, kept separate from reusable modules.
add_subdirectory(apps)

# Documentation
option(MYPROJECT_BUILD_DOCS "Enable Doxygen documentation target" OFF)
if(MYPROJECT_BUILD_DOCS)
    add_subdirectory(docs)
endif()
