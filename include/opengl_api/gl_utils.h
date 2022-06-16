#pragma once
#include <glm/glm.hpp>
#include <string>
#include <vector>

namespace gl_utils{
    std::string readfile(const std::string& file_path);
    std::vector<float> make_triangle(float center=0.0f, float height=0.5f, float base=0.5f);
    std::vector<float> random_colors(ssize_t n_colors = 1, float opacity = 1.0f);
}
