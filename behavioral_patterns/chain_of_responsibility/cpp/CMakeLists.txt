cmake_minimum_required(VERSION 3.5)

project(c LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main.exe main.cpp department.cpp)
