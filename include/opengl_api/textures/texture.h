#pragma once

#include "image.h"
#include "buffers/bindable.h"

class Texture : public Bindable{
	public:
		Texture(const std::string& uri, const GLenum& texture_type = GL_TEXTURE_2D, const GLenum& internal_format = GL_RGB);
		~Texture();

		void bind() override;
		void unbind() override;

		void setParameteri(const GLenum& parameter, const GLenum& value){
			require_bound();
			glTexParameteri(_texType, parameter, value);
		}

	private: 
		Image _tex;
		const GLenum _texType;
};