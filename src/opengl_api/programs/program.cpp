#include "programs/program.h"


Program::Program(const std::string& fshader, const std::string& vshader){
    _id = glCreateProgram();
    gl_utils::check_errors(__FILE__, __LINE__);

    _vshader = std::make_shared<Shader>(vshader, GL_VERTEX_SHADER);
    _fshader = std::make_shared<Shader>(fshader, GL_FRAGMENT_SHADER);

    glAttachShader(_id, _fshader->id());
    gl_utils::check_errors(__FILE__, __LINE__);
    glAttachShader(_id, _vshader->id());
    gl_utils::check_errors(__FILE__, __LINE__);

    link();

}

Program::Program(std::shared_ptr<Shader> fshader, std::shared_ptr<Shader> vshader){
    _id = glCreateProgram();
    gl_utils::check_errors(__FILE__, __LINE__);

    _fshader = std::move(fshader);
    _vshader = std::move(vshader);

    glAttachShader(_id, _fshader->id());
    gl_utils::check_errors(__FILE__, __LINE__);
    glAttachShader(_id, _vshader->id());
    gl_utils::check_errors(__FILE__, __LINE__);

    link();

    fshader->~Shader();
    vshader->~Shader();

}

Program::~Program(){
    glDeleteProgram(_id);
    gl_utils::check_errors(__FILE__, __LINE__);
}

void Program::link(){
    glLinkProgram(_id);
    gl_utils::check_errors(__FILE__, __LINE__);
    GLint success = GL_FALSE;
    char infolog[512] = "";

    glGetProgramiv(_id, GL_LINK_STATUS, &success);

    if(success == GL_TRUE) {

        _fshader.reset();
        _vshader.reset();

        return;
    }

    glGetProgramInfoLog(_id, 512, nullptr, infolog);

    throw std::runtime_error(std::string("Error while linking a program: ") + infolog);

}

void Program::bind(){
   glUseProgram(_id);
    gl_utils::check_errors(__FILE__, __LINE__);
    glGetIntegerv(GL_CURRENT_PROGRAM, &_enabled);
}

void Program::unbind(){
    glUseProgram(0);
    gl_utils::check_errors(__FILE__, __LINE__);
    glGetIntegerv(GL_CURRENT_PROGRAM, &_enabled);
}

int Program::getUniformLocation(const char* uniform_name){
    
    require_bound("Program", "getUniformLocation");
    int location = glGetUniformLocation(_id, uniform_name);
    if(location == -1) throw std::runtime_error(std::string("[getUniformLocation] Error finding ") + uniform_name);

    return location;
}

/*4D Vectors*/

template<> void Program::setUniform<glm::vec4>(const char* uniform_name, const glm::vec4& uniform_value){
    int location = getUniformLocation(uniform_name);
    glUniform4f(location, uniform_value.x, uniform_value.y, uniform_value.z ,uniform_value.w);
    gl_utils::check_errors(__FILE__, __LINE__);
}

template<> void Program::setUniform<glm::dvec4>(const char* uniform_name, const glm::dvec4& uniform_value){
    int location = getUniformLocation(uniform_name);
    glUniform4d(location, uniform_value.x, uniform_value.y, uniform_value.z ,uniform_value.w);
    gl_utils::check_errors(__FILE__, __LINE__);
}

template<> void Program::setUniform<glm::ivec4>(const char* uniform_name, const glm::ivec4& uniform_value){
    int location = getUniformLocation(uniform_name);
    glUniform4i(location, uniform_value.x, uniform_value.y, uniform_value.z ,uniform_value.w);
    gl_utils::check_errors(__FILE__, __LINE__);
}


template<> void Program::setUniform<glm::uvec4>(const char* uniform_name, const glm::uvec4& uniform_value){
    int location = getUniformLocation(uniform_name);
    glUniform4ui(location, uniform_value.x, uniform_value.y, uniform_value.z ,uniform_value.w);
    gl_utils::check_errors(__FILE__, __LINE__);
}

/*3D Vectors*/

template<> void Program::setUniform<glm::vec3>(const char* uniform_name, const glm::vec3& uniform_value){
    int location = getUniformLocation(uniform_name);
    glUniform3f(location, uniform_value.x, uniform_value.y, uniform_value.z);
    gl_utils::check_errors(__FILE__, __LINE__);
}

