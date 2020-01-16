cmake_minimum_required(VERSION 3.10)
project(4A)

SET(CMAKE_CXX_FLAGS -pthread)

find_package(Threads)

set(CMAKE_CXX_STANDARD 17)

add_executable(4A main.cpp)