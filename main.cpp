#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>
#include <vector>

#include <unistd.h>

#include "Includes/Includes.h"

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

    std::string str;
    std::string greet = "greet";//getenv("PS1");

    while (true) {
        std::cout << YELLOW << "<" <<getenv("LOGNAME") << " " << shortPwd() << "> " << GREEN;

        std::getline(std::cin, str);
        std::cout << STANDART;
        if (str == "exit") exit(0);
        std::vector<std::string> spl;
        boost::split(spl, str, boost::is_any_of(" "));
        std::cout << RED;
        for (auto& it : spl) {
            std::cout << it << std::endl;
        }
        std::cout << STANDART;

    }


    return 0;
}