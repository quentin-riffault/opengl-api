#include "renderers/companion_cube_renderer.h"

CompanionCubeRenderer::CompanionCubeRenderer(){
	
	_vao.bind();
	_vao.set_vbo(0, vertices, [](){
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, (3+2)*sizeof(float), nullptr);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, (3+2)*sizeof(float), (void*) (3*sizeof(float)));
		glEnableVertexAttribArray(1);
	});
	
	_vao.set_ebo(indices);
	_vao.unbind();

	scale(glm::vec3(0.5f));
	translate(glm::vec3(-0.5f));

}

void CompanionCubeRenderer::setup_after_registration(){
	_prog = _pbank->getProgramInstance("companion");
	_tex = _tbank->getTextureInstance("cc.jpg");
	
	_prog->enable();
	_prog->setUniform("companionTexture", 0);
	_prog->disable();

}

CompanionCubeRenderer::~CompanionCubeRenderer(){

}

void CompanionCubeRenderer::render(){
	_tex->setTexunit(0);
	
	_prog->enable();
	_vao.bind();

    _prog->setUniform("pvm", pvm());
	
	_vao.draw();

	_vao.unbind();
	_prog->disable();
}