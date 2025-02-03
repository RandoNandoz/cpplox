#include <doctest>
#include <lox/Token.hpp>

TEST_CASE("Test Token.to_string()") {
    Token t1(TokenType::FALSE, "false", false, 1);

    SUBCASE("Print string") {
        std::string expected = "TokenType: {FALSE}, lexeme: {false}, literal: {false}, line: {1};";
        CHECK(t1.to_string() == expected);
    }
}