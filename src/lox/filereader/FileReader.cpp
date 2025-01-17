#include "FileReader.hpp"

FileReader::FileReader(const std::string& path) {
    this->file_path = std::move(path);
}

std::string FileReader::readAsString() {
        std::ifstream path_stream(this->file_path);
        std::stringstream buf;
        buf << path_stream.rdbuf();
        return buf.str();
}