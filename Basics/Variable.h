//
// Created by rolledm on 11.04.18.
//

#ifndef INTERPRETER_VARIABLE_H
#define INTERPRETER_VARIABLE_H

#include <string>
#include <utility>

class Variable {
public:
    Variable(std::string name, std::string value, bool created_by_user) : name(std::move(name)), value(std::move(value)), created_by_user(created_by_user) {}

    std::string name;
    std::string value;
    bool created_by_user;
};

#endif //INTERPRETER_VARIABLE_H
