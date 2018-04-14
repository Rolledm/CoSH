//
// Created by rolledm on 11.04.18.
//

#include <iostream>
#include "Echo.h"
#include "../../Includes/Retvals.h"
#include "../../Includes/Colors.h"

Echo::Echo() : Builtin("echo") {}

std::string Echo::start(std::vector<std::string> argv, Variables vars) {
    for(auto& it : argv) {
        if (it[0] == '$') {
            std::string str = it.substr(1, it.size());
            std::cout << vars.getValue(str);
        } else {
            std::cout << it << " ";
        }
    }
    std::cout << std::endl;
    return GOOD;
}
