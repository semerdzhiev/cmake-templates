#
# FindOrFetch
#
# Tries to locate a local copy of a library, or downloads it from its Git repo.
#
# If the library has been made available under the ./lib/ subdirectory,
# then this local copy will have precedence and will be used.
#
# Otherwise, FetchContent_MakeAvailable will be called. It will try to
# obtain a locally built and installed copy and if one is not available,
# then the library will be downloaded from its Git repo.
#
# Usage:
#   find_or_fetch_library(
#       NAME <name_of_the_library>
#       GIT_REPOSITORY <url_if_the_git_repo>
#       GIT_TAG <tag_or_commit_hash>
#       [FIND_PACKAGE_ARGS <args>]
#   )
#
# Example:
#   find_or_fetch_library(
#       NAME           Catch2
#       GIT_REPOSITORY https://github.com/catchorg/Catch2.git
#       GIT_TAG        v3.9.1
#   )
#

macro(find_or_fetch_library)
  cmake_parse_arguments(
    FFL
    ""                             # Boolean args
    "NAME;GIT_REPOSITORY;GIT_TAG"  # Single-value args
    "FIND_PACKAGE_ARGS"            # Multi-value args
    ${ARGN}
  )

  if(NOT FFL_NAME)
    message(FATAL_ERROR "find_or_fetch_library: NAME is required; use it to pass the name of the library.")
  endif()

  message(STATUS "find_or_fetch_library(): Let's try to find '${FFL_NAME}'...")
  list(APPEND CMAKE_MESSAGE_INDENT "  ") # Increase the indent for all subsequent messages

  set(FFL_LOCAL_COPY "${CMAKE_SOURCE_DIR}/lib/${FFL_NAME}")

  if(EXISTS FFL_LOCAL_COPY)
    # If the library's code has been placed in the /lib directory, use that
    message(STATUS "Found '${FFL_NAME}' as a local copy under ${FFL_LOCAL_COPY}")
    add_subdirectory(FFL_LOCAL_COPY)

  else()

    message(STATUS "There is no local copy under ./lib/; invoking FetchContent_MakeAvailable...")

    # Try to either find a local installation of the library,
    # or download it from its repository.
    #
    # You can find more information on how FetchContent works and
    # what is the order of locations being searched in these sources:
    #
    # Using Dependencies Guide
    #   https://cmake.org/cmake/help/latest/guide/using-dependencies/index.html#guide:Using%20Dependencies%20Guide
    # FetchContent examples:
    #   https://cmake.org/cmake/help/latest/module/FetchContent.html#fetchcontent-find-package-integration-examples
    # If necessary, set up FETCHCONTENT_TRY_FIND_PACKAGE_MODE. Check:
    #   https://cmake.org/cmake/help/latest/module/FetchContent.html#variable:FETCHCONTENT_TRY_FIND_PACKAGE_MODE

    include(FetchContent)

    # FIND_PACKAGE_ARGS makes it so that CMake first tries to find
    # CMake with find_package() and if it is NOT found, it will
    # be retrieved from its repository.
    FetchContent_Declare(
        ${FFL_NAME}
        GIT_REPOSITORY    ${FFL_GIT_REPOSITORY}
        GIT_TAG           ${FFL_GIT_TAG}
        FIND_PACKAGE_ARGS ${FIND_PACKAGE_ARGS}
    )

    FetchContent_MakeAvailable(${FFL_NAME})

  endif()

  message(STATUS "Finished processing. Dumping some variables below:")

  cmake_print_variables(CMAKE_MODULE_PATH)
  cmake_print_variables(${FFL_NAME}_DIR)
  cmake_print_variables(${FFL_NAME}_SOURCE_DIR)
  cmake_print_variables(${FFL_NAME}_FOUND)

  list(POP_BACK CMAKE_MESSAGE_INDENT) # Restore the previous indentation level

endmacro()
