#include <iostream>
#include <sysexits.h>
#include "lox/Lox.hpp" 

int main(int argc, char* argv[]) {
    Lox lox;
    if (argc > 2) {
        std::cout << "Usage: cpplox: [script]\n";
        return EX_USAGE;
    } else if (argc == 2) {
        lox.runFile(argv[0]);
    } else {
        lox.runREPL();
    }

    return EX_OK;
}