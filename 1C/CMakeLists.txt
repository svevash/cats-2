cmake_minimum_required(VERSION 3.15)
project(1C)

set(CMAKE_CXX_STANDARD 17)
set(src main.cpp date.cpp date.h)
add_executable(1C ${src})