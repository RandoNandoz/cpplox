#include <doctest>
#include <lox/filereader/FileReader.hpp>
#include <string>

TEST_CASE("Test reading file into string") {
    FileReader fr("./test_data/test.txt");
    SUBCASE("Reading file with valid string") {
        const std::string expected = "Hello, world!";
        const std::string result = fr.read_as_string();
        CHECK(expected == result);
    }
}