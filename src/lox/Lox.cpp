#include "Lox.hpp"

#include <iostream>
#include <stdexcept>
#include <vector>

#include "Token.hpp"
#include "TokenScanner.hpp"
#include "filereader/FileReader.hpp"

void Lox::run_file(const std::string& path) {
    FileReader reader(path);
    this->run(reader.read_as_string());
    if (this->hadError) {
        throw std::invalid_argument("File had errors!");
    }
}

void Lox::run_REPL() {
    std::string user_input;
    while (std::cin >> user_input) {
        this->run(user_input);
    }
    this->hadError = false; // reset error flag after running a line
}

void Lox::run(const std::string& source) {
    TokenScanner ts{source};
    std::vector<Token> result = ts.scan_tokens();
    for (Token t : result) {
        std::cout << t << "\n";
    }
}

Lox::Lox() { this->hadError = false; }

void Lox::log_error(const int line, const std::string& message) { report(line, "", message); }

void Lox::report(const int line, const std::string& where, const std::string& message) {
    std::cout << "[line " << line << "] Error" + where + ": " + message << "\n";
}