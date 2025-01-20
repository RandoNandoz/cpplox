#pragma once

#include <string>
#include <vector>

#include "Token.hpp"
class TokenScanner {
   private:
    std::string source;
    std::vector<Token> tokens;
    int start;    // start of first lexeme
    int current;  // current idx of line
    int line;     // current line #

    bool at_end();
    void scan_token();
    char advance();

   public:
    TokenScanner(const std::string& source);
    std::vector<Token> scan_tokens();
};