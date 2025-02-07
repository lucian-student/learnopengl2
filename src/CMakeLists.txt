add_executable(APP 
    main.cpp
)
target_compile_options(APP PRIVATE /EHsc /W4 /D_DEBUG /MDd)
#target_compile_options(APP PRIVATE /Zi  /fsanitize=address)

target_link_libraries(APP PRIVATE CORE)

add_subdirectory(exceptions)
add_subdirectory(core)