//
// Created by rolledm on 17.04.18.
//

#ifndef INTERPRETER_BUILTIN_ALIAS_H
#define INTERPRETER_BUILTIN_ALIAS_H


#include "../Builtin.h"
#include "../../Basics/Alias.h"

class Builtin_Alias{
public:
    Alias start(std::vector<std::string> argv);
};


#endif //INTERPRETER_BUILTIN_ALIAS_H
