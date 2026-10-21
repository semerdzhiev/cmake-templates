add_executable(myproject_cli
    "main.cpp"
)

target_link_libraries(myproject_cli PRIVATE
    myproject::math
    myproject::build_options
    myproject::cxx_version
)

set_target_properties(myproject_cli PROPERTIES OUTPUT_NAME "calculator")
