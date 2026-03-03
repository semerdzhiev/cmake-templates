cmake_minimum_required (VERSION 3.13)

project ("Minimalistic CMake Template" VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Get a list of all compile options
# Works only for generators that support this functionality.
# https://cmake.org/cmake/help/latest/variable/CMAKE_EXPORT_COMPILE_COMMANDS.html
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#
# Tell MSVC to build using multiple processes.
# This may speed up compilation time significantly.
# For more information check:
# https://learn.microsoft.com/en-us/cpp/build/reference/mp-build-with-multiple-processes?view=msvc-170
#
add_compile_options($<$<CXX_COMPILER_ID:MSVC>:/MP>)

# Executables will go into a "/bin" subfolder of the output directory.
# Libraries will go into a "/lib" subfolder of the output directory.
# Remove/comment the lines below if you prefer to have the default behavior.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

# Main target
add_executable(application)

target_sources(
	application
	PRIVATE
		"main.cpp"
)
