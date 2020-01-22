cmake_minimum_required(VERSION 3.10)
project(4C)

SET(CMAKE_CXX_FLAGS -pthread)

find_package(Threads)

set(CMAKE_CXX_STANDARD 17)

add_executable(4C main.cpp solution.h)