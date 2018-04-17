//
// Created by rolledm on 17.04.18.
//

#ifndef INTERPRETER_ALIAS_H
#define INTERPRETER_ALIAS_H


#include <string>
#include <utility>

class Alias {
public:
    Alias(std::string pseudoName, std::string name) {
        alias.first = std::move(pseudoName);
        alias.second = std::move(name);
    }

    std::pair<std::string, std::string> alias;
};


#endif //INTERPRETER_ALIAS_H
