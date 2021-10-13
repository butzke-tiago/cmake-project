cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

# set the project name and version
project(cmake_project
        VERSION 0.1.0
        LANGUAGES C
        )

# set standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# configure header file for version
configure_file(cmake-project.h.in ${PROJECT_SOURCE_DIR}/inc/cmake-project.h)

# add the code directory
add_subdirectory(code)
