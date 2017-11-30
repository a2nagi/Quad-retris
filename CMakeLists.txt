cmake_minimum_required(VERSION 3.8)
project(CS246_Project)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp model/Cell.h view/TextDisplay.h controller/Controller.h controller/Level.h controller/Block.cpp
        controller/Controller.cc controller/IBlock.cpp controller/JBlock.cpp controller/LBlock.cpp controller/Level0.cc controller/Level0.h
        controller/Level1.cc controller/Level1.h controller/Level2.cc controller/Level2.h controller/Level3.cc controller/Level3.h
        controller/Level4.cc controller/Level4.h controller/OBlock.cpp controller/OBlock.h controller/SBlock.cpp controller/TBlock.cpp
        controller/ZBlock.cpp view/TextDisplay.cc
        controller/Block.h controller/IBlock.h controller/JBlock.h controller/LBlock.h controller/OBlock.h controller/TBlock.h
        controller/SBlock.h controller/ZBlock.h model/Cell.h model/Observer.h model/State.h model/Subject.h model/Info.h model/Grid.h model/Cell.cc model/Grid.cc)
add_executable(CS246_Project ${SOURCE_FILES})
