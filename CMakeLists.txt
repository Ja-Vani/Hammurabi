cmake_minimum_required(VERSION 3.26)
project(Hammurabi)

set(CMAKE_CXX_STANDARD 20)

include_directories(Inc)

#add_subdirectory(test)

set(SOURCE
        Src/main.cpp
        Src/logic.cpp
        Src/menu.cpp
)

add_executable(Hammurabi ${SOURCE})