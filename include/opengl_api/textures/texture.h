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
			require_bound("Texture", "setParameteri");
			glTexParameteri(_texType, parameter, value);
			gl_utils::check_errors();
		}

		void setTexunit(uint texunit){
			
			glActiveTexture(GL_TEXTURE0 + texunit);
			gl_utils::check_errors();
			bind();
		}

	private: 
		Image _tex;
		const GLenum _texType;
};