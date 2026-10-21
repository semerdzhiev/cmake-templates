# Simple CMake project template

This repository contains a simple template for new CMake projects.

## .gitignore

The `.gitignore` file filters:

* Several commonly used directories like `.vs/`, `out/` and `build/`.
* The [`CMakeUserPresets.json`](https://cmake.org/cmake/help/latest/manual/cmake-presets.7.html)
  local presets file.

## Directory Layout

* `src/` -- Your own sources
* `test/` -- Your own tests
* `lib/` -- External third-party libraries

## Catch2

The template uses [Catch2](https://github.com/catchorg/Catch2) for unit testing.
It attempts to locate a local copy of Catch2 and if one does not exist,
fetches it from its GitHub repository.

For more information on how to build and install Catch2 locally,
check out the [official documentation](https://github.com/catchorg/Catch2/blob/devel/docs/cmake-integration.md#installing-catch2-from-git-repository).

If you need to build both the debug and release versions,
when using a multi-configuration generator (e.g., VS),
you can use a single CMake build directory for both configurations:

```bash
cmake -B .build

# Debug
cmake --build build --config Debug
cmake --install build --config Debug

# Release
cmake --build build --config Release
cmake --install build --config Release
```

When using a single-configuration generator (e.g. Ninja),
you need separate build directories:

```bash
# Debug
cmake -B .build-debug -DCMAKE_BUILD_TYPE=Debug
cmake --build .build-debug
cmake --install .build-debug

# Release
cmake -B .build-release -DCMAKE_BUILD_TYPE=Release
cmake --build .build-release
cmake --install .build-release
```

## Dependencies

The template comes with directives for popular libraries such as Catch2 and spdlog.
Check the [`cmake/Dependencies.cmake`](cmake/Dependencies.cmake) file for more information.

If you want to use a locally cloned copy, set the appropriate
`FETCHCONTENT_SOURCE_DIR_*` variable.
You can do so in the `Dependencies.cmake` file itself,
or by passing the variable on the command line:

```text
-DFETCHCONTENT_SOURCE_DIR_SPDLOG=/path
```

If you want to always fetch, rather than search for installed packages use:

```text
-DFETCHCONTENT_TRY_FIND_PACKAGE_MODE=NEVER
```

