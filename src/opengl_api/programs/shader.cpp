#include "programs/shader.h"


Shader::Shader(const std::string &shader_source_path, const GLenum& shader_type) : _id(0), _shaderType(shader_type) {
    std::string shader_source;

    try{
        std::cout << "======== Shader source beg ========" << std::endl;
        shader_source = gl_utils::readfile(shader_source_path);
        std::cout << "======== Shader source end ========" << std::endl;
    }catch(const std::runtime_error& e){
       std::cerr << e.what() << std::endl;
       throw std::runtime_error("Could not compile shader - Source not found");
    }

    try{
        compileSources(shader_source.c_str());
    }catch(const std::runtime_error& e){
        std::cerr << e.what() << std::endl;
        throw std::runtime_error("Shader compilation failed");
    }
}

void Shader::compileSources(const char* shader_source){
    GLint success = GL_FALSE;
    char infolog[512] = "";

    _id = glCreateShader(_shaderType);
    glShaderSource(_id, 1, &shader_source, nullptr);
    glCompileShader(_id);

    glGetShaderiv(_id, GL_COMPILE_STATUS, &success);

    if(success){
        std::cout << "Shader compilation success" << std::endl;
        return;
    }

    glGetShaderInfoLog(_id, 512, nullptr, infolog);
    std::string ex = std::string("Shader compilation error: ") + infolog;
    throw std::runtime_error(ex);

}

Shader::~Shader(){
    glDeleteShader(_id);
    gl_utils::check_errors();
}