#pragma once

#include <string>
#include <vector>

#include "Token.hpp"
#include "TokenType.hpp"
class TokenScanner {
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
    void addToken(TokenType type);
    void addToken(TokenType type, LiteralValue value);

   public:
    explicit TokenScanner(const std::string& source);
    std::vector<std::string> report_errors();
    std::vector<Token> scan_tokens();
};