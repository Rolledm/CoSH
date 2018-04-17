//
// Created by rolledm on 16.04.18.
//

#ifndef INTERPRETER_START_H
#define INTERPRETER_START_H


//#include "../Builtin.h"

#include <string>
#include <vector>
#include "../../Basics/Variables.h"

class Start {
public:
    std::vector<std::string> start(std::vector<std::string> argv, Variables* vars);
};


#endif //INTERPRETER_START_H
