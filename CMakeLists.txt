cmake_minimum_required(VERSION 3.8.2)
project("roa-mod-template" LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")

file(READ version ROA_MOD_TEMPLATE_VERSION)
add_compile_definitions("VERSION_STR=\"${ROA_MOD_TEMPLATE_VERSION}\"")

add_library(${PROJECT_NAME} SHARED 
    "src/load.cpp" 
    "src/callback.cpp"
)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "${PROJECT_NAME}")
target_include_directories(${PROJECT_NAME} PRIVATE "include")

# roa-mod-loader
add_subdirectory("vendor/roa-mod-loader")
target_link_libraries(${PROJECT_NAME} PRIVATE roa-mod-loader)
target_include_directories(${PROJECT_NAME} PRIVATE "vendor/roa-mod-loader/loader/include")

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_SOURCE_DIR}/details.yaml" "${CMAKE_BINARY_DIR}/${PROJECT_NAME}/info.yaml"
)

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND "py" "${CMAKE_SOURCE_DIR}/script/launch.py"
)