#include "TokenScanner.hpp"

#include <string>
#include <vector>

#include "Token.hpp"
#include "TokenType.hpp"
#include "errorreporter/ErrorReportable.hpp"
#include "errorreporter/IErrorReporter.hpp"

using enum TokenType;

TokenScanner::TokenScanner(const std::string& source, IErrorReporter& error_reporter)
    : ErrorReportable(error_reporter), source(source), start(0), current(0), line(1) {}

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
        case '!': {
            add_token(match('=') ? BANG_EQUAL : BANG);
            break;
        }
        case '=': {
            add_token(match('=') ? EQUAL_EQUAL : EQUAL);
        }
        case '<': {
            add_token(match('<') ? LESS_EQUAL : LESS);
            break;
        }
        case '>': {
            add_token(match('=') ? GREATER_EQUAL : GREATER);
            break;
        }
        default: {
            error_reporter.log_error(line, "Unexpected character");
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

bool TokenScanner::match(char expected) {
    if (at_end()) {
        return false;
    }

    if (source[current] != expected) {
        return false;
    }

    current++;
    return true;
}

char TokenScanner::peek() {
    if (at_end()) {
        return '\0';
    }

    return source[current];
}