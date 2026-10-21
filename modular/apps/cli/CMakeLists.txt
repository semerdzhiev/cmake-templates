set(APP_NAME "cli")
set(APP_TARGET "${PROJECT_ID}_${APP_NAME}")

add_executable("${APP_TARGET}"
    main.cpp
)

target_link_libraries("${APP_TARGET}" PRIVATE
    "${PROJECT_ID}::math"
    "${PROJECT_ID}::build_options"
    "${PROJECT_ID}::cxx_version"
)

set_target_properties("${APP_TARGET}" PROPERTIES
    OUTPUT_NAME "calculator"
)
