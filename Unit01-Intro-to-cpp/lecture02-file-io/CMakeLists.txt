cmake_minimum_required(VERSION 3.27)
project(lecture02_file_io)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lecture02_file_io
        add_bullets.cpp)
add_executable(Count count_words.cpp words.txt)
add_executable(Strings sum_lines.cpp)
