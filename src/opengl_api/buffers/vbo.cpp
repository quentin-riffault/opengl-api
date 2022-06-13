#include "buffers/vbo.h"

VBO::VBO(){
    glGenBuffers(1, &_id);
}

VBO::~VBO(){
    glDeleteBuffers(1, &_id);
}

