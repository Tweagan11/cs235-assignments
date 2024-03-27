cmake_minimum_required(VERSION 3.27)
project(homework4a_sllist)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(test_files)

add_executable(homework4a_sllist
        test_files/test1.stdout.txt
        test_files/test2.stdout.txt
        test_files/test3.stdout.txt
        test_files/test4.stdout.txt
        SLList.h
        tests.cpp)
