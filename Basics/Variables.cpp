//
// Created by rolledm on 13.04.18.
//

#include <boost/algorithm/string.hpp>
#include <iostream>
#include <vector>
#include "Variables.h"

Variables::Variables() {
    for (char **env = environ; *env; ++env){
        std::string temp(*env);
        std::vector<std::string> vector;
        boost::split(vector, temp, boost::is_any_of("="));
        vars.emplace_back(vector[0], vector[1]);
    }

    //print();
}

void Variables::print() {
    for (auto& it : vars) {
        std::cout << it.name << " is " << it.value << std::endl;
    }
}

std::string Variables::getValue(const std::string &var) {
    for (auto& it : vars) {
        if (it.name == var) {
            return it.value;
        }
    }
    return "";
}
