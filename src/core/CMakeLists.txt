
add_library(CORE 
    app.cpp
)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(CORE PUBLIC glfw glad)

target_include_directories(CORE PUBLIC  "${CMAKE_CURRENT_LIST_DIR}")
