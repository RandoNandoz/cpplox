#include <any>
#include <ostream>
#include <string>

#include "TokenType.hpp"

class Token {
   private:
    TokenType type;
    std::string lexeme;
    std::any literal;
    int line;

   public:
    Token(TokenType type, const std::string& lexeme, std::any literal, int line);

    friend std::ostream& operator<<(std::ostream &os, const Token& token);
};