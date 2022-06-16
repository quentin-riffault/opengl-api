#include "renderers/triangle_color_renderer.h"
#include "opengl_api/gl_api.h"


TriangleColorRenderer::TriangleColorRenderer() : Renderer(), _prog(FSHADER_PATH, VSHADER_PATH), _vao(2){

    const std::vector<float> vertices = {
        0.0f,  0.5f, 0.0f,  
        0.5f, -0.5f, 0.0f,  
        -0.5f, -0.5f, 0.0f,  
    };

    const std::vector<float> colors = gl_utils::random_colors(3);

    _vao.bind();
    _vao.set_vbo<float>(0, vertices);
    _vao.set_vbo<float>(1, colors);
    _vao.set_ebo(indices);
    _vao.unbind();

}

TriangleColorRenderer::TriangleColorRenderer(const std::vector<float>& vertices, const std::vector<float>& colors) : Renderer(), _prog(FSHADER_PATH, VSHADER_PATH), _vao(2){

    if(vertices.size() < 9) throw std::invalid_argument("[TriangleColorRenderer] 9 points are necessary in order to build the triangle");
    if(colors.size() < 9*4) throw std::invalid_argument("[TriangleColorRenderer] Color size must respect RGBA format (9*4 values)");

    _vao.bind();
    _vao.set_vbo<float>(0, vertices);
    _vao.set_vbo<float>(1, colors);
    _vao.set_ebo(indices);
    _vao.unbind();

}

TriangleColorRenderer::~TriangleColorRenderer(){

}   

void TriangleColorRenderer::render(){
        _prog.enable();
        _vao.draw();
        _prog.disable();

}


