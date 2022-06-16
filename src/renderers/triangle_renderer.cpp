#include "renderers/triangle_renderer.h"
#include "opengl_api/gl_api.h"


TriangleRenderer::TriangleRenderer() : Renderer(), _prog(FSHADER_PATH, VSHADER_PATH){

    const std::vector<float> vertices = {
        0.0f,  0.5f, 0.0f,  
        0.5f, -0.5f, 0.0f,  
        -0.5f, -0.5f, 0.0f,  
    };


    _vao.bind();
    _vao.set_vbo<float>(0, vertices);
    _vao.set_ebo(indices);
    _vao.unbind();

}

TriangleRenderer::TriangleRenderer(const std::vector<float>& vertices) : Renderer(), _prog(FSHADER_PATH, VSHADER_PATH){

    if(vertices.size() < 9) throw std::invalid_argument("9 points are necessary in order to build the triangle");

    _vao.bind();
    _vao.set_vbo<float>(0, vertices);
    _vao.set_ebo(indices);
    _vao.unbind();

}

TriangleRenderer::~TriangleRenderer(){
}   

void TriangleRenderer::render(){
        _prog.enable();
        _vao.draw();
        _prog.disable();

}


