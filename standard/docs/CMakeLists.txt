find_package(Doxygen)

if (DOXYGEN_FOUND)
    # Doxyfile.in is a standard Doxyfile generated with the help of Doxywizard.
    # However, inside it, we want to be able to refer to CMake variables, such
    # as PROJECT_VERSION, PROJECT_NAME, CMAKE_SOURCE_DIR, etc.
    # Thus, inside the file, when we need those variables, we encapsulate them
    # with '@' symbols, like this: @PROJECT_VERSION@, @PROJECT_NAME@, etc.
    # You can simply use those names inside Doxywizard. For example,
    # you can specify the path to the sources as @CMAKE_SOURCE_DIR@/src
    # Later on, we use configure_file to copy the file to the build directory
    # and replace all such occurrances with the corresponding variable values.
    set(DOXYFILE_PATH "${DOCUMENTATION_OUTPUT_PATH}/Doxyfile")

    message(DEBUG "Documentation output path is \"${DOCUMENTATION_OUTPUT_PATH}\"")
    message(DEBUG "Doxyfile will be copied to \"${DOXYFILE_PATH}\"")
    
    configure_file(
        "Doxyfile.in"
        "${DOXYFILE_PATH}"
        @ONLY
    )

    # For more information on add_custom_target() check:
    #   https://cmake.org/cmake/help/latest/command/add_custom_target.html
    # Here is what the ALL option does:
    #   "Indicate that this target should be added to the default build target so that it will be run every time"
    add_custom_target(
        documentation_target
        ALL
        COMMAND "${DOXYGEN_EXECUTABLE}" "${DOXYFILE_PATH}"
        WORKING_DIRECTORY "${DOCUMENTATION_OUTPUT_PATH}"
        COMMENT "Running Doxygen..."
        VERBATIM
    )

else()

    message(SEND_ERROR "WARNING: Unable to find the Doxygen package")

endif()