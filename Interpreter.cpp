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

    parser = new Parser(&vars);
}

void Interpreter::work() {

    init_pair(RED, COLOR_RED, COLOR_BLACK);
    init_pair(YELLOW, COLOR_YELLOW, COLOR_BLACK);
    init_pair(GREEN, COLOR_GREEN, COLOR_BLACK);
    init_pair(CYAN, COLOR_CYAN, COLOR_BLACK);
    init_pair(MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(BLUE, COLOR_BLUE, COLOR_BLACK);
    init_pair(WHITE, COLOR_WHITE, COLOR_BLACK);


    Start start;
    std::vector<std::string> autoload;
    autoload.emplace_back("autoload");
    for (auto& it : start.start(autoload, &vars)) {
        parser->parse(it, &vars);
    }



    std::string str;
    while (true) {
        std::string ps1 = "<" + vars.getValue("LOGNAME") + " " + shortPwd() + "> ";
        if (vars.getValue("PS1")[0] == '<' ) {vars.setValue("PS1", ps1, false); };

        attron(COLOR_PAIR(GREEN));
        printw("%s", vars.getValue("PS1").c_str());
        attron(COLOR_PAIR(YELLOW));



        str = "";
        int ch = 0;
        int size = 0;
        bool up = false;

        std::string temp;

        while (ch != '\n') {
            ch = getch();



            if (ch == KEY_UP) {

                if (history.getSize() > 0) {

                    if (!up) {
                        temp = str;
                        size = history.getSize() - 1;
                        up = true;
                    }
                    else {
                        if (size > 0) {
                            size--;
                        } else {
                            size = history.getSize() - 1;
                        }
                    }


                    for (int j = 0; j < str.size(); ++j) {
                        addch('\b'); // Костыль, каких свет еще не видел
                        addch(' '); // Извращение
                        addch('\b'); // С этим надо что-то сделать
                    }

                    str = history.get(size);
                    printw("%s", str.c_str());
                    }
            } else if (ch == KEY_DOWN) {

              if (size < history.getSize() - 1) {

                  for (int j = 0; j < str.size(); ++j) {
                      addch('\b'); // Костыль, каких свет еще не видел
                      addch(' '); // Извращение
                      addch('\b'); // С этим надо что-то сделать
                  }

                  size++;
                  str = history.get(size);
                  printw("%s", str.c_str());
              } else {
                  for (int j = 0; j < str.size(); ++j) {
                      addch('\b'); // Костыль, каких свет еще не видел
                      addch(' '); // Извращение
                      addch('\b'); // С этим надо что-то сделать
                  }
                  str = temp;
                  printw("%s", str.c_str());
              }
            } else if (ch == CTRL('l')) {
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

        history.push(str);
        history.save();


        attron(COLOR_PAIR(GREEN));

        parser->parse(str, &vars);

        attron(COLOR_PAIR(GREEN));

    }


}

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
