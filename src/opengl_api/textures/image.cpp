#define STB_IMAGE_IMPLEMENTATION
#include "textures/stb_image.h"
#include "textures/image.h"


Image::Image(const std::string& uri){
	stbi_set_flip_vertically_on_load(true);
	data = stbi_load(uri.c_str(), &width, &height, &channels, 0);
	if(!data) throw std::runtime_error("Error while loading image " + uri);
}

Image::~Image(){}

void Image::freeData(){
	stbi_image_free(data);
}