
add_library(
    UTILS 
    color_utils.cpp
    shader_utils.cpp
    program_utils.cpp 
    shader.cpp
    utils.cpp
    vertex_array_object.cpp
    vertex_buffer_object.cpp
    program.cpp
    texture.cpp
)


find_package(glm CONFIG REQUIRED)
target_link_libraries(UTILS PRIVATE glm::glm)

target_link_libraries(UTILS PUBLIC glad EXCEPTION stb)

target_include_directories(UTILS PUBLIC "${CMAKE_CURRENT_LIST_DIR}")