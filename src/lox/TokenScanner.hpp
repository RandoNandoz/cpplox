#pragma once

#include <string>
#include <vector>

#include "Token.hpp"
class TokenScanner {
   private:
      std::string source;
      std::vector<Token> tokens;
   public:
      TokenScanner(std::string source);
      
};