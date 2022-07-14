#include "textures/texture_bank.h"

TextureBank::TextureBank() : _bank(64){

}

/**
 * @brief Fetches a texture in cache or on the disk
 * 
 * @param texture_identifier Full image name with extension 
 * @param format Image format to use the Opengl texture 
 * @param texture_type Type of Opengl texture
 * @return std::shared_ptr<Texture> 
 */
std::shared_ptr<Texture> TextureBank::getTextureInstance(const std::string& texture_identifier, const GLenum& format, const GLenum& texture_type){


	if(_bank.find(texture_identifier) != _bank.end()){
		std::cout << "[getTextureInstance] Loading " << texture_identifier << " from cache" << std::endl;
		return _bank[texture_identifier];
	}


	const std::string image_uri = texture_directory + "/" + texture_identifier;

	std::shared_ptr<Texture> t =  std::make_shared<Texture>(image_uri, format, texture_type);
	_bank.insert(std::make_pair(texture_identifier, t));
	std::cout << "[getTextureInstance] Texture " << texture_identifier << " Loaded. "  << "- Loaded textures : " << _bank.size() << std::endl;
	return t;

}