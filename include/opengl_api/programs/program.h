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

   template<typename T> void setUniform(const char*, const T&){
       throw std::runtime_error("[Program] setUniform : Type not supported");
   }

   int getUniformLocation(const char* uniform_name);


   inline void needEnabled(){
       if(!_enabled) throw std::runtime_error("[Program] Needs to be enabled");
   }

private:
    void link();
    GLuint _id = 0;
    bool _enabled = false;
    std::shared_ptr<Shader> _vshader;
    std::shared_ptr<Shader> _fshader;
};
