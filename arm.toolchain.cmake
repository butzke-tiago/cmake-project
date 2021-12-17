# Example of a toolchain

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

if (NOT DEFINED GCC_ARM_TC_ROOT)
  if (EXISTS "/usr/local/gcc-arm-none-eabi-6-2017-q2-update/bin/arm-none-eabi-gcc")
    set(GCC_ARM_TC_ROOT /usr/local/gcc-arm-none-eabi-6-2017-q2-update)
  endif()
endif()

if (NOT DEFINED GCC_ARM_TC_ROOT)
  if (EXISTS "/usr/gcc-arm-none-eabi-6-2017-q2-update/bin/arm-none-eabi-gcc")
    set(GCC_ARM_TC_ROOT /usr/gcc-arm-none-eabi-6-2017-q2-update)
  endif()
endif()

if (NOT DEFINED GCC_ARM_TC_ROOT)
  if (EXISTS "/opt/gcc-arm-none-eabi-6-2017-q2-update/bin/arm-none-eabi-gcc")
	  set(GCC_ARM_TC_ROOT /opt/gcc-arm-none-eabi-6-2017-q2-update)
  endif()
endif()

set(CMAKE_FIND_ROOT_PATH ${GCC_ARM_TC_ROOT}/)
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

set(CMAKE_C_COMPILER ${GCC_ARM_TC_ROOT}/bin/arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER ${GCC_ARM_TC_ROOT}/bin/arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER ${GCC_ARM_TC_ROOT}/bin/arm-none-eabi-gcc)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# Avoid known bug in linux giving: 
#    arm-none-eabi-gcc: error: unrecognized command line option '-rdynamic'
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "")

# Auto provide start functions
set(CMAKE_EXE_LINKER_FLAGS "--specs=nosys.specs")
