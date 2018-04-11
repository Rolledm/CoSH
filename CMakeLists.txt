cmake_minimum_required(VERSION 3.10)
project(Interpreter)

set(CMAKE_CXX_STANDARD 11)

add_executable(Interpreter main.cpp Includes/Colors.h Includes/Includes.h)