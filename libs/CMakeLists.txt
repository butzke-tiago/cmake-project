# add libs directories
add_subdirectory(mymath)

# add module to support external projects
include(ExternalProject)

# add jansson library from submodule
ExternalProject_Add(jansson
                        # Root dir for entire project
                        PREFIX ${PROJECT_SOURCE_DIR}/libs/jansson
                        # Source dir to be used for build
                        SOURCE_DIR ${PROJECT_SOURCE_DIR}/libs/jansson
                        
                        # Specify build dir location
                        BINARY_DIR ${PROJECT_SOURCE_DIR}/libs/jansson/build
                        ## To define install directory after build
                        # Arguments to CMake command line
                        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=${PROJECT_SOURCE_DIR}/libs/bin/jansson
                    )

# add curl library from git repo
ExternalProject_Add(curl
                        # Root dir for entire project
                        PREFIX ${PROJECT_SOURCE_DIR}/libs/curl
                        
                        # URL of git repo
                        GIT_REPOSITORY https://github.com/curl/curl.git
                        # Git branch name, commit id or tag
                        GIT_TAG curl-7_80_0

                        # Specify build dir location
                        BINARY_DIR ${PROJECT_SOURCE_DIR}/libs/curl/build
                        # Arguments to CMake command line - define install directory after build
                        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=${PROJECT_SOURCE_DIR}/libs/bin/curl
                    )
