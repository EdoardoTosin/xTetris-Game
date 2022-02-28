cmake_minimum_required(VERSION 3.21)

set(CMAKE_C_STANDARD 90)

set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS} -ansi -pedantic -Wall -O3 -fsanitize=address,undefined")

set(CMAKE_C_FLAGS_RELEASE_INIT "-Wall")

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS} -ansi -pedantic -Wall -g -O3 -fsanitize=address,undefined")

set(CMAKE_C_FLAGS_DEBUG_INIT "-Wall")

project(xTetris)

file(GLOB_RECURSE TARGET_SOURCES ${CMAKE_CURRENT_LIST_DIR}/src/*.c)

add_executable(xTetris ${TARGET_SOURCES})

install(TARGETS xTetris)
