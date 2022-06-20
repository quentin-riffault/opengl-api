#pragma once

#include "image.h"
#include "buffers/bindable.h"

class Texture : public Bindable{
	public:
		Texture(const std::string& uri, const GLenum& format = GL_RGB, const GLenum& texture_type = GL_TEXTURE_2D);
		~Texture();

		void bind() override;
		void unbind() override;

		void setParameteri(const GLenum& parameter, const GLenum& value){
			require_bound();
			glTexParameteri(_texType, parameter, value);
		}

		void setTexunit(uint texunit){
			
			const int unit = GL_TEXTURE0 + texunit; 

			if(unit > GL_MAX_TEXTURE_UNITS)
				throw std::invalid_argument(std::string("[Texture] Unit size over max unit (") + std::to_string(GL_MAX_TEXTURE_UNITS) + ")");

			glActiveTexture(unit);
			bind();
		}

	private: 
		Image _tex;
		const GLenum _texType;
};