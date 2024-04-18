cmake_minimum_required(VERSION 3.27)
project(homework4d_vector_iterators)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(homework4d_vector_iterators
        test_files/test1.stdout.txt
        test_files/test2.stdout.txt
        tests.cpp
        Vector.h)
