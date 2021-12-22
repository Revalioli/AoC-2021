cmake_minimum_required(VERSION 3.21)
project(Day8)

set(CMAKE_CXX_STANDARD 14)

configure_file(input.txt . COPYONLY)
include_directories(${CMAKE_SOURCE_DIR}/../AoClib)

add_executable(Day8 main.cpp day8_1.cpp day8_2.cpp)

find_library(AOC_LIB AoC ${CMAKE_SOURCE_DIR}/..)
target_link_libraries(Day8 LINK_PUBLIC ${AOC_LIB})