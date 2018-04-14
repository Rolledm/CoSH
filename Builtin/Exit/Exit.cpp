//
// Created by rolledm on 11.04.18.
//

#include "Exit.h"
#include "../../Includes/Retvals.h"

Exit::Exit() : Builtin("exit") {}

std::string Exit::start(std::vector<std::string> argv, Variables* vars) {
    exit(0);
    //return GOOD;
}
