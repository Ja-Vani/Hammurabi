cmake_minimum_required(VERSION 3.26)
project(Hammurabi)

set(CMAKE_CXX_STANDARD 20)

include_directories(Inc)

set(SOURCE
        Src/main.cpp
        Src/logic.cpp
        Inc/logic.h
)

add_executable(Hammurabi ${SOURCE})