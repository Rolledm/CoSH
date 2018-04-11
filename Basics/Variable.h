//
// Created by rolledm on 11.04.18.
//

#ifndef INTERPRETER_VARIABLE_H
#define INTERPRETER_VARIABLE_H

#include <string>
#include <utility>

class Variable {
public:
    Variable(std::string name, std::string value) : name(std::move(name)), value(std::move(value)) {}

    std::string name;
    std::string value;
};

#endif //INTERPRETER_VARIABLE_H
