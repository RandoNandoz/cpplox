#pragma once

#include <iostream>
#include <string>

class Lox {
   public:
    Lox();
    /**
        Runs the lox interpreter on a file. Reads file from disk then calls Lox.run() on it.
     */
    void runFile(const std::string& path);

    void runREPL();

    void run(const std::string& source);

   private:
    bool hadError;
    void logError(const int line, const std::string& message);

    void report(const int line, const std::string& where, const std::string& message);
};