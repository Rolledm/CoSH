//
// Created by rolledm on 16.04.18.
//

#include "Parser.h"
#include <vector>
#include <boost/algorithm/string.hpp>
#include <ncurses.h>
#include "Includes/Includes.h"


void Parser::parse(const std::string& promt, Variables* vars, std::list<Builtin*> builtinList) {

    std::vector<std::string> spl;
    boost::split(spl, promt, boost::is_any_of(" "));
    bool flag = false;

    for (auto& it : spl) {   // Getting values of variables.
        if (it[0] == '$') {
            it = vars->getValue(it.substr(1, it.size()));
        }
    }

    for (auto& it : builtinList) {  // start the builtin util
        if (spl[0] == it->functionName) {
            std::vector<std::string> args(spl.begin() + 1, spl.end());
            it->start(args, vars);
            flag = true;
            break;
        }
    }
    if (!flag) {
        attron(RED);
        printw("Unknown command: %s\n", promt.c_str());
    }

}