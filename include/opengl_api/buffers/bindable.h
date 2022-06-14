#pragma once
#include "gl_config.h"

class Bindable{

public:

    virtual void bind() = 0;
    virtual void unbind() = 0;
    virtual ~Bindable(){};

protected:
    uint _id;

};
