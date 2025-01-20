#pragma once
#include <string>


class FileReader {
   private:
    std::string file_path;

   public:
    FileReader(const std::string& path);

    std::string read_as_string();
};