cmake_minimum_required(VERSION 3.26)
project(adventofcode_2023_day_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(adventofcode_day_1 main.cpp input)

configure_file(input input COPYONLY)
