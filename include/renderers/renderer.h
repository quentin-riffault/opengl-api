#pragma once

#include "gl_api.h"
#include "camera.h"

const std::string TEST_SHADER_PATH = "../src/shaders";
const std::string TEST_TEXTURE_PATH = "../../resources";

class Renderer {

public:

    Renderer() = default;
    
    /**
     * @brief Set the camera object for the renderer and its slaves
     * @param cam 
     */
    virtual void set_camera(const Camera* cam) { 
        _cam = cam;
        for(auto& r : _slaves){
            r->set_camera(cam);
        }        
    }

   /**
    * @brief Set the texture bank object for the renderer and its slaves
    * @param t 
    */
    virtual void set_texture_bank(TextureBank* t){ 
        std::cout << this << " (tbank)=> " << t << std::endl;
        _tbank = t; 
        for(auto& r : _slaves){
            r->set_texture_bank(t);
        }        
    }

    /**
     * @brief Set the program bank object for the renderer and its slaves
     * @param p 
     */
    virtual void set_program_bank(ProgramBank* p){
        std::cout << this << " (pbank)=> " << p << std::endl;
        _pbank = p; 
        for(auto& r : _slaves){
            r->set_program_bank(p);
        }        
    }

    /**
     * @brief Setup the renderer after being registered in the window renderer manager
     * 
    */
    virtual void setup_after_registration(){} 
    

public:

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
        _model = glm::rotate(glm::mat4(1.0f), angle, axis);
    }

    virtual void translate_to(const glm::vec3& translation){
        _model = glm::translate(glm::mat4(0.0f), translation);
    }

    virtual void scaling_to(const glm::vec3& scaling){
        _model = glm::scale(glm::mat4(1.0f), scaling);
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
        if(! _cam ) throw std::logic_error("[Renderer] No camera");
        return _cam->pv() * _model; 
    }


public:
    
    virtual void set_wireframe(bool state){ _wireframe = state; }
    void hide(){ _hide = true; }
    void show(){ _hide = false; }
    void toggle(){ _hide = !_hide; }

    void render_call(bool slave = false){

        if(_hide) return;
        glPolygonMode(GL_FRONT_AND_BACK, (_wireframe) ? GL_LINE : GL_FILL );
        (slave) ? slave_render() : render(); 

    }

    void operator()(bool slave = false){
        render_call(slave);
    }




protected:
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
        throw std::logic_error("Slave rendering not implemented");
    };

protected:

    glm::mat4 _base = glm::mat4(1.0f); // Initial model state
    glm::mat4 _model = _base; // Current model state
    std::vector<Renderer*> _slaves; // Renderers controlled by this renderer
    ProgramBank* _pbank; // Pointer to program bank, forbidden to delete
    TextureBank* _tbank; // Pointer to texture bank, forbidden to delete


    const Camera* _cam = nullptr;
    bool _wireframe = false;
    bool _hide = false;

};