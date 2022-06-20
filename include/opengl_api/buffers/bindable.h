#pragma once
#include "gl_config.h"

class Bindable{

public:

    virtual void bind() = 0;
    virtual void unbind() = 0;
    virtual ~Bindable(){};
    void require_bound(const std::string& module = "", const std::string& operation=""){
        if(! _enabled) {
            const std::string err = "[" + module +"] Element required to be bound to apply operation " + operation; 
            throw std::runtime_error(err);
        }
    };

protected:
    uint _id;
    bool _enabled;
};
