#pragma once
#include "gl_config.h"
#include "bindable.h"
#include "attribute_properties.h"

class VBO : public Bindable{
public:

    VBO();
    ~VBO();

    void bind() override{
        glBindBuffer(GL_ARRAY_BUFFER, _id);
        gl_utils::check_errors(__FILE__, __LINE__);
		glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &_enabled);
    }

    void unbind() override{
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        gl_utils::check_errors(__FILE__, __LINE__);
		glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &_enabled);
    }

    template <typename T> void setAttribPointer(const GLuint& index, size_t n_components = 3){
        require_bound("VBO", "setData");
        
        if(n_components > 4) throw std::invalid_argument("[setAttribPointer] Number of components must be between 0 and 4");

        int stride = n_components*sizeof(T);
        glVertexAttribPointer(index, n_components, _dataType, GL_FALSE, stride, nullptr);
        gl_utils::check_errors(__FILE__, __LINE__);
        glEnableVertexAttribArray(index);
        gl_utils::check_errors(__FILE__, __LINE__);
    }

    template<typename T, std::size_t N> void setData(const std::array<T, N>& array, GLenum mode=GL_STATIC_DRAW){
        require_bound("VBO", "setData");
        _dataSize = array.size();
        _dataType = AttributeProperties<T>::dataType;
        glBufferData(_type, _dataSize*sizeof(T), array.data(), mode);
        gl_utils::check_errors(__FILE__, __LINE__);
    }

    template<typename T> void setData(const std::vector<T>& array, GLenum mode=GL_STATIC_DRAW) {
        require_bound("VBO", "setData");
        _dataSize = array.size();
        _dataType = AttributeProperties<T>::dataType;
        glBufferData(_type, _dataSize*sizeof(T), array.data(), mode);
        gl_utils::check_errors(__FILE__, __LINE__);
    }

private:

    GLenum _type = GL_ARRAY_BUFFER;
    GLenum _dataType;
    ssize_t _dataSize;

};
