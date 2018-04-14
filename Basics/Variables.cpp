//
// Created by rolledm on 13.04.18.
//

#include <boost/algorithm/string.hpp>
#include <iostream>
#include <vector>
#include "Variables.h"
#include "../Includes/Retvals.h"

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

std::string Variables::setValue(const std::string& name, const std::string& value) {
    for (auto& it : vars) {
        if (it.name == name) {
            it.value = value;
            return GOOD;
        }
    }
    vars.push_back(Variable(name, value));
    return GOOD;
}
