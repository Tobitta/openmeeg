#
# Build the documentation
#

INCLUDE (Documentation OPTIONAL)

IF (BUILD_DOCUMENTATION)

    #
    # Configure the script and the doxyfile, then add target
    #
    # XXXX: This should not be done in this manner, or at least it should break when dot is not found.
    #       The way to do that is:
    #       find_package(Doxygen
    #                    REQUIRED dot
    #                    OPTIONAL_COMPONENTS gnuplot)
    #       if(NOT DOXYGEN_DOT_FOUND)
    #            message(WARNING "Graphviz doesn't seem to be installed.\
    #                             Doxygen will not be able to generate graphs.\
    #                             Consider installing this package.")
    #       endif(NOT DOXYGEN_DOT_FOUND)
    #
    IF(NOT DOT_PATH)
        GET_FILENAME_COMPONENT(DOT_PATH ${DOT} PATH)
    ENDIF(NOT DOT_PATH)


    IF (NOT USE_CGAL)
        SET(OpenMEEG_EXCLUDE_FROM_DOCUMENTATION
            "${OpenMEEG_EXCLUDE_FROM_DOCUMENTATION} ${CMAKE_SOURCE_DIR}/tools/cgal_mesh_create.cpp ${CMAKE_SOURCE_DIR}/tools/cgal_mesh_include.h")
    ENDIF()
    CONFIGURE_FILE(
        ${OpenMEEG_SOURCE_DIR}/documentation/reference/doxyfile.in
        ${OpenMEEG_BINARY_DIR}/documentation/reference/doxyfile)

    #   The ALL in the next directive is necessary to cope with a CMake bug !!!
    #   Otherwise the target is never activated.

    ADD_CUSTOM_TARGET(OpenMEEG-documentation ALL)

    ADD_DEPENDENCIES(OpenMEEG-documentation OpenMEEG-doxygen_outputs)

    ADD_CUSTOM_TARGET(OpenMEEG-doxygen_outputs
                      COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/doxyfile
                      DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/doxyfile)

    INSTALL(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/html/ DESTINATION share/doc/OpenMEEG/reference)

ENDIF (BUILD_DOCUMENTATION)
