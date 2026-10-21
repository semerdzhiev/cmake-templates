cmake_minimum_required(VERSION 3.24)

project(MyProject VERSION 1.1 LANGUAGES CXX)

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
