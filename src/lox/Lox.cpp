#include "Lox.hpp"

#include <iostream>
#include <stdexcept>
#include <vector>

#include "Token.hpp"
#include "TokenScanner.hpp"
#include "errorreporter/ErrorReportable.hpp"
#include "errorreporter/IErrorReporter.hpp"
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
    this->hadError = false;  // reset error flag after running a line
}

void Lox::run(const std::string& source) {
    TokenScanner ts{source, this->error_reporter};
    std::vector<Token> result = ts.scan_tokens();
    for (Token t : result) {
        std::cout << t << "\n";
    }
}

Lox::Lox(IErrorReporter& error_reporter) : ErrorReportable(error_reporter), hadError(false){};
