#pragma once
#include "gl_config.h"

template<typename T> struct AttributeProperties{
	static const ssize_t components = -1;
	static const GLenum dataType = GL_NONE;
};

template<> struct AttributeProperties<float>{
	static const ssize_t components = 3;
	static const GLenum dataType = GL_FLOAT;
};