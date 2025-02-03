#pragma once
// #include <cstddef>
#include <ostream>
#include <string>
// #include <variant>

#include "LiteralValue.hpp"

#include "TokenType.hpp"



class Token {
   private:
    TokenType type;
    std::string lexeme;
    LiteralValue literal;
    int line;

    std::string to_string() const;

   public:
    Token(TokenType type, const std::string& lexeme, LiteralValue literal, int line);

    friend std::ostream& operator<<(std::ostream& os, const Token& token);

    /**
        Equality comparison on Token is weak - all fields need to be equal,
        but if the literals have the same type, they have the same
     */
    bool operator==(const Token& other) const;
};