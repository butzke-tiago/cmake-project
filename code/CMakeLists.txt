# add main to the executable
add_executable( cmake_project
                main.c)

set_target_properties(  cmake_project
                        PROPERTIES
                            RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
                        )

# add dependencies
target_include_directories( cmake_project
                            PUBLIC
                                ${PROJECT_SOURCE_DIR}/inc
                          )