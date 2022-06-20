#include "gl_utils.h"
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <random>
#include <GL/glew.h>
#include <GL/gl.h>

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
    colors.reserve(n_colors);

    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for(int n = 0; n < n_colors; n++){
        colors.push_back((dis(gen)));
        colors.push_back((dis(gen)));
        colors.push_back((dis(gen)));
        colors.push_back(opacity);
    }

    return colors;
}

std::vector<float> gl_utils::random_colored_triangles(ssize_t n_triangles, float opacity){
    std::vector<float> vertices;
    const ssize_t components = n_triangles * (3*3 + 3*4);
    const ssize_t n_points = 3*n_triangles;
    vertices.reserve(components);
    

    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for(int n = 0; n < n_points; n++){
        vertices.push_back((dis(gen))); // x
        vertices.push_back((dis(gen))); // y
        vertices.push_back((dis(gen))); // z
        vertices.push_back((dis(gen))); // r
        vertices.push_back((dis(gen))); // g
        vertices.push_back((dis(gen))); // b
        vertices.push_back(opacity);    // alpha
    }

    std::cout << vertices.size() << std::endl;

    return vertices;
}

void gl_utils::check_errors()
{

#ifdef GL_NO_CHECK
    return;
#endif

    GLenum error = glGetError();
    if (error != GL_NO_ERROR)
    {
        std::string errmsg = "OpenGL error [" + std::to_string(error) + "] : " + (const char *)glewGetErrorString(error);
#ifdef GL_DEBUG
        throw std::runtime_error(errmsg);
#else
        std::cerr << errmsg << std::endl;
#endif
    }
}