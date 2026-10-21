add_library(myproject_math
    src/calculator.cpp
)
add_library(myproject::math ALIAS myproject_math)

target_include_directories(myproject_math PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:include>"
)

target_link_libraries(
    myproject_math
    PRIVATE
        myproject::build_options
        myproject::cxx_version
)

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
