set(TARGET ${PROJECT_NAME}_app_sc_blinky)

set(TOOLS_DIR ${CMAKE_SOURCE_DIR}/tools)
set(OUTPUT_DIR ${TOOLS_DIR}/output)
set(UF2_SCRIPT ${TOOLS_DIR}/uf2conv.py)

# Ensure the directory exists
file(MAKE_DIRECTORY ${OUTPUT_DIR})

add_executable(${TARGET} 
    app_sc_blinky.c)

target_include_directories(${TARGET} PUBLIC
    ${CMAKE_SOURCE_DIR}/dev/inc
    ${CMAKE_SOURCE_DIR}/dev/hal/include
    ${CMAKE_SOURCE_DIR}/dev/hardware/rp2040/drivers/inc
 )

target_link_libraries(${TARGET} PUBLIC
    startup
    boot_stage2
    drivers_gpio
    hal
    helper
    types) 

# Add post-build command command to generate hex and bin file
add_custom_command(TARGET ${TARGET} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Generating ${TARGET}.hex/.bin and displaying size info..."
    COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:${TARGET}> ${TARGET}.hex
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${TARGET}> ${TARGET}.bin
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${TARGET}>
    COMMENT "Generating ${TARGET}.hex/.bin and displaying size info"
)

    # Add post-build command command to copy generate map, hex and bin file to output
add_custom_command(TARGET ${TARGET} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Copying bin and hex files to output..."
    COMMAND ${CMAKE_COMMAND} -E copy ${TARGET}.hex ${OUTPUT_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy ${TARGET}.bin ${OUTPUT_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/app.map ${OUTPUT_DIR}/${TARGET}.map
    COMMENT "Copying bin and hex files to output"
)

# Add post-build command to convert .bin to .uf2
add_custom_command(TARGET ${TARGET} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Converting ${BIN_FILE} to UF2..."
    COMMAND python3 ${UF2_SCRIPT} -b 0x10000000 -f ${CMAKE_PLATFORM_ID} -o ${OUTPUT_DIR}/${TARGET}.uf2 ${TARGET}.bin
    COMMENT "Generating UF2 file from BIN"
)