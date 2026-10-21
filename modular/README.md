# MyProject — modular C++/CMake scaffold

A simple starter template for CMake 3.24

`math` and `cli` are examples. Delete or rename them to adapt to your project.

You will also probably want to replate all occurrances of `myproject` to the identifier of your own project:

- `cmake\ProjectSettings.cmake`
- Within each module in `modules/` and `apps/` check
  the following files/directories (if present):
  - `CMakeLists.txt` file
  - `tests/CMakeLists.txt`
  - Rename the `include/myproject` directory
  - Fix all `#include` directives that refer to `myproject`.
  - Fix all namespace-related code that refers to `myproject`.

## Layout

```text
MyProject/
├── CMakeLists.txt
├── cmake/
│   ├── ProjectSettings.cmake
│   ├── Dependencies.cmake
│   ├── FindOrFetch.cmake
│   └── Testing.cmake
├── modules/ # Your reusable modules
├── apps/    # Your applications
├── docs/    # Documentation building (Doxygen based)
│   ├── CMakeLists.txt
│   └── Doxyfile.in
└── lib/     # Third-party libraries
```

## Build

Requires CMake 3.24+.
To build tests, Catch2 v3 is needed.
The template first tries to locate a locally installed copy
and then falls back to fetching it from the GitHub repo.

```sh
cmake -S . -B .build
cmake --build .build

# Build just one module's tests
cmake --build .build --target myproject_math_tests

# Run all tests
ctest --test-dir .build --output-on-failure

# Run tests with a given label
ctest --test-dir .build -L math --output-on-failure
```

## Optional documentation

Install Doxygen, then:

```sh
cmake -S . -B build -DMYPROJECT_BUILD_DOCS=ON
cmake --build build --target documentation_target
```

The docs are generated under `build/docs/html`. If Doxygen is absent,
configuration succeeds with a warning and no documentation target.

## Add a module

1. Copy `modules/math/` to `modules/<newname>/`.
2. Rename its library and test target (`myproject_<newname>` and
   `myproject_<newname>_tests`), along with its public alias.
3. Rename the headers, source files, and Catch2 tests.
4. Add `add_subdirectory(modules/<newname>)` to the root `CMakeLists.txt`.
5. Keep tests within the module; gate its `tests` directory on `BUILD_TESTING`.

Target names are *global*, even across subdirectories: use unique prefixes.
`myproject::math` is a CMake ALIAS, not a filesystem path.

## CMake design

- `CMakeLists.txt` at the root wires together modules, application, and options.
- `cmake/ProjectSettings.cmake` exposes several INTERFACE targets
  you can link in your own targets:
  - `myproject::options` adds the MSVC `/MP` switch
  - `myproject::cxx_version` sets a common C++ version
- `cmake/FindOrFetch.cmake` contains reusable dependency resolution code.
- `cmake/Dependencies.cmake` lists third-party dependencies.
  Note that `Catch2` is not listed there.
- `cmake/Testing.cmake` resolves Catch2 once and loads Catch's test-discovery helper.
- Each module owns its own library target and executable test target.
- CTest collects test cases globally via `catch_discover_tests()`; labels
  enable per-module filtering.

This is a project scaffold, not a package export/install configuration.
Add install/export rules if you want consumers to use these libraries via
`find_package(MyProject)`.
