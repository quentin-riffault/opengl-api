#include "renderers/triangle_renderer.h"
#include "opengl_api/gl_api.h"


TriangleRenderer::TriangleRenderer() : Renderer(), _prog(FSHADER_PATH, VSHADER_PATH){

    const std::vector<float> vertices = {
        0.5f,  0.5f, 0.0f,  // top right
        0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left 
    };

    const std::vector<uint> indices = {  // note that we start from 0!
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
    };  

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


