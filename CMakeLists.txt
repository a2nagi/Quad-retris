cmake_minimum_required(VERSION 3.8)
project(CS246_Project)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp model/Cell.h view/TextDisplay.h controller/Controller.h controller/Level.h controller/Block.h)
add_executable(CS246_Project ${SOURCE_FILES})
