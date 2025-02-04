#include "TokenScanner.hpp"

#include <memory>
#include <string>
#include <vector>

#include "Token.hpp"
#include "TokenType.hpp"
#include "errorreporter/ConsoleErrorReporter.hpp"
#include "errorreporter/IErrorReporter.hpp"

using enum TokenType;

TokenScanner::TokenScanner(const std::string& source) : source(source), start(0), current(0), line(1) {
    this->error_reporter = std::make_unique<ConsoleErrorReporter>();
}

TokenScanner::TokenScanner(const std::string& source, const std::shared_ptr<IErrorReporter> error_reporter)
    : source(source), error_reporter(std::move(error_reporter)), start(0), current(0), line(1) {}

bool TokenScanner::at_end() { return current >= this->source.length(); }

void TokenScanner::scan_token() {
    switch (char c = advance(); c) {
        case '(': {
            add_token(LEFT_PAREN);
            break;
        }
        case ')': {
            add_token(RIGHT_PAREN);
            break;
        }
        case '{': {
            add_token(LEFT_BRACE);
            break;
        }
        case '}': {
            add_token(RIGHT_BRACE);
            break;
        }
        case ',': {
            add_token(COMMA);
            break;
        }
        case '.': {
            add_token(DOT);
            break;
        }
        case '-': {
            add_token(MINUS);
            break;
        }
        case '+': {
            add_token(PLUS);
            break;
        }
        case ';': {
            add_token(SEMICOLON);
            break;
        }
        case '*': {
            add_token(STAR);
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

void TokenScanner::add_token(TokenType type) { this->add_token(type, nullptr); }

void TokenScanner::add_token(TokenType type, LiteralValue value) {
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