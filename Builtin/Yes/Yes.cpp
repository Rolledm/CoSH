//
// Created by rolledm on 11.04.18.
//

#include "Yes.h"
#include "../../Includes/Retvals.h"
#include <utility>
#include <iostream>

Yes::Yes() : Builtin("yes") {}

std::string Yes::start(std::vector<std::string> argv, Variables* vars) {
    std::string output;
    if(argv.empty()) {
        output = "yes";
    } else {
        for (auto& it : argv) {
            output += it;
            output += " ";
        }
    }

    for (int i = 0; i < 5; ++i) {
        std::cout << output << std::endl;
    }
    return GOOD;
}



