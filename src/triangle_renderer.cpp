#include "triangle_renderer.h"
#include "opengl_api/opengl_api.h"
#include <iostream>


TriangleRenderer::TriangleRenderer() : Renderer(), _prog(FSHADER_PATH, VSHADER_PATH){

}

TriangleRenderer::~TriangleRenderer(){
}   

void TriangleRenderer::render(){

    _triangleVBO.bind();
    _triangleVBO.setData(sizeof(vertices), vertices, GL_STATIC_DRAW);
    _triangleVBO.unbind();

}


