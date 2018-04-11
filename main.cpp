#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>
#include <vector>

#include <unistd.h>

#include "Includes/Includes.h"
#include "Builtin/Builtin.h"
#include "Builtin/Yes/Yes.h"
#include "Builtin/Exit/Exit.h"

std::string shortPwd() {
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

int main(int argc, char* argv[], char* env[])
{

    std::vector<Builtin*> builtinList;
    builtinList.push_back(new Yes());
    builtinList.push_back(new Exit());



    std::string str;
    std::string greet = "greet";//getenv("PS1");

    while (true) {
        std::cout << YELLOW << "<" <<getenv("LOGNAME") << " " << shortPwd() << "> " << GREEN;

        std::getline(std::cin, str);
        std::cout << STANDART;
        std::vector<std::string> spl;
        boost::split(spl, str, boost::is_any_of(" "));
        //if (spl[0] == "exit") exit(0);
        bool flag = false;
        for (auto& it : builtinList) {
            if (spl[0] == it->functionName) {
                std::vector<std::string> args(spl.begin() + 1, spl.end());
                it->start(args);
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


    return 0;
}