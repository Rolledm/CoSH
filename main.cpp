#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>
#include <vector>

#include <unistd.h>

#include "Includes/Includes.h"
#include "Interpreter.h"
#include <ncurses.h>



int main(int argc, char* argv[])
{
    system("clear");

    initscr();
    keypad(stdscr, TRUE);
    raw();
    noecho();
    start_color();

    scrollok(stdscr, TRUE);

    Interpreter interpreter;
    interpreter.work();

    endwin();

    return 0;
}