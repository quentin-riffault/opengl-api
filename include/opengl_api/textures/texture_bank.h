#pragma once

#include "textures/texture.h"
using TextureMap = StringMap<std::shared_ptr<Texture>>;

/**
 * @brief Manages all textures, useful to relieve memory usage
 * 
 */
class TextureBank{


	public:
		TextureBank();
		~TextureBank() = default;

		std::shared_ptr<Texture> getTextureInstance(const std::string& texture_identifier, const GLenum& format = GL_RGB, const GLenum& texture_type = GL_TEXTURE_2D);
		std::string texture_directory = "../resources/";

	private:
		TextureMap _bank;
};
