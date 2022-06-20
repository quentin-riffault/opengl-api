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

TriangleColorRenderer::TriangleColorRenderer(const std::vector<float>& data) : Renderer(), _prog(FSHADER_PATH, VSHADER_PATH){
    if(data.size() < 3*7) throw std::invalid_argument("[TriangleColorRenderer] 9 points and 12 colors are necessary in order to build the triangle");

    _vao.bind();
    _vao.set_vbo<float>(0, data, [](){
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, (3+4)*sizeof(float), nullptr);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, (3+4)*sizeof(float), (void*)(3*sizeof(float)));
    });
    _vao.set_ebo(indices);
    _vao.unbind();

}


TriangleColorRenderer::TriangleColorRenderer(const std::vector<float>& vertices, const std::vector<float>& colors) : Renderer(), _prog(FSHADER_PATH, VSHADER_PATH), _vao(2){

    if(vertices.size() < 3*3) throw std::invalid_argument("[TriangleColorRenderer] 3*3 points are necessary in order to build the triangle");
    if(colors.size() < 3*4) throw std::invalid_argument("[TriangleColorRenderer] Color size must respect RGBA format (3*4 values)");

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
        glPolygonMode(GL_FRONT_AND_BACK, (wireframe) ? GL_LINE : GL_FILL );

        double time = glfwGetTime();
        double ct = cos(time);
        double st = sin(time);


        _prog.setUniform<glm::vec4>("color_modifier", glm::vec4(st, ct, 1.0f, ct*ct + st));

        _vao.draw();
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        _prog.disable();

}


