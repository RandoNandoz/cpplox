#include <any>
#include <ostream>
#include <string>
#include "TokenType.hpp"
#include "Token.hpp"

Token::Token(TokenType type, const std::string& lexeme, std::any literal, int line) : type(type), lexeme(lexeme), literal(literal), line(line) {};

std::ostream& operator<<(std::ostream &os, const Token& token) {
    return os;
}