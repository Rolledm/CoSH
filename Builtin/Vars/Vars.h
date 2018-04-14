//
// Created by rolledm on 14.04.18.
//

#ifndef INTERPRETER_VARS_H
#define INTERPRETER_VARS_H


#include "../Builtin.h"

class Vars: public Builtin {
public:
    Vars();

    std::string start(std::vector<std::string> argv, Variables* vars) override;
};


#endif //INTERPRETER_VARS_H
