add_executable(APP main.cpp)
target_compile_options(APP PRIVATE /EHsc /W4 /D_DEBUG /MDd)


target_include_directories(APP PRIVATE "${CMAKE_SOURCE_DIR}")

find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(APP PUBLIC glfw glad)

