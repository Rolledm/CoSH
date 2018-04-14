//
// Created by rolledm on 11.04.18.
//

#include <iostream>
#include "LS.h"
#include "../../Includes/Retvals.h"

LS::LS() : Builtin("ls") {}

std::string LS::start(std::vector<std::string> argv, Variables vars) {
    std::cout << getenv("PWD") << std::endl;
    return GOOD;
}
