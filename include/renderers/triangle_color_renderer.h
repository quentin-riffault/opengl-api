#pragma once
#include "renderer.h"

class TriangleColorRenderer : public Renderer{

public:

    TriangleColorRenderer();
    TriangleColorRenderer(const std::vector<float>& data);
    TriangleColorRenderer(const std::vector<float>& vertices, const std::vector<float>& colors);
    virtual ~TriangleColorRenderer();

    virtual void render() override;

private:

    const std::string FSHADER_PATH = "/data/Projets/opengl_boilerplate/src/shaders/simple_color.f.glsl";
    const std::string VSHADER_PATH = "/data/Projets/opengl_boilerplate/src/shaders/simple_color.v.glsl";
    const std::vector<uint> indices = {  
        0, 1, 2,
    };  

    Program _prog;
    VAO _vao;

};