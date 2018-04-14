//
// Created by rolledm on 14.04.18.
//

#include "Set.h"
#include "../../Includes/Retvals.h"

Set::Set(): Builtin("set") {}

std::string Set::start(std::vector<std::string> argv, Variables* vars) {
    vars->setValue(argv[0], argv[1]);
    return GOOD;
}
