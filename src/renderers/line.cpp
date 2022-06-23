#include "renderers/line.h"

Line::Line(const std::vector<float>& data) : _prog(FSHADER_PATH, VSHADER_PATH){

	_vao.bind();
	_vao.set_vbo(0, data, [](){
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, (3+4)*sizeof(float), nullptr);
		gl_utils::check_errors(__FILE__, __LINE__);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, (3+4)*sizeof(float), (void*)(3*sizeof(float)));
		gl_utils::check_errors(__FILE__, __LINE__);
		glEnableVertexAttribArray(1);
	});
	_vao.set_ebo(indices);
	gl_utils::check_errors(__FILE__, __LINE__);
	_vao.unbind();	

}

Line::Line(const Axis& ax, const Program& p) : _prog(p){
	const std::vector<float> data = Line::getAxis(ax);
	_vao.bind();
	_vao.set_vbo(0, data, [](){
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, (3+4)*sizeof(float), nullptr);
		gl_utils::check_errors(__FILE__, __LINE__);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, (3+4)*sizeof(float), (void*)(3*sizeof(float)));
		gl_utils::check_errors(__FILE__, __LINE__);
		glEnableVertexAttribArray(1);
	});
	_vao.set_ebo(indices);
	gl_utils::check_errors(__FILE__, __LINE__);
	_vao.unbind();	

}

Line::~Line(){

}

void Line::render(){

	_prog.enable();
	_vao.bind();

	_prog.setUniform("pvm", pvm());
	_vao.draw(GL_LINES);
	gl_utils::check_errors(__FILE__, __LINE__);

	_vao.unbind();
	_prog.disable();

}

void Line::slave_render(){
	_vao.bind();
	_vao.draw();
	_vao.unbind();
}