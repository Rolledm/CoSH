//
// Created by rolledm on 11.04.18.
//

#include <ncurses.h>
#include "Exit.h"
#include "../../Includes/Retvals.h"

Exit::Exit() : Builtin("exit") {}

std::string Exit::start(std::vector<std::string> argv, Variables* vars) {
    endwin();
    exit(0);
    //return GOOD;
}
