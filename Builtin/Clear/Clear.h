//
// Created by rolledm on 17.04.18.
//

#ifndef INTERPRETER_CLEAR_H
#define INTERPRETER_CLEAR_H


#include "../Builtin.h"

class Clear : public Builtin {
public:
    Clear();
    std::string start(std::vector<std::string> argv, Variables* vars) override;
};


#endif //INTERPRETER_CLEAR_H
