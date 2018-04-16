cmake_minimum_required(VERSION 3.10)
project(Interpreter)

set(CMAKE_CXX_STANDARD 11)

add_executable(Interpreter main.cpp Includes/Colors.h Includes/Includes.h Builtin/Builtin.cpp Builtin/Builtin.h Builtin/Yes/Yes.cpp Builtin/Yes/Yes.h Builtin/Exit/Exit.cpp Builtin/Exit/Exit.h Includes/BuiltinFuncsList.h Interpreter.cpp Interpreter.h Includes/Retvals.h Basics/Variable.h Builtin/Echo/Echo.cpp Builtin/Echo/Echo.h Builtin/Ls/LS.cpp Builtin/Ls/LS.h Builtin/PWD/PWD.cpp Builtin/PWD/PWD.h Basics/Variables.cpp Basics/Variables.h Builtin/Set/Set.cpp Builtin/Set/Set.h Builtin/Vars/Vars.cpp Builtin/Vars/Vars.h Builtin/Start/Start.cpp Builtin/Start/Start.h Parser.cpp Parser.h)

set(CMAKE_CXX_FLAGS "-lncurses")