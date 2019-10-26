cmake_minimum_required(VERSION 3.15)
project(1F)

set(CMAKE_CXX_STANDARD 17)

set(src buffered_reader.h main.cpp)

add_executable(1F ${src})