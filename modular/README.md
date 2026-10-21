# MyProject — modular C++/CMake scaffold

A starter for CMake 3.24+ and C++20 with module-local tests. `math` and
`parser` are minimal example modules; delete or rename their example code
as you adapt the template.

## Layout

```text
MyProject/
├── CMakeLists.txt
├── cmake/
│   ├── ProjectSettings.cmake
│   ├── Dependencies.cmake
│   ├── FindOrFetch.cmake
│   └── Testing.cmake
├── modules/
│   ├── math/
│   │   ├── CMakeLists.txt
│   │   ├── include/myproject/math/calculator.hpp
│   │   ├── src/calculator.cpp
│   │   └── tests/
│   │       ├── CMakeLists.txt
│   │       └── calculator_tests.cpp
│   └── parser/
│       ├── CMakeLists.txt
│       ├── include/myproject/parser/parser.hpp
│       ├── src/parser.cpp
│       └── tests/
│           ├── CMakeLists.txt
│           └── parser_tests.cpp
├── apps/cli/
│   ├── CMakeLists.txt
│   └── main.cpp
├── docs/
│   ├── CMakeLists.txt
│   └── Doxyfile.in
└── lib/                # Optional vendored third-party CMake projects
```

## Build

Requires a C++20 compiler and CMake 3.24+.

```sh
cmake -S . -B build -DBUILD_TESTING=OFF
cmake --build build
./build/bin/myproject_cli  # On Windows: use the corresponding .exe and config directory
```

To build tests, Catch2 v3 is needed. The template first checks `lib/Catch2`,
then tries an installed CMake package, then fetches pinned Catch2 v3.9.1
from Git. **The Git fallback requires network access during configuration.**

```sh
cmake -S . -B build -DBUILD_TESTING=ON
cmake --build build
ctest --test-dir build --output-on-failure

# Run tests from one module
ctest --test-dir build -L math --output-on-failure
ctest --test-dir build -L parser --output-on-failure
```

To build just one module's tests:

```sh
cmake --build build --target myproject_math_tests
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
- `cmake/ProjectSettings.cmake` exposes `myproject::options`, an INTERFACE
  target holding C++20 and MSVC `/MP` requirements for your own targets.
- `cmake/FindOrFetch.cmake` contains reusable dependency resolution code.
- `cmake/Dependencies.cmake` lists non-test third-party dependencies.
- `cmake/Testing.cmake` resolves Catch2 once and loads Catch's test-discovery helper.
- Each module owns its own library target and executable test target.
- CTest collects test cases globally via `catch_discover_tests()`; labels
  enable per-module filtering.

This is a project scaffold, not a package export/install configuration.
Add install/export rules if you want consumers to use these libraries via
`find_package(MyProject)`.
