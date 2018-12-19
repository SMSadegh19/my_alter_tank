cmake_minimum_required(VERSION 3.0)
project(tank C)
set(CMAKE_C_STANDARD 99)

file(GLOB_RECURSE SOURCE "src/*.c" "src/*.h")
add_executable(tank "${SOURCE}" src/testhead.h)

include_directories("/usr/include/SDL2")
target_link_libraries(tank m SDL2 SDL2_gfx)
