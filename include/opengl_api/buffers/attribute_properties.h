#pragma once
#include "gl_config.h"

template<typename T> struct AttributeProperties{
	static const GLenum dataType = GL_NONE;
};

template<> struct AttributeProperties<float>{
	static const GLenum dataType = GL_FLOAT;
};