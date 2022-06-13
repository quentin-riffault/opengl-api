#pragma once
#include "gl_config.h"
#include "buffers/buffer.h"
#include <vector>
#include <unistd.h>

class VBO : public Buffer{
public:

    VBO();
    ~VBO();

    void bind() override{
        glBindBuffer(GL_ARRAY_BUFFER, _id);
    }

    void unbind() override{
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    template<typename T> void setData(ssize_t size, const T* data, GLenum mode){
        glBufferData(GL_ARRAY_BUFFER, size, data, mode);
    }

    template<typename T> void setData(ssize_t size, std::vector<T> array, GLenum mode) {
        glBufferData(GL_ARRAY_BUFFER, size, array.data(), mode);
    }

private:
    unsigned int _id;

};
