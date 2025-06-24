cmake_minimum_required(VERSION 3.18)

set(PROJECT_NAME core-crafter)
set(PROJECT_VERSION 1.0.0)

project(
    ${PROJECT_NAME}
    VERSION ${PROJECT_VERSION}
    LANGUAGES C ASM)

# Default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Set toolchain
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/cmake/rp2040_toolchain.cmake" CACHE STRING "")

# Set hardware name
set(CMAKE_SELECTED_PLATFORM "RP2040" CACHE STRING "")

# Output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if(CMAKE_SELECTED_PLATFORM STREQUAL "RP2040")
    set(CMAKE_PLATFORM_ID "0xe48bff56")
    message(STATUS "Building for RP2040 platform")
    message(STATUS "Platform ID : ${CMAKE_PLATFORM_ID}")
else()
    set(CMAKE_PLATFORM_ID "0x0000000")
    message(STATUS "Invalid hardware platform")
endif()

# Include all components
add_subdirectory(dev)