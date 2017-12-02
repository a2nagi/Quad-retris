cmake_minimum_required(VERSION 3.8)
project(CS246_Project)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp controller/Block.cpp
        controller/Controller.cc controller/IBlock.cpp controller/JBlock.cpp controller/LBlock.cpp controller/Level0.cc
        controller/Level1.cc controller/Level2.cc controller/Level3.cc
        controller/Level4.cc controller/OBlock.cpp controller/SBlock.cpp controller/TBlock.cpp
        controller/Level.h model/Info.h model/Observer.h model/State.h
        controller/ZBlock.cpp view/TextDisplay.cc model/Cell.cc model/Grid.cc model/Subject.cc controller/Level.cc
        view/graphicsdisplay.cc view/window.cc
        )
add_executable(CS246_Project ${SOURCE_FILES})
