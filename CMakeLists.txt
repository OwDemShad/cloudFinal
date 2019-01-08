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
        Headers/graphics.h Sources/winbgi.cpp

        Tests/Headers/doctest.h
        Tests/Sources/testCase.cpp
        Tests/Sources/testLaser.cpp
        Tests/Sources/testmain.cpp
        Tests/Sources/testPosition.cpp
        Tests/Sources/testTerrainMursFins.cpp
        Tests/Sources/testTerrainMursPleins.cpp
        )