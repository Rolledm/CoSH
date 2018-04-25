//
// Created by rolledm on 25.04.18.
//

#include <fstream>
#include <ncurses.h>
#include <iostream>
#include "History.h"

History::History() {
    std::ifstream file("history"); // Handle
    std::string str;
    if (!file.is_open()) printw("NOPE\n");
    while (getline(file, str)) {
        history.emplace_back(str);
    }
    file.close();
}

void History::push(std::string elem) {
    if (history.size() < maxsize) {
        history.push_back(elem);
    } else {
        for (int i = 0; i < maxsize - 1; ++i) {
            history[i] = history[i + 1];
        }
        history[maxsize - 1] = elem;
    }
}

std::string History::get(int num) {
    return history[num];
}

int History::getSize() {
    return history.size();
}

void History::save() {
    std::ofstream file("history");
    for (auto& it : history) {
        file << it << std::endl;
    }
    file.close();
}
