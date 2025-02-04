#pragma once

#include <memory>
#include <string>
#include <vector>

#include "errorreporter/IErrorReporter.hpp"

#include "Token.hpp"
#include "TokenType.hpp"
class TokenScanner {
   private:
    std::string source;
    std::vector<Token> tokens;
    std::vector<std::string> errors;
    std::shared_ptr<IErrorReporter> error_reporter;
    
    size_t start;    // start of first lexeme
    size_t current;  // current idx of line
    size_t line;     // current line #

    bool at_end();
    void scan_token();
    char advance();
    void add_token(TokenType type);
    void add_token(TokenType type, LiteralValue value);

   public:
    explicit TokenScanner(const std::string& source);
    TokenScanner(const std::string& source, const std::shared_ptr<IErrorReporter> error_reporter);
    std::vector<Token> scan_tokens();
};