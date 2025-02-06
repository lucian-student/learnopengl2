add_executable(APP main.cpp)
target_compile_options(APP PRIVATE /EHsc /W4 /D_DEBUG /MDd)

find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(APP PRIVATE glfw GladLib)