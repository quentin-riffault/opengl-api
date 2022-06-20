#pragma once

#include "gl_api.h"

const std::string TEST_SHADER_PATH = "../src/shaders";

class Renderer {

public:
    virtual void render() = 0;
    virtual void set_wireframe(bool state){
        wireframe = state;
    }

protected:
    bool wireframe = false;

};