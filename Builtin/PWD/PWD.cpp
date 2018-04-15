//
// Created by rolledm on 11.04.18.
//

#include <iostream>
#include <ncurses.h>
#include "PWD.h"
#include "../../Includes/Retvals.h"

PWD::PWD() : Builtin("pwd") {}

std::string PWD::start(std::vector<std::string> argv, Variables* vars) {
    //std::cout << vars->getValue("PWD") << std::endl;
    printw("%s\n",vars->getValue("PWD").c_str());
    return GOOD;
}
