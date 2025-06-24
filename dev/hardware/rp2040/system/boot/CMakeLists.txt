set(TARGET boot_stage2)

add_library(${TARGET} STATIC
    src/boot_stage2.c
)

target_include_directories(${TARGET} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/private
)

target_link_libraries(${TARGET} PUBLIC helper types)


