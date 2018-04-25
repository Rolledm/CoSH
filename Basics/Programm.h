//
// Created by rolledm on 25.04.18.
//

#ifndef INTERPRETER_PROGRAMM_H
#define INTERPRETER_PROGRAMM_H


#include <string>
#include <utility>

class Programm {
public:
    Programm(std::string name, std::string path) : name(std::move(name)), path(std::move(path)) {}

    std::string name;
    std::string path;
};


#endif //INTERPRETER_PROGRAMM_H
