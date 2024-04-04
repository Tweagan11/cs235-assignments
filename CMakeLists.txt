cmake_minimum_required(VERSION 3.27)
project(cs235_assignments)

set(CMAKE_CXX_STANDARD 14)

include_directories(Unit03-Sorting/homework3d-quicksort)

add_executable(cs235_assignments
        Unit03-Sorting/homework3d-quicksort/test_files/test1.stdout.txt
        Unit03-Sorting/homework3d-quicksort/test_files/test2.stdout.txt
        Unit03-Sorting/homework3d-quicksort/test_files/test3.stdout.txt
        Unit03-Sorting/homework3d-quicksort/test_files/test4.stdout.txt
        Unit03-Sorting/homework3d-quicksort/test_files/test5.stdout.txt
        Unit03-Sorting/homework3d-quicksort/test_files/test6.stdout.txt
        Unit03-Sorting/homework3d-quicksort/test_files/test7.stdout.txt
        Unit03-Sorting/homework3d-quicksort/instructions.md
        Unit03-Sorting/homework3d-quicksort/QS.h
        Unit03-Sorting/homework3d-quicksort/tests.cpp)
