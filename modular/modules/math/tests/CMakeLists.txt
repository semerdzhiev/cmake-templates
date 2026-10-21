set(TEST_TARGET "${MODULE_TARGET}_tests")

add_executable("${TEST_TARGET}"
    factorial_tests.cpp
    fibonacci_tests.cpp
)

target_link_libraries("${TEST_TARGET}" PRIVATE
    "${MODULE_ALIAS}"
    "${PROJECT_ID}::build_options"
    "${PROJECT_ID}::cxx_version"
    Catch2::Catch2WithMain
)

catch_discover_tests("${TEST_TARGET}"
    TEST_PREFIX "${MODULE_NAME}::"
    PROPERTIES LABELS "${MODULE_NAME}"
    ADD_TAGS_AS_LABELS
)
