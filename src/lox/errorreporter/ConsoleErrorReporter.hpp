#pragma once
#include "IErrorReporter.hpp"

class ConsoleErrorReporter : public IErrorReporter {
   public:
    ~ConsoleErrorReporter();
    void log_error(const int line, const std::string& message);
    void report(const int line, const std::string& where, const std::string& message);
};