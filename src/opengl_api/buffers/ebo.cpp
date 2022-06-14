#include "buffers/ebo.h"

EBO::EBO(){
	glGenBuffers(1, &_id);
}

EBO::~EBO(){
	glDeleteBuffers(1, &_id);
}