//
// Created by rolledm on 11.04.18.
//

#ifndef INTERPRETER_INTERPRETER_H
#define INTERPRETER_INTERPRETER_H


#include <list>
#include "Basics/Variable.h"
#include "Builtin/Builtin.h"
#include "Basics/Variables.h"
#include "Parser.h"

class Interpreter {
public:
    Interpreter();

    void work();

    std::string shortPwd();

    void parse(const std::string& promt);

    std::string input();


    Variables vars;
    std::list<Builtin*> builtinList;
    Parser parser;
};


#endif //INTERPRETER_INTERPRETER_H
