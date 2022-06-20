#include "textures/texture.h"

Texture::Texture(const std::string& uri, const GLenum& format, const GLenum& texture_type) : _tex(uri), _texType(texture_type){
	glGenTextures(1, &_id);
    gl_utils::check_errors();
	bind();

	glTexImage2D(_texType, 0, format, _tex.width, _tex.height, 0, format, GL_UNSIGNED_BYTE, _tex.data);
    gl_utils::check_errors();
	glGenerateMipmap(_texType);
    gl_utils::check_errors();

	unbind();

	_tex.freeData();
}

Texture::~Texture(){
	glDeleteTextures(1, &_id);
    gl_utils::check_errors();
}

void Texture::bind(){
	glBindTexture(_texType, _id);
    gl_utils::check_errors();
	_enabled = true;
}

void Texture::unbind(){
	glBindTexture(_texType, 0);
    gl_utils::check_errors();
	_enabled = false;
}