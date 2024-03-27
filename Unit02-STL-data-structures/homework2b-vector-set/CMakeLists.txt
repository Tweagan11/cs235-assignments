cmake_minimum_required(VERSION 3.27)
project(homework2b_vector_set)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(homework2b_vector_set
        tests.cpp
        VectorSet.h)
