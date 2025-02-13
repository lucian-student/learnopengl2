cmake_minimum_required(VERSION 3.30)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(OPENGL)

add_subdirectory(stb)
add_subdirectory(glad)
add_subdirectory(src)
add_subdirectory(test)
