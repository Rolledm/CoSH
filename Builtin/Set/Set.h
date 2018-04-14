//
// Created by rolledm on 14.04.18.
//

#ifndef INTERPRETER_SET_H
#define INTERPRETER_SET_H


#include "../Builtin.h"

class Set: public Builtin {
public:
    Set();

    std::string start(std::vector<std::string> argv, Variables* vars) override;

};


#endif //INTERPRETER_SET_H
