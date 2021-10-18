# add all source files from src folder to variable MODULES
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src MODULES)
# add main.c and MODULES to the executable
add_executable( cmake_project
                main.c
                ${MODULES})

# add inc to the include directories
target_include_directories( cmake_project
                            PRIVATE
                                ${CMAKE_CURRENT_SOURCE_DIR}/inc
                            )

# set output dir and output file name
set_target_properties(  cmake_project
                        PROPERTIES
                            RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
                            RUNTIME_OUTPUT_NAME cmake-project
                        )

# add dependencies
target_include_directories( cmake_project
                            PUBLIC
                                ${PROJECT_SOURCE_DIR}/inc
                            )