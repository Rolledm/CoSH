//
// Created by rolledm on 17.04.18.
//

#ifndef INTERPRETER_FUNC_H
#define INTERPRETER_FUNC_H


#include <string>
#include <list>
#include <utility>

class Func {
public:
    explicit Func(std::string name) : functionName(std::move(name)) {}

    std::list<std::string> tasks;
    std::string functionName;
};


#endif //INTERPRETER_FUNC_H
