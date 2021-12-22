cmake_minimum_required(VERSION 3.21)
project(Day9)

set(CMAKE_CXX_STANDARD 14)

configure_file(input.txt . COPYONLY)
include_directories(${CMAKE_SOURCE_DIR}/../AoClib)

add_executable(Day9 main.cpp day9_1.cpp day9_2.cpp day9_1.cpp day9_2.cpp)

find_library(AOC_LIB AoC ${CMAKE_SOURCE_DIR}/..)
target_link_libraries(Day9 LINK_PUBLIC ${AOC_LIB})