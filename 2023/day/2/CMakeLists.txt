cmake_minimum_required(VERSION 3.27)
project(adventofcode_2023_day_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(adventofcode_2023_day_2 main.cpp)

configure_file(input input COPYONLY)
