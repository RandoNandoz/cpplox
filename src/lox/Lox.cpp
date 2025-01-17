#include "Lox.hpp"
#include "filereader/FileReader.hpp"

void Lox::runFile(const std::string& path) {
    FileReader reader(path);
    this->run(reader.readAsString());
}

void Lox::runREPL() {
    
}

void Lox::run(const std::string& source) {

}
