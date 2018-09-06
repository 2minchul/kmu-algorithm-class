cmake_minimum_required(VERSION 3.12)
project(6_Palindrom)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(6_Palindrom
        CMakeLists.txt
        develop.cpp
        develop.h
        input.txt
        main.cpp)
