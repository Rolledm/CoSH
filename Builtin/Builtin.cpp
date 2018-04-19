//
// Created by rolledm on 11.04.18.
//

#include "Builtin.h"
#include <utility>

Builtin::Builtin(std::string functionName) : functionName(std::move(functionName)) {}

void Builtin::setName(std::string functionName) {
    this->functionName = std::move(functionName);
}

std::string Builtin::getName() {
    return functionName;
}
