#define STB_IMAGE_IMPLEMENTATION
#include "textures/stb_image.h"
#include "textures/image.h"


Image::Image(const std::string& uri){
	data = stbi_load(uri.c_str(), &width, &height, &channels, 0);
	if(!data) throw std::runtime_error("Error while loading image");
}

Image::~Image(){}

void Image::freeData(){
	stbi_image_free(data);
}