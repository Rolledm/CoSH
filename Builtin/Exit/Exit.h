//
// Created by rolledm on 11.04.18.
//

#ifndef INTERPRETER_EXIT_H
#define INTERPRETER_EXIT_H


#include "../Builtin.h"

class Exit : public Builtin {
public:
    explicit Exit();

    std::string start(std::vector<std::string> argv, Variables vars) override;

};


#endif //INTERPRETER_EXIT_H
