cmake_minimum_required(VERSION 3.15)
project(2D)

set(CMAKE_CXX_STANDARD 17)

set(src main.cpp format_visitor.h)

add_executable(2D ${src})