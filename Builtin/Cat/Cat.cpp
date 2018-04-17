//
// Created by rolledm on 17.04.18.
//

#include <fstream>
#include <ncurses.h>
#include "Cat.h"
#include "../../Includes/Retvals.h"

Cat::Cat() : Builtin("cat") {}

std::string Cat::start(std::vector<std::string> argv, Variables *vars) {
    std::vector<std::string> vec;
    if (!argv.empty()) {
        std::ifstream file(argv[0]); // Handle
        std::string str;
        if (!file.is_open()) return NO_FILE;
        while (getline(file, str)) {
            printw("%s\n", str.c_str());
            //vec.emplace_back(str);
        }
        file.close();
    } else return INVALID_ARGS;
    return GOOD;
}
