#pragma once
#include "gl_config.h"

class Shader {
public:
    Shader(const std::string &shader_source_path, const GLenum& shader_type = GL_VERTEX_SHADER);
    ~Shader();
    GLuint id() const { return _id; };

private:
    void compileSources(const char* shader_source);

private:
    GLuint _id;
    GLenum _shaderType;

};