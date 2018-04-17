//
// Created by rolledm on 17.04.18.
//

#include <ncurses.h>
#include "Function.h"
#include "../../Includes/Retvals.h"
#include "../../Includes/Includes.h"

Func Function::start(std::vector<std::string> argv) {
    if (argv.size() == 1) {
        Func func(argv[0]);

        std::string str;

        while (str != "end") {
            str = "";
            printw("    ");
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
            //printw("%s", str.c_str());
            func.tasks.emplace_back(str);
        }
        func.tasks.pop_back();
        return func;

    } else return Func(INVALID_ARGS);
}
