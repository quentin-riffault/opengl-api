#pragma once
#include "gl_config.h"

class Bindable{

public:

    virtual void bind() = 0;
    virtual void unbind() = 0;
    virtual ~Bindable(){};
    void require_bound(const std::string& module = "", const std::string& operation=""){
        if(_enabled != static_cast<GLint>(_id)) {
            std::cerr << module << " currently bound : " << _enabled << ", " << module << " id = " << _id << std::endl;
            const std::string err = "[" + module +"] Element required to be bound to apply operation " + operation; 
            throw std::runtime_error(err);
        }
    };

protected:
    GLuint _id;
    GLint _enabled;
};
