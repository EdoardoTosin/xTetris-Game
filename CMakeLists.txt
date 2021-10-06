cmake_minimum_required(VERSION 3.14)

set(CMAKE_C_STANDARD 90)

project(x-Tetris)

file(GLOB_RECURSE TARGET_SOURCES ${CMAKE_CURRENT_LIST_DIR}/src/*.c)

add_executable(x-Tetris ${TARGET_SOURCES})

install(TARGETS x-Tetris)
