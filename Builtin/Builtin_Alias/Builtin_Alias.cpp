//
// Created by rolledm on 17.04.18.
//

#include "Builtin_Alias.h"
#include "../../Includes/Retvals.h"

Alias Builtin_Alias::start(std::vector<std::string> argv) {
    if (argv.size() == 2) {
        return Alias(argv[0], argv[1]);
    } else return Alias(INVALID_ARGS, INVALID_ARGS);
}
