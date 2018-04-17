//
// Created by rolledm on 17.04.18.
//

#include <ncurses.h>
#include "Clear.h"
#include "../../Includes/Retvals.h"

Clear::Clear() : Builtin("clear") {}

std::string Clear::start(std::vector<std::string> argv, Variables *vars) {
    clear();
    return GOOD;
}
