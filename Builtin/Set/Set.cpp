//
// Created by rolledm on 14.04.18.
//

#include "Set.h"
#include "../../Includes/Retvals.h"

Set::Set(): Builtin("set") {}

std::string Set::start(std::vector<std::string> argv, Variables* vars) {
    std::string str;
    for(auto it = argv.begin() + 1; it < argv.end(); it++) {
        str += *it.base() + " ";
    }
    vars->setValue(argv[0], str.substr(0, str.size() - 1));
    return GOOD;
}
