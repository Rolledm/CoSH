//
// Created by rolledm on 14.04.18.
//

#include <boost/algorithm/string.hpp>
#include "Vars.h"
#include "../../Includes/Retvals.h"

Vars::Vars(): Builtin("vars") {}

std::string Vars::start(std::vector<std::string> argv, Variables *vars) {

    if (argv.size() == 1) {
        size_t pos = argv[0].find('=');
        if (pos != std::string::npos) {
            std::vector<std::string> spl;
            boost::split(spl, argv[0], boost::is_any_of("="));
            if (spl.size() == 2) {
                if (spl[0] == "-user") {     // ARG = "-user".
                    if (spl[1] == "true") {
                        vars->print(true);
                        return GOOD;
                    } else if (spl[1] == "false") {
                        vars->print(false);
                        return GOOD;
                    } else return INVALID_ARGS;
                }
            } else return INVALID_ARGS;
        } else return INVALID_ARGS;
    }

    vars->print(false);
    vars->print(true);
    return GOOD;
}
