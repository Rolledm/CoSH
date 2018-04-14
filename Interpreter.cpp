//
// Created by rolledm on 11.04.18.
//

#include <iostream>
#include <boost/algorithm/string.hpp>
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
}

void Interpreter::work() {

    std::string str;
    while (true) {
        std::cout << YELLOW << "<" <<getenv("LOGNAME") << " " << shortPwd() << "> " << GREEN;

        std::getline(std::cin, str);
        std::cout << STANDART;
        std::vector<std::string> spl;
        boost::split(spl, str, boost::is_any_of(" "));
        bool flag = false;
        for (auto& it : builtinList) {
            if (spl[0] == it->functionName) {
                std::vector<std::string> args(spl.begin() + 1, spl.end());
                it->start(args, vars); //TODO: FIND VARIABLES
                flag = true;
                break;
            }
        }
        if (!flag) {
            std::cout << RED << "Unknown command: " << str << std::endl;
        }


        //std::cout << RED;
        //for (auto& it : spl) {
        //    std::cout << it << std::endl;
        //}
        std::cout << STANDART;



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