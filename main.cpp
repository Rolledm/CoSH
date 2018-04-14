#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>
#include <vector>

#include <unistd.h>

#include "Includes/Includes.h"
#include "Interpreter.h"



int main(int argc, char* argv[])
{
    system("clear");
    Interpreter interpreter;
    interpreter.work();
    return 0;
}