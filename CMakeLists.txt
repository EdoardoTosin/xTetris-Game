cmake_minimum_required(VERSION 3.14)

set(CMAKE_C_STANDARD 90)

set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS} -O3")

project(xTetris)

file(GLOB_RECURSE TARGET_SOURCES ${CMAKE_CURRENT_LIST_DIR}/src/*.c)

add_executable(xTetris ${TARGET_SOURCES})

install(TARGETS xTetris)
