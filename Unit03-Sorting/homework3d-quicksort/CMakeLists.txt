cmake_minimum_required(VERSION 3.27)
project(homework3d_quicksort)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(homework3d_quicksort
        test_files/test1.stdout.txt
        test_files/test2.stdout.txt
        test_files/test3.stdout.txt
        test_files/test4.stdout.txt
        test_files/test5.stdout.txt
        test_files/test6.stdout.txt
        test_files/test7.stdout.txt
        QS.h
        tests.cpp)
