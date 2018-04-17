//
// Created by rolledm on 16.04.18.
//

#ifndef INTERPRETER_PARSER_H
#define INTERPRETER_PARSER_H


#include <string>
#include "Builtin/Builtin.h"
#include "Includes/Includes.h"
#include "Basics/Func.h"
#include <list>

class Parser {
public:
    Parser();

    void parse (const std::string& promt, Variables* vars);

    std::list<Builtin*> builtinList;
    std::list<Func> functionsList;
};


#endif //INTERPRETER_PARSER_H
