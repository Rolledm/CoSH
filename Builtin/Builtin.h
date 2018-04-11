//
// Created by rolledm on 11.04.18.
//

#ifndef INTERPRETER_BUILTIN_H
#define INTERPRETER_BUILTIN_H

#include <string>
#include <vector>

class Builtin {
public:

    explicit Builtin(std::string functionName);

    virtual std::string start(std::vector<std::string> argv) = 0;

    std::string functionName;
};


#endif //INTERPRETER_BUILTIN_H

