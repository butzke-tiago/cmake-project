cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

# Handle inclusion of toolchain configuration file, as the --toolchain option seems not to work.
if (DEFINED TOOLCHAIN)
    include(${TOOLCHAIN})
    set(CMAKE_CROSSCOMPILING true)
endif()

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

include(options.cmake)



# add the code directory
add_subdirectory(code)

# add libs directory
if(USE_LIBS) 
    add_subdirectory(libs)
endif()

#add dependencies to be built before the main target
add_dependencies(cmake_project jansson mymath)