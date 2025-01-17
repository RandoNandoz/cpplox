#include <doctest>
#include <lox/filereader/FileReader.hpp>
#include <string>

TEST_CASE("Test reading file into string") {
    FileReader fr("./test.txt");
    SUBCASE("Reading file with valid string") {
        const std::string expected =
            "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed convallis libero et iaculis maximus. Suspendisse vehicula ornare mauris, ac faucibus "
            "leo tincidunt vel. Donec fringilla eleifend neque, vitae lobortis ante molestie quis. Nulla suscipit egestas pretium. Proin fringilla erat orci, "
            "eu facilisis est consequat at. Donec velit lectus, placerat sed auctor at, tempus cursus velit. Nulla facilisi.";
        
        const std::string result = fr.readAsString();
        CHECK(expected == result);
    }
}