include_guard(GLOBAL)

# Get a list of all compile options
# Supported by Makefile and Ninja generators (not all generators).
# https://cmake.org/cmake/help/latest/variable/CMAKE_EXPORT_COMPILE_COMMANDS.html
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Default output layout. Multi-config generators may append a config subdirectory.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

# Usage requirements shared by our own targets; avoid global compiler options.
add_library(myproject_build_options INTERFACE)
add_library(myproject::build_options ALIAS myproject_build_options)

# Tell MSVC to build using multiple processes.
# This may speed up compilation time significantly.
# For more information check:
# https://learn.microsoft.com/en-us/cpp/build/reference/mp-build-with-multiple-processes?view=msvc-170
target_compile_options(myproject_build_options INTERFACE
    "$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/MP>"
)

# C++ standard version shared with our own targets
add_library(myproject_cxx_version INTERFACE)
add_library(myproject::cxx_version ALIAS myproject_cxx_version)
target_compile_features(myproject_cxx_version INTERFACE cxx_std_20)
