#include "renderers/companion_cube_renderer.h"

CompanionCubeRenderer::CompanionCubeRenderer() : _tex("../resources/cc.jpg"), _prog (TEST_SHADER_PATH+"/companion.f.glsl", TEST_SHADER_PATH+"/companion.v.glsl") {
	_vao.bind();
	_vao.set_vbo(0, vertices, [](){
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, (3+2)*sizeof(float), nullptr);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, (3+2)*sizeof(float), (void*) (3*sizeof(float)));
		glEnableVertexAttribArray(1);
	});
	
	_vao.set_ebo(indices);
	_vao.unbind();

	_prog.bind();
	_prog.setUniform("companionTexture", 0);
	_prog.unbind();
}

CompanionCubeRenderer::~CompanionCubeRenderer(){

}

void CompanionCubeRenderer::render(){
	_tex.setTexunit(0);
	
	_prog.enable();
	_vao.bind();

    _prog.setUniform("pvm", pvm());
	
    glPolygonMode(GL_FRONT_AND_BACK, (wireframe) ? GL_LINE : GL_FILL );
	_vao.draw();

	_vao.unbind();
	_prog.disable();
}