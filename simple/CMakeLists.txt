cmake_minimum_required (VERSION 3.24)

project ("Simple CMake Template" VERSION 1.4 LANGUAGES CXX)

# The template specifies the standard per project
# Uncomment only if truly needed.
# set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Makes it easier to display some useful info
include(CMakePrintHelpers)

# Display useful configuration information
cmake_print_variables(
    CMAKE_MODULE_PATH
    CMAKE_PREFIX_PATH
    CMAKE_INSTALL_PREFIX
)

# Shared build settings and general-purpose dependencies
include(cmake/ProjectSettings.cmake)
include(cmake/Dependencies.cmake)

# Add the src/ directory to the include path of all targets
include_directories("src")

# Configure the project for testing with CTest/CDash
# Automatically adds the BUILD_TESTING option and sets it to ON
# If BUILD_TESTING is ON, automatically calls enable_testing().
# Check the following resources for more info:
#   https://cmake.org/cmake/help/latest/module/CTest.html
#   https://cmake.org/cmake/help/latest/command/enable_testing.html
#   https://cmake.org/cmake/help/latest/manual/ctest.1.html
include(CTest)

if(BUILD_TESTING)
    include(cmake/Testing.cmake)
endif()

# Executable and library targets
add_subdirectory(src)

if(BUILD_TESTING)
  add_subdirectory(test)
endif()
