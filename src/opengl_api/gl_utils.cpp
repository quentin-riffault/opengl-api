#include "gl_utils.h"
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <random>

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

std::vector<float> gl_utils::make_triangle(float center, float height, float base){

    return {

        center - base/2, -height/2, 0.0f,
        center + base/2, -height/2, 0.0f,
        center, height/2, 0.0f,

    };
}

std::vector<float> gl_utils::random_colors(ssize_t n_colors, float opacity){
    std::vector<float> colors;
    colors.reserve(4*n_colors);

    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for(int n = 0; n < n_colors; n++){
        colors.push_back(dis(gen));
        colors.push_back(dis(gen));
        colors.push_back(dis(gen));
        colors.push_back(opacity);
    }

    return colors;
}