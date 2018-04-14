//
// Created by rolledm on 11.04.18.
//

#ifndef INTERPRETER_PWD_H
#define INTERPRETER_PWD_H


#include "../Builtin.h"

class PWD : public Builtin {
public:
    PWD();

    std::string start(std::vector<std::string> argv, Variables vars) override;
};


#endif //INTERPRETER_PWD_H
