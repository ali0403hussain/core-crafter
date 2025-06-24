add_library(drivers_gpio STATIC
    src/drivers_gpio.c
)

target_include_directories(drivers_gpio PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/private
    ${CMAKE_CURRENT_SOURCE_DIR}/../regs
)

target_link_libraries(drivers_gpio PUBLIC types hal)
