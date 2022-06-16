#pragma once

#include "gl_api.h"

class Renderer {

public:
    virtual void render() = 0;
    virtual void set_wireframe(bool state){
        wireframe = state;
    }

protected:
    bool wireframe = false;

};