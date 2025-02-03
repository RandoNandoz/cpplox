#include "TokenScanner.hpp"

#include <string>
#include <string_view>
#include <vector>

#include "Token.hpp"
#include "TokenType.hpp"

using enum TokenType;

TokenScanner::TokenScanner(const std::string& source) : source(source), start(0), current(0), line(1) {}

bool TokenScanner::at_end() { return current >= this->source.length(); }

void TokenScanner::scan_token() {
    switch (char c = advance()) {
        case '(': {
            addToken(LEFT_PAREN);
            break;
        }
        case ')': {
            addToken(RIGHT_PAREN);
            break;
        }
        case '{': {
            addToken(LEFT_BRACE);
            break;
        }
        case '}': {
            addToken(RIGHT_BRACE);
            break;
        }
        case ',': {
            addToken(COMMA);
            break;
        }
        case '.': {
            addToken(DOT);
            break;
        }
        case '-': {
            addToken(MINUS);
            break;
        }
        case '+': {
            addToken(PLUS);
            break;
        }
        case ';': {
            addToken(SEMICOLON);
            break;
        }
        case '*': {
            addToken(STAR);
            break;
        }
        default: {
            // idk what to do, invalid char
            break;
        }
    }
}

char TokenScanner::advance() {
    char result = this->source[this->current];
    current++;
    return result;
}

void TokenScanner::addToken(TokenType type) {
    this->addToken(type, nullptr);
}

void TokenScanner::addToken(TokenType type, LiteralValue value) {
    std::string lexeme = this->source.substr(this->start, this->current);
    this->tokens.emplace_back(Token(type, lexeme, value, this->line));
}

std::vector<Token> TokenScanner::scan_tokens() {
    while (!this->at_end()) {
        // we are beginning of next lexeme
        this->start = this->current;
        scan_token();
    }

    this->tokens.emplace_back(Token(END_OF_FILE, "", nullptr, this->line));
    return this->tokens;
}