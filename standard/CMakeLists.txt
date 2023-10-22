cmake_minimum_required (VERSION 3.13)

# Project information and configuration
project ("CMake project template" VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Options and cache variables controlling how the project is built
option(ENABLE_TESTING "Specifies whether to enable unit testing for the project" ON)
option(ENABLE_DOCUMENTATION "Specifies whether to enable building the project documentation" ON)
option(ENABLE_TCLAP "Specifies whether to add TCLAPs include path" ON)

set(DOCUMENTATION_OUTPUT_PATH "${CMAKE_BINARY_DIR}/docs" CACHE FILEPATH "Specifies where to generate the documentation")

# Specifies that executables should be placed in the "/bin" subfolder of the output directory.
# Remove/comment this line below if you prefer to have the default behavior.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# Add include directories common to all targets.
# Generally speaking, using this is not a good idea.
# It is preferred to use target_include_directories() instead.
# However, for this folder sturcture and for the commonly used libraries, it makes things easier.
# Remove the line below and switch to another behavior if necessary.
include_directories("src")

if(ENABLE_TCLAP)
    message(STATUS "Add TCLAP to the list of include directories.")
    include_directories("lib/tclap/include")
endif()

# The `src` directory contains all project targets
add_subdirectory("src")

if(ENABLE_DOCUMENTATION)
    message(STATUS "Documentation building is enabled")
    add_subdirectory("docs")
endif()

if(ENABLE_TESTING)
    message(STATUS "Building of tests is enabled")
    add_subdirectory("lib/Catch2")
    list(APPEND CMAKE_MODULE_PATH "${Catch2_SOURCE_DIR}/extras")
    include(CTest)
    include(Catch)
    add_subdirectory("test")
endif()
