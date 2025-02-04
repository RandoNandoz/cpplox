#pragma once

#include <string>
#include "errorreporter/ErrorReportable.hpp"
#include "errorreporter/IErrorReporter.hpp"

class Lox : ErrorReportable {
   public:
    explicit Lox(const IErrorReporter& error_reporter);
    /**
        Runs the lox interpreter on a file. Reads file from disk then calls Lox.run() on it.
     */
    void run_file(const std::string& path);

    void run_REPL();

    void run(const std::string& source);

   private:
    bool hadError;

    void log_error(const int line, const std::string& message);
    void report(const int line, const std::string& where, const std::string& message);
};