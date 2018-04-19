//
// Created by rolledm on 11.04.18.
//

#include <iostream>
#include <boost/algorithm/string.hpp>
#include <ncurses.h>
#include "Interpreter.h"
#include "Includes/Includes.h"

Interpreter::Interpreter() {

    std::string ps1 = "<" + vars.getValue("LOGNAME") + " " + shortPwd() + "> ";
    vars.setValue("PS1", ps1, false);
    vars.setValue("SHLVL", std::to_string(atoi(vars.getValue("SHLVL").c_str()) + 1)); // incrementing level of shell nesting

    parser = new Parser();
}

void Interpreter::work() {

    init_pair(RED, COLOR_RED, COLOR_BLACK);
    init_pair(YELLOW, COLOR_YELLOW, COLOR_BLACK);
    init_pair(GREEN, COLOR_GREEN, COLOR_BLACK);
    init_pair(CYAN, COLOR_CYAN, COLOR_BLACK);
    init_pair(MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(BLUE, COLOR_BLUE, COLOR_BLACK);
    init_pair(WHITE, COLOR_WHITE, COLOR_BLACK);


    //AUTOLOAD. TODO: detached functions in 'WORK'
    Start start;
    std::vector<std::string> autoload;
    autoload.emplace_back("autoload");
    for (auto& it : start.start(autoload, &vars)) {
        parser->parse(it, &vars);
    }



    std::string str;
    while (true) {
        std::string ps1 = "<" + vars.getValue("LOGNAME") + " " + shortPwd() + "> ";
        vars.setValue("PS1", ps1, false);

        attron(COLOR_PAIR(GREEN));
        //printw("<%s %s> ", vars.getValue("LOGNAME").c_str(), shortPwd().c_str());
        printw("%s", vars.getValue("PS1").c_str());
        attron(COLOR_PAIR(YELLOW));



        str = "";
        int ch = 0;
        while (ch != '\n') {
            ch = getch();


            if (ch == KEY_UP) {
            }
            if (ch == CTRL('l')) {
                clear();
                break;
            } else if (ch == CTRL('c')) {
                addch('X');
            } else if (ch == 127) {
                if (str.size() > 0) {
                    addch('\b'); // Костыль, каких свет еще не видел
                    addch(' '); // Извращение
                    addch('\b'); // С этим надо что-то сделать
                    str = str.substr(0, str.size() - 1);
                }
            } else {
                printw("%c", ch);
                str += (char)ch;
            }
        }
        str = str.substr(0, str.size() - 1);

        attron(COLOR_PAIR(GREEN));

        parser->parse(str, &vars);

        attron(COLOR_PAIR(GREEN));

    }


}



/*void Interpreter::parse(const std::string& promt) {

    std::vector<std::string> spl;
    boost::split(spl, promt, boost::is_any_of(" "));
    bool flag = false;

    for (auto& it : spl) {   // Getting values of variables.
        if (it[0] == '$') {
            it = vars.getValue(it.substr(1, it.size()));
        }
    }

    for (auto& it : builtinList) {  // start the builtin util
        if (spl[0] == it->functionName) {
            std::vector<std::string> args(spl.begin() + 1, spl.end());
            it->start(args, &vars);
            flag = true;
            break;
        }
    }
    if (!flag) {
        attron(RED);
        printw("Unknown command: %s\n", promt.c_str());
    }

}*/



std::string Interpreter::shortPwd() {
    std::string str = vars.getValue("PWD");
    std::string shortStr;

    if (str == "~") return str;

    for (int i = str.length() - 1; i >= 0; --i) {
        if (str[i] != '/') {
            shortStr += str[i];
        } else {
            break;
        }
    }
    std::reverse(shortStr.begin(), shortStr.end());
    return shortStr;
}

std::string Interpreter::input() {
    return std::__cxx11::string();
}
