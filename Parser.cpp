//
// Created by rolledm on 16.04.18.
//

#include "Parser.h"
#include <vector>
#include <boost/algorithm/string.hpp>
#include <ncurses.h>
#include "Includes/Includes.h"
#include "Builtin/Function/Function.h"


Parser::Parser() {
    builtinList.push_back(new Yes());
    builtinList.push_back(new Exit());
    builtinList.push_back(new Echo());
    builtinList.push_back(new LS());
    builtinList.push_back(new PWD());
    builtinList.push_back(new Set());
    builtinList.push_back(new Vars());
    //builtinList.push_back(new Start());
}


void Parser::parse(const std::string& promt, Variables* vars) {

    std::vector<std::string> spl;
    boost::split(spl, promt, boost::is_any_of(" "));
    bool flag = false;

    for (auto& it : spl) {   // Getting values of variables.
        if (it[0] == '$') {
            it = vars->getValue(it.substr(1, it.size()));
        }
    }

    std::vector<std::string> args(spl.begin() + 1, spl.end()); /////////
    for (auto& it : builtinList) {  // start the builtin util
        if (spl[0] == it->functionName) {
            ///////
            it->start(args, vars);
            flag = true;
            break;
        }
    }

    if (spl[0] == "start") {
        Start start;
        std::vector<std::string> vector = start.start(args, vars);
        for (auto& it : vector) {
            parse(it, vars);
        }
        flag = true;
    } else

        if (spl[0] == "function") {
            Function function;
            Func func = function.start(args);
            if (func.functionName != INVALID_ARGS) {
                functionsList.emplace_back(func);
            }
            flag = true;
        } else

            for (auto& it : functionsList) {
                if (spl[0] == it.functionName) {
                    for (auto& task : it.tasks) {
                        parse(task, vars);
                    }
                    flag = true;
                    break;
                }
            }



    if (!flag) {
        attron(RED);
        printw("Unknown command: %s\n", promt.c_str());
    }

}
