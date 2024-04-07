cmake_minimum_required(VERSION 3.27)
project(homework5c_avl_rebalance)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(test_files)

add_executable(homework5c_avl_rebalance
        test_files/test1.stdout.txt
        test_files/test10.stdout.txt
        test_files/test2.stdout.txt
        test_files/test3.stdout.txt
        test_files/test4.stdout.txt
        test_files/test5.stdout.txt
        test_files/test6.stdout.txt
        test_files/test7.stdout.txt
        test_files/test8.stdout.txt
        test_files/test9.stdout.txt
        printing.h
        rebalance.h
        tests.cpp)
