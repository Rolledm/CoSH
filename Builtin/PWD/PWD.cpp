//
// Created by rolledm on 11.04.18.
//

#include <iostream>
#include "PWD.h"
#include "../../Includes/Retvals.h"

PWD::PWD() : Builtin("pwd") {}

std::string PWD::start(std::vector<std::string> argv, Variables vars) {
    std::cout << getenv("PWD") << std::endl;
    return GOOD;
}
