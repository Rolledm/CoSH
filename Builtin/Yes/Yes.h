//
// Created by rolledm on 11.04.18.
//

#ifndef INTERPRETER_YES_H
#define INTERPRETER_YES_H


#include "../Builtin.h"

class Yes : public Builtin {
public:
    explicit Yes();

    std::string start(std::vector<std::string> argv, Variables vars) override;
};


#endif //INTERPRETER_YES_H
