#pragma once

#include "shader.h"

class Program {

public:

    Program() = delete;
    Program(const std::string& fshader, const std::string& vshader);
    Program(std::shared_ptr<Shader> vshader, std::shared_ptr<Shader> fshader);

    virtual ~Program();

    void enable();
    void disable();

private:
    void link();
    GLuint _id = 0;
    std::shared_ptr<Shader> _vshader;
    std::shared_ptr<Shader> _fshader;
};
