# Documentation is opt-in: -DMYPROJECT_BUILD_DOCS=ON.
find_package(Doxygen QUIET)

if(Doxygen_FOUND)
    set(DOCUMENTATION_OUTPUT_PATH "${CMAKE_CURRENT_BINARY_DIR}")
    set(DOXYFILE_PATH "${DOCUMENTATION_OUTPUT_PATH}/Doxyfile")

    configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in"
        "${DOXYFILE_PATH}"
        @ONLY
    )

    # Deliberately not in ALL: generate only when explicitly requested.
    add_custom_target(documentation_target
        COMMAND "${DOXYGEN_EXECUTABLE}" "${DOXYFILE_PATH}"
        WORKING_DIRECTORY "${DOCUMENTATION_OUTPUT_PATH}"
        COMMENT "Generating Doxygen documentation"
        VERBATIM
    )
else()
    message(WARNING "Doxygen not found; documentation_target not created")
endif()
