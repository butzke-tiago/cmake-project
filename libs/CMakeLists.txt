# add libs directories
add_subdirectory(mymath)

# add module to support external projects
include(ExternalProject)

# add jansson library from submodule
ExternalProject_Add(
                    # Name for custom target
                    jansson
                    # Root dir for entire project
                    PREFIX ${PROJECT_SOURCE_DIR}/libs/jansson
                    # Source dir to be used for build
                    SOURCE_DIR ${PROJECT_SOURCE_DIR}/libs/jansson
                    
                    ## To download directly from the repo
                    # URL of git repo
                    #   GIT_REPOSITORY https://github.com/akheron/jansson.git
                    # Git branch name, commit id or tag
                    #   GIT_TAG v2.14

                    # Specify build dir location
                    BINARY_DIR ${PROJECT_SOURCE_DIR}/libs/jansson/build
                    ## To define install directory after build
                    # Arguments to CMake command line
                    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=${PROJECT_SOURCE_DIR}/libs/bin/jansson
)

