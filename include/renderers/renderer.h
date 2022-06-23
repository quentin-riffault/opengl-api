#pragma once

#include "gl_api.h"

const std::string TEST_SHADER_PATH = "../src/shaders";
const std::string TEST_TEXTURE_PATH = "../../resources";

class Renderer {

public:

    Renderer() = default;

    /**
     * @brief Complete render with a given program.
     * 
     */
    virtual void render() = 0;
    
    /**
     * @brief Rendering using another class (such as a line with a trihedron)
     * 
     */
    virtual void slave_render(){

    }

    virtual void set_wireframe(bool state){ wireframe = state; }
    virtual void set_view(const glm::mat4* view) { _view = view;}
    virtual void set_projection(const glm::mat4* projection){ _projection = projection;}


    // Transforms on the current state of the model matrix
    virtual void rotate(const glm::vec3& axis, const float& angle){
        _model = glm::rotate(_model, angle, axis);
    }

    virtual void translate(const glm::vec3& translation){
        _model = glm::translate(_model, translation);
    }

    virtual void scale(const glm::vec3& scaling){
        _model = glm::scale(_model, scaling);
    }

    // Transforms from the base matrix    
    virtual void rotate_to(const glm::vec3& axis, const float& angle){
        _model = glm::rotate(_base, angle, axis);
    }

    virtual void translate_to(const glm::vec3& translation){
        _model = glm::translate(_base, translation);
    }

    virtual void scaling_to(const glm::vec3& scaling){
        _model = glm::scale(_base, scaling);
    }

    glm::mat4 get_model(){
        return _model;
    }


    virtual void transform(const glm::vec3& translation_vector = glm::vec3(1.0f), const glm::vec3& rotation_axis = glm::vec3(1.0f), const glm::vec3& scaling_vector = glm::vec3(1.0f), const float& angle = 0.0f){
        translate(translation_vector);
        rotate(rotation_axis, angle);
        scale(scaling_vector);
    }

    virtual glm::mat4 pvm(){
        if(! (_projection || _view) ) throw std::logic_error("[Renderer] Uninitialized view or projection matrix");
        return (*_projection) * (*_view) * _model; 
    }


protected:
    glm::mat4 _base = glm::mat4(1.0f); // < Initial model state
    glm::mat4 _model = _base; // < Current model state
    const glm::mat4* _view = nullptr;
    const glm::mat4* _projection = nullptr;


    bool wireframe = false;

};