#pragma once
#include "renderer.h"

class TriangleRenderer : public Renderer{

public:

    TriangleRenderer();
    TriangleRenderer(const std::vector<float>& vertices);
    virtual ~TriangleRenderer();

    virtual void render() override;

private:

    const std::string FSHADER_PATH = "/data/Projets/opengl_boilerplate/src/shaders/simple.f.glsl";
    const std::string VSHADER_PATH = "/data/Projets/opengl_boilerplate/src/shaders/simple.v.glsl";
    const std::vector<uint> indices = {  
        0, 1, 2,
    };  

    Program _prog;
    VAO _vao;

};