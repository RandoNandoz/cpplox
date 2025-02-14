#pragma once

#include <string>
#include <vector>

#include "Token.hpp"
#include "TokenType.hpp"
#include "errorreporter/ErrorReportable.hpp"
#include "errorreporter/IErrorReporter.hpp"
class TokenScanner : public ErrorReportable {
   private:
    std::string source;
    std::vector<Token> tokens;
    std::vector<std::string> errors;

    size_t start;    // start of first lexeme
    size_t current;  // current idx of line
    size_t line;     // current line #

    bool at_end();
    void scan_token();
    char advance();
    void add_token(TokenType type);
    void add_token(TokenType type, LiteralValue value);
    bool match(char expected);
    char peek();

   public:
    TokenScanner(const std::string& source, IErrorReporter& error_reporter);
    std::vector<Token> scan_tokens();
};