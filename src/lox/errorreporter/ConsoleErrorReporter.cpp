#include "ConsoleErrorReporter.hpp"

#include <iostream>

void ConsoleErrorReporter::log_error(const int line, const std::string& message) { report(line, "", message); }

void ConsoleErrorReporter::report(const int line, const std::string& where, const std::string& message) {
    std::cout << "[line " << line << "] Error" + where + ": " + message << "\n";
}

ConsoleErrorReporter::~ConsoleErrorReporter() = default;