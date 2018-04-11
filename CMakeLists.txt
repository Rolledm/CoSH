cmake_minimum_required(VERSION 3.10)
project(Interpreter)

set(CMAKE_CXX_STANDARD 11)

add_executable(Interpreter main.cpp Includes/Colors.h Includes/Includes.h Builtin/Builtin.cpp Builtin/Builtin.h Builtin/Yes/Yes.cpp Builtin/Yes/Yes.h Builtin/Exit/Exit.cpp Builtin/Exit/Exit.h)