#pragma once
#include "renderer.h"

class TriangleTexRenderer : public Renderer{

public:

    TriangleTexRenderer();
    TriangleTexRenderer(const std::vector<float>& data);
    virtual ~TriangleTexRenderer();

    virtual void render() override;

private:

    const std::string FSHADER_PATH = TEST_SHADER_PATH+"/simple_mix.f.glsl";
    const std::string VSHADER_PATH = TEST_SHADER_PATH+"/simple_mix.v.glsl";

    const std::string TEXTURE1_PATH = "../resources/wall.jpg"; 
    const std::string TEXTURE2_PATH = "../resources/awesomeface.png"; 

    const std::vector<uint> indices = {  
        0, 1, 2,
    };

    Texture _tex1;
    Texture _tex2;
    Program _prog;
    VAO _vao;

};