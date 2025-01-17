#include "FileReader.hpp"

#include <fstream>
#include <sstream>

FileReader::FileReader(const std::string& path) {
    this->file_path = std::move(path);
}

std::string FileReader::readAsString() {
    std::ifstream in;
    in.open(this->file_path);

    std::stringstream ss;
    ss << in.rdbuf();

    std::string str = ss.str();
    return str;
}