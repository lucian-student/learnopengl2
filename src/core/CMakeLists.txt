
add_library(
    CORE 
    app.cpp
    triangle_mesh.cpp
    triangle.cpp
    square_mesh.cpp
    object3D.cpp
    camera.cpp
    renderer.cpp
    scene.cpp
    box_mesh.cpp
    geometry/buffer_geometry.cpp
    geometry/box_geometry.cpp
    material/material.cpp
    material/basic_material.cpp
    material/light_material.cpp
    material/map_material.cpp
    mesh.cpp
)

find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

# dobré vysvětlení pro význam PUBLIC https://stackoverflow.com/questions/69783203/examples-of-when-public-private-interface-should-be-used-in-cmake
target_link_libraries(CORE PUBLIC glfw glad EXCEPTION UTILS )
target_link_libraries(CORE PRIVATE glm::glm)

target_include_directories(CORE PUBLIC  "${CMAKE_CURRENT_LIST_DIR}")
target_include_directories(CORE PUBLIC "${CMAKE_CURRENT_LIST_DIR}/geometry")
target_include_directories(CORE PUBLIC "${CMAKE_CURRENT_LIST_DIR}/material")