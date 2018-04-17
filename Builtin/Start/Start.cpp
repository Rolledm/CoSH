//
// Created by rolledm on 16.04.18.
//

#include "Start.h"
#include "../../Includes/Retvals.h"

#include <fstream>
#include <ncurses.h>

std::vector<std::string> Start::start(std::vector<std::string> argv, Variables *vars) {
    std::vector<std::string> vec;
    if (!argv.empty()) {
        std::ifstream file(argv[0]); // Handle
        std::string str;
        if (!file.is_open()) printw("NOPE\n");
        while (getline(file, str)) {
            vec.emplace_back(str);
        }
        file.close();
    } //else return INVALID_ARGS;
    return vec;
}


