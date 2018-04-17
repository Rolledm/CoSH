//
// Created by rolledm on 17.04.18.
//

#ifndef INTERPRETER_FUNCTION_H
#define INTERPRETER_FUNCTION_H


#include <vector>
#include "../../Basics/Variables.h"
#include "../../Basics/Func.h"

class Function {
public:
    Func start(std::vector<std::string> argv);
};


#endif //INTERPRETER_FUNCTION_H
