cmake_minimum_required(VERSION 3.9)
project(untitled1)

set(CMAKE_CXX_STANDARD 11)

add_executable(untitled1 main.cpp case.cpp case.h element.cpp element.h
        laser.cpp laser.h miroir.cpp miroir.h terrain.cpp terrain.h)