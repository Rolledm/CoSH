//
// Created by rolledm on 13.04.18.
//

#ifndef INTERPRETER_VARIABLES_H
#define INTERPRETER_VARIABLES_H


#include <list>
#include "Variable.h"

class Variables {
public:

    Variables();

    void print();
    std::string getValue(const std::string &var);

    std::list<Variable> vars;
};


#endif //INTERPRETER_VARIABLES_H
