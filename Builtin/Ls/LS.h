//
// Created by rolledm on 11.04.18.
//

#ifndef INTERPRETER_LS_H
#define INTERPRETER_LS_H


#include "../Builtin.h"

class LS : public Builtin {
public:
    LS();

    std::string start(std::vector<std::string> argv, Variables vars) override;
};


#endif //INTERPRETER_LS_H
