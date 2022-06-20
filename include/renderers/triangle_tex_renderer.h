#pragma once
#include "renderer.h"

class TriangleTexRenderer : public Renderer{

public:

    TriangleTexRenderer();
    TriangleTexRenderer(const std::vector<float>& data);
    virtual ~TriangleTexRenderer();

    virtual void render() override;

private:

    const std::string FSHADER_PATH = TEST_SHADER_PATH+"/simple_tex.f.glsl";
    const std::string VSHADER_PATH = TEST_SHADER_PATH+"/simple_tex.v.glsl";
    const std::string TEXTURE_PATH = "/data/Projets/opengl_boilerplate/resources/wall.jpg"; 
    const std::vector<uint> indices = {  
        0, 1, 2,
    };

    Program _prog;
    Texture _tex;
    VAO _vao;



};