cmake_minimum_required(VERSION 3.21)
project(Day3)

set(CMAKE_CXX_STANDARD 14)

configure_file(input.txt . COPYONLY)

add_executable(Day3 main.cpp day3_1.cpp)
