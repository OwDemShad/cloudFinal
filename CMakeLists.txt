cmake_minimum_required(VERSION 3.9)
project(untitled1)

set(CMAKE_CXX_STANDARD 11)

add_executable(untitled1 main.cpp Sources/case.cpp Headers/case.h Sources/element.cpp Headers/element.h
        Sources/laser.cpp Headers/laser.h Sources/miroir.cpp Headers/miroir.h Sources/terrain.cpp Headers/terrain.h
        )