set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR cortex-m0plus)

# Toolchain paths
set(TOOLCHAIN_PREFIX arm-none-eabi)
set(CMAKE_C_COMPILER ${TOOLCHAIN_PREFIX}-gcc)
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_PREFIX}-g++)
set(CMAKE_ASM_COMPILER ${TOOLCHAIN_PREFIX}-gcc)
set(CMAKE_OBJCOPY ${TOOLCHAIN_PREFIX}-objcopy)
set(CMAKE_SIZE ${TOOLCHAIN_PREFIX}-size)

# Don't use standard system libraries
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Define warnings
set(PROJECT_ENABLE_WARNINGS
    -Wall 
    -Wextra 
    -Werror 
    -ffreestanding 
    -nostdlib)

# Optimization level
set(PROJECT_OPTIMIZATION -O0)

# Common flags
set(COMMON_FLAGS 
    -mcpu=cortex-m0plus
    -mthumb)

# Combine all flags into one list
list(APPEND COMMON_FLAGS 
    ${PROJECT_ENABLE_WARNINGS} 
    ${PROJECT_OPTIMIZATION})

# Join list into space-separated string
string(JOIN " " COMMON_FLAGS_STRING ${COMMON_FLAGS})

# Apply the joined flags to compilers
set(CMAKE_C_FLAGS "${COMMON_FLAGS_STRING}")
set(CMAKE_CXX_FLAGS "${COMMON_FLAGS_STRING}")
set(CMAKE_ASM_FLAGS "${COMMON_FLAGS_STRING}")
set(CMAKE_EXE_LINKER_FLAGS
    "-T${CMAKE_SOURCE_DIR}/dev/hardware/rp2040/system/linker/linker_core0.ld -nostartfiles -Wl,-Map=${CMAKE_BINARY_DIR}/app.map")

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)