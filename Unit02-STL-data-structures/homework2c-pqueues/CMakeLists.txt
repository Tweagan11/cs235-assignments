cmake_minimum_required(VERSION 3.27)
project(homework2c_pqueues)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(homework2c_pqueues
        input.h
        pqueues.cpp)
