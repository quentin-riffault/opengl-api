#include "opengl_api/programs/program.h"

#include <utility>

Program::Program(const std::string& fshader, const std::string& vshader){
    _id = glCreateProgram();

    _vshader = std::make_shared<Shader>(vshader, GL_VERTEX_SHADER);
    _fshader = std::make_shared<Shader>(fshader, GL_FRAGMENT_SHADER);

    glAttachShader(_id, _fshader->id());
    glAttachShader(_id, _vshader->id());

    link();

}

Program::Program(std::shared_ptr<Shader> fshader, std::shared_ptr<Shader> vshader){
    _id = glCreateProgram();

    _fshader = std::move(fshader);
    _vshader = std::move(vshader);

    glAttachShader(_id, _fshader->id());
    glAttachShader(_id, _vshader->id());

    link();

    fshader->~Shader();
    vshader->~Shader();

}

Program::~Program(){
    glDeleteProgram(_id);
}

void Program::link(){
    glLinkProgram(_id);
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

void Program::enable(){
   glUseProgram(_id);
}

void Program::disable(){
    glUseProgram(0);
}

