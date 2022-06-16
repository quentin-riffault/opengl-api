#pragma once
#include "renderer.h"

class TriangleColorRenderer : public Renderer{

public:

    TriangleColorRenderer();
    virtual ~TriangleColorRenderer();

    virtual void render() override;

private:

    const std::string FSHADER_PATH = "/data/Projets/opengl_boilerplate/src/shaders/simple_color.f.glsl";
    const std::string VSHADER_PATH = "/data/Projets/opengl_boilerplate/src/shaders/simple_color.v.glsl";

    Program _prog;
    VAO _vao;

};