
add_library(UTILS color_utils.cpp shader_utils.cpp program_utils.cpp)

target_include_directories(UTILS PUBLIC "${CMAKE_CURRENT_LIST_DIR}")

target_link_libraries(UTILS PUBLIC glad)