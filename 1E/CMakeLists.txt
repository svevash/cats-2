cmake_minimum_required(VERSION 3.15)
project(1E)

set(CMAKE_CXX_STANDARD 17)

set(src main.cpp num.cpp num.h)

add_executable(1E ${src})