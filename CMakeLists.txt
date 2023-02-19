cmake_minimum_required(VERSION 3.21)
project(clox C)

set(CMAKE_C_STANDARD 17)

include_directories("${PROJECT_SOURCE_DIR}")
#LINK_DIRECTORIES("${PROJECT_BINARY_DIR}")

add_executable(clox main.c chunk.c memory.c debug.c value.c vm.h vm.c compiler.h compiler.c scanner.h scanner.c object.h object.c table.h table.c)
#target_link_libraries (clox "${PROJECT_BINARY_DIR}")
