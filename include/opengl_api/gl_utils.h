#pragma once
#include <glm/glm.hpp>
#include <string>
#include <vector>
#include <unordered_map>

template<typename T> using StringMap = std::unordered_map<std::string, T>;

namespace gl_utils{
    std::string readfile(const std::string& file_path);
    std::vector<float> make_triangle(float center=0.0f, float height=0.5f, float base=0.5f);
    std::vector<float> random_colors(ssize_t n_colors = 3, float opacity = 1.0f);
    std::vector<float> random_colored_triangles(ssize_t n_triangles=1, float opacity = 1.0f);
    void check_errors(const std::string& filename = "", const int& line = -1);
}