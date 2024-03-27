cmake_minimum_required(VERSION 3.27)
project(lecture03_references)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lecture03_references
        const_demo_framing.cpp
)
add_executable(const_demo
        const_demo_punchline.cpp
)
add_executable(telling
        const_demo_telling.cpp
)

add_executable(heavy
        heavy_copy.cpp
)
add_executable(reckless
        reckless.cpp
)
add_executable(super_type
        super_type.cpp
)
add_executable(Swap
        swap.cpp
        where.h
)


