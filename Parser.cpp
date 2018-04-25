//
// Created by rolledm on 16.04.18.
//

#include "Parser.h"
#include <vector>
#include <boost/algorithm/string.hpp>
#include <ncurses.h>
#include <fstream>
#include <iostream>
#include <fcntl.h>
#include <sys/wait.h>
#include "Includes/Includes.h"
#include "Builtin/Function/Function.h"
#include "Builtin/Builtin_Alias/Builtin_Alias.h"


Parser::Parser(Variables* vars) {
    builtinList.push_back(new Yes());
    builtinList.push_back(new Exit());
    builtinList.push_back(new Echo());
    builtinList.push_back(new LS());
    builtinList.push_back(new PWD());
    builtinList.push_back(new Set());
    builtinList.push_back(new Vars());
    builtinList.push_back(new Clear());
    builtinList.push_back(new Cat());



    std::vector<std::string> PATH;  // programms from PATH init
    std::string temp = vars->getValue("PATH");
    boost::split(PATH, temp, boost::is_any_of(":"));

    for (auto& it : PATH)
    {
        std::ofstream f("temp");
        f.close();

        int fd = open("temp", O_RDWR);
        int save_out = dup(fileno(stdout));
        dup2(fd, fileno(stdout));

        char* arg[] = {const_cast<char *>("/bin/ls"), const_cast<char *>(it.c_str()), nullptr};

        int retval;
        if ((fork()) == 0) {
            execve("/bin/ls", arg, environ);
        } else {
            wait(&retval);
        }

        dup2(save_out, fileno(stdout));
        close(fd);

        std::ifstream file("temp"); // Handle
        std::string str;
        if (!file.is_open()) printw("NOPE\n");
        while (getline(file, str)) {
            programmList.emplace_back(Programm(str, it));
        }
        file.close();


    }
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
        if (spl[0] == it->getName()) {
            ///////
            it->start(args, vars);
            flag = true;
            break;
        }
    }

    for (auto& it : aliasesList) {
        if (spl[0] == it.alias.first) {
            for (auto& task : builtinList) {
                if (task->getName() == it.alias.second) {
                    task->start(args, vars);
                    flag = true;
                    goto metka;
                }
            }
        }
    }
    metka:

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
            }        //HANDLE ERRORS
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

    if (spl[0] == "alias") {
        Builtin_Alias BA;
        Alias alias = BA.start(args);
        if (alias.alias.first != alias.alias.second) {
            aliasesList.emplace_back(alias);
        } else {
            attron(PAIR_NUMBER(RED));
            printw("%s", alias.alias.first.c_str());
            attron(PAIR_NUMBER(GREEN));
        }
        flag = true;
    }

    if (spl[0] == "ex") {


        if (spl.size() > 1) {

            std::string prg;

            for(auto& it : programmList) {
                //printw("%s : %s\n", it.name.c_str(), spl[1].c_str());
                //getch();


                if (it.name == spl[1]) {
                    prg += it.path + '/' + it.name;
                    break;
                }
            }

            if (!prg.empty()) {

                std::ofstream f("temp");
                f.close();

                int fd = open("file", O_WRONLY);
                int save_out = dup(fileno(stdout));
                dup2(fd, fileno(stdout));

                char* arg[] = {const_cast<char *>(prg.c_str()), nullptr};

                int retval;
                if ((fork()) == 0) {
                    execve(prg.c_str(), arg, environ);
                } else {
                    wait(&retval);
                }

                dup2(save_out, fileno(stdout));
                close(fd);

                std::ifstream file("file"); // Handle
                std::string str;
                if (!file.is_open()) printw("NOPE\n");
                while (getline(file, str)) {
                    printw("%s\n", str.c_str());
                }
                file.close();


            } else {
                printw("%s\n", NO_FILE);
            }



        } else {
            printw("%s\n", INVALID_ARGS);
        }
        flag = true;
    }




    if (!flag) {
        attron(PAIR_NUMBER(RED));
        if (!promt.empty()) {
            printw("Unknown command: %s\n", promt.c_str());
        }
    }

}
