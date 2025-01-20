#include "TokenScanner.hpp"
#include "Token.hpp"
#include "TokenType.hpp"

#include <string>
#include <vector>

using enum TokenType;

TokenScanner::TokenScanner(const std::string& source) : source(source), start(0), current(0), line(1) {}

bool TokenScanner::at_end() {
    return current >= this->source.length();
}



void TokenScanner::scan_token() {

}

std::vector<Token> TokenScanner::scan_tokens() {
    while (!this->at_end()) {
        // we are beginning of next lexeme
        this->start = this->current;
        scan_token();
    }

    this->tokens.emplace_back(Token(END_OF_FILE, "", std::any(), this->line));
    return this->tokens;
}