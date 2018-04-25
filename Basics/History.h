//
// Created by rolledm on 25.04.18.
//

#ifndef INTERPRETER_HISTORY_H
#define INTERPRETER_HISTORY_H


#include <string>
#include <vector>

class History {
public:
    History();
    void push(std::string elem);
    std::string get(int num);
    int getSize();

    void save();

private:
    const int maxsize = 10;
    std::vector<std::string> history;
};


#endif //INTERPRETER_HISTORY_H
