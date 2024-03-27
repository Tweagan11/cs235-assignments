cmake_minimum_required(VERSION 3.27)
project(lecture2b_classes)

set(CMAKE_CXX_STANDARD 23)

include_directories(.)

add_executable(lecture2b_classes
        stuff.h
        uses_stuff.cpp)

add_executable(noisy
        noisy_demo.cpp
        noisy_vector.h
        noisy_vector_solution.h
)

add_executable(counter
        counter_demo.cpp
        counter_demo.cpp)

add_executable(pair
        pair_demo.cpp
        pair_demo.cpp)