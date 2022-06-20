#include "textures/texture.h"

Texture::Texture(const std::string& uri, const GLenum& texture_type, const GLenum& format) : _tex(uri), _texType(texture_type){
	glGenTextures(1, &_id);
	bind();

	glTexImage2D(_texType, 0, format, _tex.width, _tex.height, 0, GL_RGB, GL_UNSIGNED_BYTE, _tex.data);
	glGenerateMipmap(_texType);

	unbind();

	_tex.freeData();
}

Texture::~Texture(){

}

void Texture::bind(){
	glBindTexture(_texType, _id);
	_enabled = true;
}

void Texture::unbind(){
	glBindTexture(_texType, 0);
	_enabled = false;
}