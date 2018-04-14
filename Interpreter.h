//
// Created by rolledm on 11.04.18.
//

#ifndef INTERPRETER_INTERPRETER_H
#define INTERPRETER_INTERPRETER_H


#include <list>
#include "Basics/Variable.h"
#include "Builtin/Builtin.h"
#include "Basics/Variables.h"

class Interpreter {
public:
    Interpreter();

    void work();
    std::string shortPwd();

    Variables vars;
    //std::list<Variable> variables;
    std::list<Builtin*> builtinList;
};


#endif //INTERPRETER_INTERPRETER_H
