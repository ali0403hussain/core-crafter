add_library(hal STATIC
    src/hal_gpio.c
)

target_include_directories(hal PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

target_link_libraries(hal
    PUBLIC
        types
        drivers_gpio   
)