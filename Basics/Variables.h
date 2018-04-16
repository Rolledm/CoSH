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

    void print(bool user);
    std::string getValue(const std::string &var);
    std::string setValue(const std::string& name, const std::string& value);
    std::string setValue(const std::string& name, const std::string& value, bool user);

    std::list<Variable> vars;
};


#endif //INTERPRETER_VARIABLES_H
