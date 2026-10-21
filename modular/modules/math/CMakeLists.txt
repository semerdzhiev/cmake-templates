set(MODULE_NAME "math")
set(MODULE_TARGET "${PROJECT_ID}_${MODULE_NAME}")
set(MODULE_ALIAS "${PROJECT_ID}::${MODULE_NAME}")

add_library("${MODULE_TARGET}"
    src/calculator.cpp
)
add_library("${MODULE_ALIAS}" ALIAS "${MODULE_TARGET}")

target_include_directories("${MODULE_TARGET}" PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:include>"
)

target_link_libraries(
    "${MODULE_TARGET}"
    PRIVATE
        "${PROJECT_ID}::build_options"
        "${PROJECT_ID}::cxx_version"
)

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
