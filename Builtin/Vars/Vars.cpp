//
// Created by rolledm on 14.04.18.
//

#include "Vars.h"
#include "../../Includes/Retvals.h"

Vars::Vars(): Builtin("vars") {}

std::string Vars::start(std::vector<std::string> argv, Variables *vars) {
    vars->print();
    return GOOD;
}
