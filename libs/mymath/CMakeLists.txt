# add all source files from src folder to variable MODULES
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src MODULES)
# add main.c and MODULES to the executable
add_library( mymath
                ${MODULES}
            )

# add inc to the interface directories
target_include_directories( mymath
                            INTERFACE
                                ${CMAKE_CURRENT_SOURCE_DIR}/inc
                            )
