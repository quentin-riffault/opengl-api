#pragma once

#include "shader.h"
#include "buffers/bindable.h"

class Program : public Bindable{

public:

    Program() = delete;
    Program(const std::string& fshader, const std::string& vshader);
    Program(std::shared_ptr<Shader> fshader, std::shared_ptr<Shader> vshader);

    virtual ~Program();

    void bind() override;
    void unbind() override;

    void enable(){ bind(); }
    
    void disable(){ unbind(); }

   template<typename T> void setUniform(const char*, const T&){
       throw std::runtime_error("[Program] setUniform : Type not supported");
   }

   int getUniformLocation(const char* uniform_name);

private:
    void link();
    std::shared_ptr<Shader> _vshader;
    std::shared_ptr<Shader> _fshader;
};
