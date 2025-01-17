#pragma once

#include <string>

class Lox {
    public:
        /**
            Runs the lox interpreter on a file. Reads file from disk then calls Lox.run() on it.
         */
        void runFile(const std::string& path);

        void runREPL();

        void run(const std::string& source);
};