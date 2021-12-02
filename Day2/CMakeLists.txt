cmake_minimum_required(VERSION 3.21)
project(Day2)

set(CMAKE_CXX_STANDARD 14)

configure_file(input.txt . COPYONLY)

add_executable(Day2_1 day2_1.cpp)
add_executable(Day2_2 day2_2.cpp)
