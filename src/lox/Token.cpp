#include "Token.hpp"

#include <magic_enum.hpp>
#include <ostream>
#include <stdexcept>
#include <string>

#include "TokenType.hpp"

Token::Token(TokenType type, const std::string& lexeme, std::variant<bool, double, std::string, nullptr_t> literal, int line)
    : type(type), lexeme(lexeme), literal(literal), line(line){};

std::ostream& operator<<(std::ostream& os, const Token& token) { os << token.to_string(); }

std::string Token::to_string() const {
    std::string result;

    result += "TokenType: {";
    result += magic_enum::enum_name(this->type);
    result += "}";

    result += ", ";

    result += "lexeme: {";
    result += lexeme;
    result += "}";

    result += ", ";

    result += "literal: {";
    switch (size_t type_index = this->literal.index()) {
        case lv::INT_INDEX: {
            break;
        }
        case lv::DOUBLE_INDEX: {
            break;
        }
        case lv::STRING_INDEX: {
            break;
        }
        case lv::NULLPTR_INDEX: {
            break;
        }
        default: {
            throw std::runtime_error("This should never be reached! ");
            break;
        }
    }
}

bool Token::operator==(const Token& other) const {
    return this->lexeme == other.lexeme && this->line == other.line && this->literal == other.literal && this->type == other.type;
}