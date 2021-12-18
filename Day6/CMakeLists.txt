cmake_minimum_required(VERSION 3.21)
project(Day6)

set(CMAKE_CXX_STANDARD 14)

configure_file(input.txt . COPYONLY)
include_directories(${CMAKE_SOURCE_DIR}/../AoClib)

add_executable(Day6 main.cpp day6_1.cpp day6_2.cpp)

find_library(AOC_LIB AoC ${CMAKE_SOURCE_DIR}/..)
target_link_libraries(Day6 LINK_PUBLIC ${AOC_LIB})