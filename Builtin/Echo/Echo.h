//
// Created by rolledm on 11.04.18.
//

#ifndef INTERPRETER_ECHO_H
#define INTERPRETER_ECHO_H


#include "../Builtin.h"

class Echo : public Builtin {
public:
    explicit Echo();

    std::string start(std::vector<std::string> argv) override;

};


#endif //INTERPRETER_ECHO_H
