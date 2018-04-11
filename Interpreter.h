//
// Created by rolledm on 11.04.18.
//

#ifndef INTERPRETER_INTERPRETER_H
#define INTERPRETER_INTERPRETER_H


#include <vector>
#include "Basics/Variable.h"
#include "Builtin/Builtin.h"

class Interpreter {
public:
    Interpreter();

    void work();
    std::string shortPwd();

    std::vector<Variable> variables;
    std::vector<Builtin*> builtinList;
};


#endif //INTERPRETER_INTERPRETER_H
