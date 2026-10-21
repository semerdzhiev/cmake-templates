add_executable(myproject_math_tests
    factorial_tests.cpp
    fibonacci_tests.cpp
)

target_link_libraries(myproject_math_tests PRIVATE
    myproject::math
    myproject::build_options
    myproject::cxx_version
    Catch2::Catch2WithMain
)

catch_discover_tests(myproject_math_tests
    TEST_PREFIX "math::"
    PROPERTIES LABELS "math"
)
