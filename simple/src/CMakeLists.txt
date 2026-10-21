# Sample static library
add_library(samplelib STATIC)

set_target_properties(samplelib PROPERTIES OUTPUT_NAME "sample")

target_sources(
    samplelib
    PRIVATE
        "library.cpp"
        "library.h"
)

target_link_libraries(
    samplelib
    PRIVATE
        myproject::build_options
        myproject::cxx_version
)

# Executable target for the application
add_executable(application)

set_target_properties(application PROPERTIES OUTPUT_NAME "calc")

target_sources(
    application
    PRIVATE
        "application.cpp"
)

target_link_libraries(
    application
    PRIVATE
        samplelib
        myproject::build_options
        myproject::cxx_version
)
