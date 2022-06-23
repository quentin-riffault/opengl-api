#pragma once
#include "renderer.h"

class TriangleRenderer : public Renderer{

public:

    TriangleRenderer();
    TriangleRenderer(const std::vector<float>& vertices);
    virtual ~TriangleRenderer();

    virtual void render() override;

private:

    const std::string FSHADER_PATH = TEST_SHADER_PATH+"/simple.f.glsl";
    const std::string VSHADER_PATH = TEST_SHADER_PATH+"/simple.v.glsl";
    const std::vector<uint> indices = {  
        0, 1, 2,
    };  

    Program _prog;
    VAO _vao;
};