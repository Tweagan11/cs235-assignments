cmake_minimum_required(VERSION 3.27)
project(lecture2c_queue_stack_pqueue)

set(CMAKE_CXX_STANDARD 23)

include_directories(.)

add_executable(lecture2c_queue_stack_pqueue
        wait_in_line.cpp
        input.h)

add_executable(postfix
        postfix.cpp
        input.h)
