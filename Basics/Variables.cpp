//
// Created by rolledm on 13.04.18.
//

#include <boost/algorithm/string.hpp>
#include <iostream>
#include <vector>
#include <ncurses.h>
#include "Variables.h"
#include "../Includes/Retvals.h"

Variables::Variables() {
    for (char **env = environ; *env; ++env){
        std::string temp(*env);
        std::vector<std::string> vector;
        boost::split(vector, temp, boost::is_any_of("="));
        vars.emplace_back(vector[0], vector[1], false);
    }
}

void Variables::print(bool user) {
    for (auto& it : vars) {
        if (it.created_by_user == user)
            printw("%s is %s\n", it.name.c_str(), it.value.c_str());
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
    vars.emplace_back(name, value, true);
    return GOOD;
}

std::string Variables::setValue(const std::string &name, const std::string &value, bool user) {
    vars.emplace_back(name, value, user);
    return GOOD;
}
