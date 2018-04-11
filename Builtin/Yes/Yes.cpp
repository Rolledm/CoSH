//
// Created by rolledm on 11.04.18.
//

#include "Yes.h"
#include <utility>
#include <iostream>

Yes::Yes() : Builtin("yes") {}

std::string Yes::start(std::vector<std::string> argv) {
    std::string output;
    if(argv.size() == 0) {
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
    return "";
}



