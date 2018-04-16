//
// Created by rolledm on 16.04.18.
//

#ifndef INTERPRETER_START_H
#define INTERPRETER_START_H


#include "../Builtin.h"

class Start: public Builtin {
public:
    Start();

    std::string start(std::vector<std::string> argv, Variables* vars) override;
};


#endif //INTERPRETER_START_H
