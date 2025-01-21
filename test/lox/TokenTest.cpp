#include <doctest>
#include <lox/Token.hpp>
#include <ostream>
#include <sstream>

TEST_CASE("Test Token's operator<<") {
    Token t(TokenType::FALSE, "false", false, 1);
    
    SUBCASE("Test print") {
        std::string expected = "FALSE false false 1";
        std::stringstream ss;
        ss << t;
        CHECK(ss.str() == expected);
    }
}