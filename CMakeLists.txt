cmake_minimum_required(VERSION 3.9)
project(Laser)

set(CMAKE_CXX_STANDARD 11)

add_executable(Laser main.cpp
        Headers/affichage.h Sources/affichage.cpp
        Headers/case.h Sources/case.cpp

        Headers/laser.h Sources/laser.cpp
        Headers/position.h Sources/position.cpp
        Headers/terrain.h Sources/terrain.cpp
        Headers/terrainMursFins.h Sources/terrainMursFins.cpp
        Headers/terrainMursPleins.h Sources/terrainMursPleins.cpp
        Headers/element.h Sources/element.cpp

        Tests/Headers/doctest.h
        Tests/Sources/testTerrainMursPleins.cpp Tests/Sources/testmain.cpp)