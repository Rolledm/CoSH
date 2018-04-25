//
// Created by rolledm on 25.04.18.
//

#ifndef INTERPRETER_HISTORY_H
#define INTERPRETER_HISTORY_H


#include <string>
#include <vector>

class History {
public:
    explicit History(int maxsize);
    void push(std::string elem);
    std::string get(int num);
    int getSize();

private:
    const int maxsize;
    std::vector<std::string> history;
};


#endif //INTERPRETER_HISTORY_H
