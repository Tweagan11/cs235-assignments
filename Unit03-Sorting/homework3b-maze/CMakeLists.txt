cmake_minimum_required(VERSION 3.27)
project(homework3b_maze)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(homework3b_maze
        Grid.h
        maze.cpp)

add_executable(test
        test.cpp)
