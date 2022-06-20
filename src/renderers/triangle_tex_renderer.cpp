#include "renderers/triangle_tex_renderer.h"
#include "opengl_api/gl_api.h"


TriangleTexRenderer::TriangleTexRenderer(const std::vector<float>& data) : Renderer(), _prog(FSHADER_PATH, VSHADER_PATH), _tex1(TEXTURE1_PATH), _tex2(TEXTURE2_PATH, GL_RGBA, GL_TEXTURE_2D){
    if(data.size() < 3*9) throw std::invalid_argument("[TriangleColorRenderer] 9 points, 12 colors and 6 texture coordinates are necessary in order to build the triangle");


    _vao.bind();
    _vao.set_vbo<float>(0, data, [](){
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, (3+4+2)*sizeof(float), nullptr);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, (3+4+2)*sizeof(float), (void*)(3*sizeof(float)));
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, (3+4+2)*sizeof(float), (void*)((3+4)*sizeof(float)));
        glEnableVertexAttribArray(2);
    });
    
    _vao.set_ebo(indices);
    _vao.unbind();
    
    _prog.bind();

    _prog.setUniform("tex1", 0);
    _prog.setUniform("tex2", 1);

    _prog.unbind();

}

TriangleTexRenderer::~TriangleTexRenderer(){

}   

void TriangleTexRenderer::render(){
        _tex1.setTexunit(0);
        _tex2.setTexunit(1);
        
        _prog.enable();
        glPolygonMode(GL_FRONT_AND_BACK, (wireframe) ? GL_LINE : GL_FILL );

        //double time = glfwGetTime();
        double r = 1.0f;
        double g = 1.0f;
        double b = 1.0f;
        double a = 1.0f;


        _prog.setUniform<glm::vec4>("color_modifier", glm::vec4(r, g, b, a));
        _vao.draw();
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        _prog.disable();

}


