//
// Created by rolledm on 25.04.18.
//

#include "History.h"

History::History(int maxsize) : maxsize(maxsize) {

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
