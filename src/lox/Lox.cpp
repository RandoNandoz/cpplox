#include "Lox.hpp"

#include <iostream>
#include <stdexcept>

#include "filereader/FileReader.hpp"

void Lox::runFile(const std::string& path) {
    FileReader reader(path);
    this->run(reader.readAsString());
    if (this->hadError) {
        throw std::invalid_argument("File had errors!");
    }
}

void Lox::runREPL() {
    std::string user_input;
    while (std::cin >> user_input) {
        this->run(user_input);
    }
    this->hadError = false; // reset error flag after running a line
}

void Lox::run(const std::string& source) {}

Lox::Lox() { this->hadError = false; }

void Lox::logError(const int line, const std::string& message) { report(line, "", message); }

void Lox::report(const int line, const std::string& where, const std::string& message) {
    std::cout << "[line " << line << "] Error" + where + ": " + message << "\n";
}