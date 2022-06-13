#pragma once
#include "gl_config.h"

class Buffer{

public:

    virtual void bind() = 0;
    virtual void unbind() = 0;
    virtual ~Buffer(){};

};
