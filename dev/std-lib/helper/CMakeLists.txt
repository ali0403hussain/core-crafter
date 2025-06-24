add_library(helper STATIC
    src/helper_runtime.c
)

target_include_directories(helper PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/private
)

target_link_libraries(helper PUBLIC types)
