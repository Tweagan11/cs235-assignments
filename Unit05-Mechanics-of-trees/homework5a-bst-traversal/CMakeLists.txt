cmake_minimum_required(VERSION 3.27)
project(homework5a_bst_traversal)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(homework5a_bst_traversal
        find.h
        printing.h
        tests.cpp)
