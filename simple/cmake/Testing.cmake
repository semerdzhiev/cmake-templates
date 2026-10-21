include_guard(GLOBAL)

include(FetchContent)

# Declare Catch2 as our testing framework.
# Prefer an installed package, otherwise fetch from Git.

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.16.1
    FIND_PACKAGE_ARGS 3 CONFIG QUIET
)

FetchContent_MakeAvailable(Catch2)

# Catch2's CTest integration is provided by Catch.cmake.
#
# When Catch2 is fetched from source, this file is located
# in the extras/ directory.
#
# When Catch2 is installed as a package, its package
# configuration normally makes Catch.cmake discoverable.

if(EXISTS "${catch2_SOURCE_DIR}/extras/Catch.cmake")
    list(PREPEND CMAKE_MODULE_PATH
        "${catch2_SOURCE_DIR}/extras"
    )
endif()

include(Catch)
