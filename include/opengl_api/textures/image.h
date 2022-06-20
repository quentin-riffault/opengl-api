#pragma once
#include "gl_config.h"

struct Image{

	Image(const std::string& uri);
	~Image();
	void freeData();
	
	unsigned char* data;
	int width;
	int height;
	int channels;
};