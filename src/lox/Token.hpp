#pragma once
#include <any>
#include <cstddef>
#include <ostream>
#include <string>
#include <variant>

#include "TokenType.hpp"

class Token {
   private:
    TokenType type;
    std::string lexeme;
    std::variant<bool, double, std::string, nullptr_t> literal;
    int line;

   public:
    Token(TokenType type, const std::string& lexeme, std::variant<bool, double, std::string, nullptr_t> literal, int line);

    friend std::ostream& operator<<(std::ostream& os, const Token& token);

    /**
        Equality comparison on Token is weak - all fields need to be equal,
        but if the literals have the same type, they have the same 
     */
    bool operator==(const Token& other) const;
};