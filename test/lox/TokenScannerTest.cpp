#include <doctest>
#include <lox/TokenScanner.hpp>
#include <vector>
#include "lox/Token.hpp"

TEST_CASE("Test scan_tokens") {
    TokenScanner ts{""};
    
    SUBCASE("Trivial subcase") {
        std::vector<Token> trival_case;
        CHECK(trival_case == ts.scan_tokens());
    }
}