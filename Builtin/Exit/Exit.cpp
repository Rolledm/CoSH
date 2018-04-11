//
// Created by rolledm on 11.04.18.
//

#include "Exit.h"

Exit::Exit() : Builtin("exit") {}

std::string Exit::start(std::vector<std::string> argv) {
    exit(0);
    return "";
}
