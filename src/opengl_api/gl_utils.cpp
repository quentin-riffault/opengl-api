#include "gl_utils.h"
#include <iostream>
#include <fstream>

std::string gl_utils::readfile(const std::string& file_path) {

    std::ifstream file(file_path);

    if( ! file.is_open() ) {
        throw std::runtime_error(std::string("File not found or unable to view it (file ") + file_path + ")");
    }

    std::string contents;
    std::string line;

    while(std::getline(file, line)){
        contents += line + "\n";
        std::cout << line << std::endl;
    }

    file.close();
    return contents;
}