template<> void Program::setUniform<glm::dvec3>(const char* uniform_name, const glm::dvec3& uniform_value){
    int location = getUniformLocation(uniform_name);
    glUniform3d(location, uniform_value.x, uniform_value.y, uniform_value.z);
    gl_utils::check_errors(__FILE__, __LINE__);
}

template<> void Program::setUniform<glm::ivec3>(const char* uniform_name, const glm::ivec3& uniform_value){
    int location = getUniformLocation(uniform_name);
    glUniform3i(location, uniform_value.x, uniform_value.y, uniform_value.z);
    gl_utils::check_errors(__FILE__, __LINE__);
}

template<> void Program::setUniform<glm::uvec3>(const char* uniform_name, const glm::uvec3& uniform_value){
    int location = getUniformLocation(uniform_name);
    glUniform3ui(location, uniform_value.x, uniform_value.y, uniform_value.z);
    gl_utils::check_errors(__FILE__, __LINE__);
}

/*2D Vectors*/

template<> void Program::setUniform<glm::vec2>(const char* uniform_name, const glm::vec2& uniform_value){
    int location = getUniformLocation(uniform_name);
    glUniform2f(location, uniform_value.x, uniform_value.y);
    gl_utils::check_errors(__FILE__, __LINE__);
}

template<> void Program::setUniform<glm::dvec2>(const char* uniform_name, const glm::dvec2& uniform_value){
    int location = getUniformLocation(uniform_name);
    glUniform2d(location, uniform_value.x, uniform_value.y);
    gl_utils::check_errors(__FILE__, __LINE__);
}

template<> void Program::setUniform<glm::ivec2>(const char* uniform_name, const glm::ivec2& uniform_value){
    int location = getUniformLocation(uniform_name);
    glUniform2i(location, uniform_value.x, uniform_value.y);
    gl_utils::check_errors(__FILE__, __LINE__);
}

template<> void Program::setUniform<glm::uvec2>(const char* uniform_name, const glm::uvec2& uniform_value){
    int location = getUniformLocation(uniform_name);
    glUniform2ui(location, uniform_value.x, uniform_value.y);
    gl_utils::check_errors(__FILE__, __LINE__);
}

/*Scalars*/

template<> void Program::setUniform<glm::vec1>(const char* uniform_name, const glm::vec1& uniform_value){
    int location = getUniformLocation(uniform_name);
    glUniform1f(location, uniform_value.x);
    gl_utils::check_errors(__FILE__, __LINE__);
}

template<> void Program::setUniform<glm::dvec1>(const char* uniform_name, const glm::dvec1& uniform_value){
    int location = getUniformLocation(uniform_name);
    glUniform1d(location, uniform_value.x);
    gl_utils::check_errors(__FILE__, __LINE__);
}

template<> void Program::setUniform<glm::ivec1>(const char* uniform_name, const glm::ivec1& uniform_value){
    int location = getUniformLocation(uniform_name);
    glUniform1i(location, uniform_value.x);
    gl_utils::check_errors(__FILE__, __LINE__);
}

template<> void Program::setUniform<glm::uvec1>(const char* uniform_name, const glm::uvec1& uniform_value){
    int location = getUniformLocation(uniform_name);
    glUniform1ui(location, uniform_value.x);
    gl_utils::check_errors(__FILE__, __LINE__);
}

template<> void Program::setUniform<int>(const char* uniform_name, const int& uniform_value){
    int location = getUniformLocation(uniform_name);
    glUniform1i(location, uniform_value);
    gl_utils::check_errors(__FILE__, __LINE__);
}

/*Square matrices*/

template<> void Program::setUniform<glm::mat4>(const char* uniform_name, const glm::mat4& uniform_value){
    int location = getUniformLocation(uniform_name);
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(uniform_value));
    gl_utils::check_errors(__FILE__, __LINE__);
}


template<> void Program::setUniform<glm::mat3>(const char* uniform_name, const glm::mat3& uniform_value){
    int location = getUniformLocation(uniform_name);
    glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(uniform_value));
    gl_utils::check_errors(__FILE__, __LINE__);
}

template<> void Program::setUniform<glm::mat2>(const char* uniform_name, const glm::mat2& uniform_value){
    int location = getUniformLocation(uniform_name);
    glUniformMatrix2fv(location, 1, GL_FALSE, glm::value_ptr(uniform_value));
    gl_utils::check_errors(__FILE__, __LINE__);
}