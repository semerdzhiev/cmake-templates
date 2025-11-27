cmake_minimum_required (VERSION 3.24)

project ("Simple CMake Template" VERSION 1.3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Makes it easier to display some useful info
include(CMakePrintHelpers)

# Get a list of all compile options
# Works only for generators that support this functionality.
# https://cmake.org/cmake/help/latest/variable/CMAKE_EXPORT_COMPILE_COMMANDS.html
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Uncomment the line below, if you want to specify additional
# locations to be searched by find_package and include.
# For example, a local cmake/ directory within the project, etc.
# list(PREPEND CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/cmake)

# Display some useful information
cmake_print_variables(CMAKE_MODULE_PATH)
cmake_print_variables(CMAKE_PREFIX_PATH)
cmake_print_variables(CMAKE_INSTALL_PREFIX)

# Custom modules are located in the ./cmake/ directory
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# Include the library finder module
include(FindOrFetch)


################################################################################
#
# Unit testing
#

# Configure the project for testing with CTest/CDash
# Automatically adds the BUILD_TESTING option and sets it to ON
# If BUILD_TESTING is ON, automatically calls enable_testing().
# Check the following resources for more info:
#   https://cmake.org/cmake/help/latest/module/CTest.html
#   https://cmake.org/cmake/help/latest/command/enable_testing.html
#   https://cmake.org/cmake/help/latest/manual/ctest.1.html
include(CTest)

if(BUILD_TESTING)

  # In this project we will be using Catch2.
  # Notes on CMake integration are provided in the documentation:
  #   https://github.com/catchorg/Catch2/blob/devel/docs/cmake-integration.md

  find_or_fetch_library(
    NAME           Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.9.1
  )

  # Status messages
  #cmake_print_variables(catch2_SOURCE_DIR)

  # Include the Catch module, which provides catch_discover_tests
  include(Catch)

endif()


################################################################################
#
# Additional libraries
#

# find_or_fetch_library(
#   NAME           TCLAP
#   GIT_REPOSITORY git://git.code.sf.net/p/tclap/code
#   GIT_TAG        77561f5fab620e0857a04c240ae981f679449e15
# )

# find_or_fetch_library(
#   NAME           spdlog
#   GIT_REPOSITORY git@github.com:gabime/spdlog.git
#   GIT_TAG        v1.16.0
# )


################################################################################
#
# Configuration settings which apply to all projects
# and are related to how they are being built.
#

#
# Tell MSVC to build using multiple processes.
# This may speed up compilation time significantly.
# For more information check:
# https://learn.microsoft.com/en-us/cpp/build/reference/mp-build-with-multiple-processes?view=msvc-170
#
add_compile_options($<$<CXX_COMPILER_ID:MSVC>:/MP>)

# Specifies that executables should be placed in the "/bin" subfolder of the output directory.
# Remove/comment this line below if you prefer to have the default behavior.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# Add the src/ directory to the include path of all targets
include_directories("src")


################################################################################
#
# Targets
#

# Executable and library targets
add_subdirectory(src)

# Unit testing
if(BUILD_TESTING)
  add_subdirectory(test)
endif()
