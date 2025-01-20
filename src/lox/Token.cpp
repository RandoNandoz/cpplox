#include "Token.hpp"

#include <any>
#include <magic_enum.hpp>
#include <ostream>
#include <string>

#include "TokenType.hpp"

Token::Token(TokenType type, const std::string& lexeme, std::variant<bool, double, std::string, nullptr_t> literal, int line)
    : type(type), lexeme(lexeme), literal(literal), line(line){};

std::ostream& operator<<(std::ostream& os, const Token& token) {
    os << magic_enum::enum_name(token.type) << " " << token.lexeme << " " << token.literal.;
    return os;
}

bool Token::operator==(const Token& other) const {
    return this->lexeme == other.lexeme && this->line == other.line && this->literal == other.literal && this->type == other.type
}