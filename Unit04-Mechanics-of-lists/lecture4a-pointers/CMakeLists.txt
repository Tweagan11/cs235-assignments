cmake_minimum_required(VERSION 3.27)
project(lecture4a_pointers)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lecture4a_pointers
        singly_linked.cpp
        test.cpp)
