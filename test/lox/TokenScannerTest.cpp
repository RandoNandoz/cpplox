#include <doctest>
#include <lox/TokenScanner.hpp>
#include <vector>
#include "lox/Token.hpp"
#include "lox/TokenType.hpp"
#include "lox/errorreporter/ConsoleErrorReporter.hpp"

using enum TokenType;
ConsoleErrorReporter reporter{};

TEST_CASE("Test scan_tokens") {
    TokenScanner ts{"", reporter};
    
    SUBCASE("Trivial subcase") {
        std::vector<Token> trival_case;
        std::vector<Token> res = ts.scan_tokens();
        CHECK(res.size() == 1);
        CHECK(res[0].to_string().find("END_OF_FILE") != std::string::npos);
    }
}

TEST_CASE("Scan single-character lexeme") {
    std::vector<Token> expected = {
        Token{DOT,  ".", nullptr, 1},
        Token{END_OF_FILE, "", nullptr, 1}
    };
    TokenScanner ts{".", reporter};

    SUBCASE("verify") {
        CHECK(ts.scan_tokens() == expected);
    }
}

TEST_CASE("Scan less-than-or-equal-to") {
    std::vector<Token> expected = {
        Token{LESS_EQUAL, "", nullptr, 1},
        Token{END_OF_FILE, "", nullptr, 1}
    };
    TokenScanner ts{".", reporter};


    SUBCASE("verify") {
        CHECK(ts.scan_tokens() == expected);
    }
}
