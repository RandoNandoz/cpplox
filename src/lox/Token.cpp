#include "Token.hpp"

#include <magic_enum.hpp>
#include <ostream>
#include <stdexcept>
#include <string>
#include <variant>

#include "TokenType.hpp"

Token::Token(TokenType type, const std::string& lexeme, std::variant<bool, double, std::string, std::nullptr_t> literal, int line)
    : type(type), lexeme(lexeme), literal(literal), line(line) {};

std::ostream& operator<<(std::ostream& os, const Token& token) {
    os << token.to_string();
    return os;
}

std::string Token::to_string() const {
    std::string result;

    result += "TokenType: {";
    result += magic_enum::enum_name(this->type);
    result += "}";

    result += ", ";

    result += "lexeme: {";
    result += this->lexeme;
    result += "}";

    result += ", ";

    result += "literal: {";
    switch (size_t type_index = this->literal.index(); type_index) {
        case lv::bool_index: {
            result += std::get<bool>(this->literal) ? "true" : "false";
            break;
        }
        case lv::double_index: {
            result += std::to_string(std::get<double>(this->literal));
            break;
        }
        case lv::string_index: {
            result += std::get<std::string>(this->literal);
            break;
        }
        case lv::nullptr_index: {
            result +=  "nullptr";
            break;
        }
        default: {
            throw std::runtime_error("This should never be reached!");
            break;
        }
    }
    result += "}";

    result += ", ";

    result += "line: {";
    result += std::to_string(this->line);
    result += "};";

    return result;
}

bool Token::operator==(const Token& other) const {
    return this->lexeme == other.lexeme && this->line == other.line && this->literal == other.literal && this->type == other.type;
}