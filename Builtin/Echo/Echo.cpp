//
// Created by rolledm on 11.04.18.
//

#include <iostream>
#include <ncurses.h>
#include <fstream>
#include "Echo.h"
#include "../../Includes/Retvals.h"
#include "../../Includes/Colors.h"

Echo::Echo() : Builtin("echo") {}

std::string Echo::start(std::vector<std::string> argv, Variables* vars) {

    if (argv.size() >= 2) {
        if (argv[argv.size() - 2] == ">") {
            std::ofstream file(argv[argv.size() - 1]);
            if (!file.is_open()) return PERM_DEN;

            for (int i = 0; i < argv.size() - 2; ++i) {
                file << argv[i] << " ";
            }
            file << '\b';
        }
    } else {

    for(auto& it : argv) {
        printw("%s ", it.c_str());
    }

    printw("\b\n"); }
    return GOOD;
}
