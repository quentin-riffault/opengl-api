#include "opengl_api.h"
#include "buffers/vao.h"
#include <assert.h>
#include <exception>

VAO::VAO(uint vbo_count){
	glGenVertexArrays(1, &_id);

	if(vbo_count > GL_MAX_VERTEX_ATTRIBS) std::runtime_error("VBO count over VBO limit on VAO construction");

	for(uint i = 0; i < vbo_count; i++){
		_vbos.push_back(std::make_shared<VBO>());
	}
}

VAO::~VAO(){
	glDeleteVertexArrays(1, &_id);
}