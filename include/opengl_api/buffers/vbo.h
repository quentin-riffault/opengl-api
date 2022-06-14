#pragma once
#include "gl_config.h"
#include "buffers/buffer.h"
#include <vector>
#include <unistd.h>
#include "attribute_properties.h"

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

    template <typename T> void setAttribPointer(const GLuint& index){
        bind();
        int stride = _components*sizeof(T);
        glVertexAttribPointer(index, _components, _dataType, GL_FALSE, stride, nullptr);
        glEnableVertexAttribArray(index);
        unbind();
    }

    template<typename T, std::size_t N> void setData(const std::array<T, N>& array, GLenum mode=GL_STATIC_DRAW){
        bind();

        _dataSize = array.size();
        _dataType = AttributeProperties<T>::dataType;
        _components = AttributeProperties<T>::components;
        glBufferData(_type, _dataSize*sizeof(T), array.data(), mode);

        unbind();
    }

    template<typename T> void setData(const std::vector<T>& array, GLenum mode=GL_STATIC_DRAW) {
        bind();

        _dataSize = array.size();
        _dataType = AttributeProperties<T>::dataType;
        _components = AttributeProperties<T>::components;
        glBufferData(_type, _dataSize*sizeof(T), array.data(), mode);

        unbind();
    }

private:

    uint _id;
    GLenum _type = GL_ARRAY_BUFFER;
    ssize_t _dataSize;
    GLenum _dataType;
    ssize_t _components;


};
