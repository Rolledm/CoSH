//
// Created by rolledm on 17.04.18.
//

#ifndef INTERPRETER_CAT_H
#define INTERPRETER_CAT_H


#include "../Builtin.h"

class Cat : public Builtin {
public:
    explicit Cat();

    std::string start(std::vector<std::string> argv, Variables* vars) override;
};


#endif //INTERPRETER_CAT_H
