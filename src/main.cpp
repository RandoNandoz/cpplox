#include <iostream>
#include <sysexits.h>
#include "lox/Lox.hpp" 

int main(int argc, char* argv[]) {
    if (argc > 1) {
        std::cout << "Usage: cpplox: [script]";
        return EX_USAGE;
    } else if (argc == 1) {
        // run the file
    } else {
        // run the REPL
    }

    return EX_OK;
}