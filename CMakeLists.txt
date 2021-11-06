cmake_minimum_required(VERSION 3.20)
project(C8_Emulator)

set(CMAKE_CXX_STANDARD 17)

add_executable(chip8 chip8.hpp platform.hpp main.cpp)

target_compile_options(chip8 PRIVATE -Wall)

target_link_libraries(chip8 SDL2main SDL2)
