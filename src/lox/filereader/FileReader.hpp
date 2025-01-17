#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

class FileReader {
   private:
    std::string file_path;

   public:
    FileReader(const std::string& path);

    std::string readAsString();
};