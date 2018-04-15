//
// Created by rolledm on 11.04.18.
//

#include <iostream>
#include <boost/algorithm/string.hpp>
#include <ncurses.h>
#include "Interpreter.h"
#include "Includes/Includes.h"

Interpreter::Interpreter() {


    /*for (char **env = environ; *env; ++env){
        std::string temp(*env);
        std::vector<std::string> tempVector;
        boost::split(tempVector, temp, boost::is_any_of("="));
        //std::cout << temp << std::endl;
        variables.emplace_back(tempVector[0], tempVector[1]);
    }*/

    /*for (auto& it : variables) {
        std::cout << it.name << std::endl;
    }*/

    builtinList.push_back(new Yes());
    builtinList.push_back(new Exit());
    builtinList.push_back(new Echo());
    builtinList.push_back(new LS());
    builtinList.push_back(new PWD());
    builtinList.push_back(new Set());
    builtinList.push_back(new Vars());
}

void Interpreter::work() {

    init_pair(RED, COLOR_RED, COLOR_BLACK);
    init_pair(YELLOW, COLOR_YELLOW, COLOR_BLACK);
    init_pair(GREEN, COLOR_GREEN, COLOR_BLACK);
    init_pair(CYAN, COLOR_CYAN, COLOR_BLACK);
    init_pair(MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(BLUE, COLOR_BLUE, COLOR_BLACK);
    init_pair(WHITE, COLOR_WHITE, COLOR_BLACK);



    std::string str;
    while (true) {
        //std::cout << YELLOW << "<" << vars.getValue("LOGNAME") << " " << shortPwd() << "> " << GREEN;

        attron(COLOR_PAIR(GREEN));
        printw("<%s %s> ", vars.getValue("LOGNAME").c_str(), shortPwd().c_str());
        attron(COLOR_PAIR(YELLOW));
        //getch();



        //std::getline(std::cin, str);
        //scanw("%s", str);
        str = "";
        int ch = 0;
        while (ch != '\n') {
            ch = getch();
            if (ch == CTRL('c')) {
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

        //std::cout << STANDART;
        attron(COLOR_PAIR(GREEN));

        std::vector<std::string> spl;
        boost::split(spl, str, boost::is_any_of(" "));
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
            //std::cout << RED << "Unknown command: " << str << std::endl;
            attron(RED);
            printw("Unknown command: %s\n", str.c_str());
        }


        //std::cout << RED;
        //for (auto& it : spl) {
        //    std::cout << it << std::endl;
        //}

        //std::cout << STANDART;
        attron(GREEN);



    }


}

std::string Interpreter::shortPwd() {
    std::string str = getenv("PWD");
    std::string shortStr;

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