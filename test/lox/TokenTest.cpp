#include <doctest>
#include <lox/Token.hpp>

TEST_CASE("Test Token.to_string()") {
    Token t1{TokenType::FALSE, "false", false, 1};
    Token t2{TokenType::AND, "and", nullptr, 30};
    Token t3{TokenType::NUMBER, "33.33", 33.33, 324};
    Token t4{TokenType::STRING, "Hello, world!\n", "Hello, world!\n", 324234};

    SUBCASE("bool") {
        std::string expected = "TokenType: {FALSE}, lexeme: {false}, literal: {false}, line: {1};";
        CHECK(t1.to_string() == expected);
    }

    SUBCASE("none") {
        std::string expected = "TokenType: {AND}, lexeme: {and}, literal: {nullptr}, line: {30};";
        CHECK(t2.to_string() == expected);
    }

    SUBCASE("double") {
        std::string expected = "TokenType: {NUMBER}, lexeme: {33.33}, literal: {33.330000}, line: {324};";
        CHECK(t3.to_string() == expected);
    }

    SUBCASE("string") {
        std::string expected = "TokenType: {STRING}, lexeme: {Hello, world!\n}, literal: {Hello, world!\n}, line: {324234};";
        CHECK(t4.to_string() == expected);
    }
}