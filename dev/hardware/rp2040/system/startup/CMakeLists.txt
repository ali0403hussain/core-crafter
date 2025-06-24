add_library(startup STATIC
    src/startup.c
)

target_include_directories(startup PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}src/private
)

target_link_libraries(startup PUBLIC types)

