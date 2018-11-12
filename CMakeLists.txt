cmake_minimum_required(VERSION 3.8)
project(sudokusolver)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c)
add_executable(sudokusolver ${SOURCE_FILES})