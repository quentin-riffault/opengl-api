#pragma once

#include "gl_config.h"
#include "renderers/renderer.h"

class AppWindow{
public:
	AppWindow(int width = 300, int height = 300, const std::string& title = "AppWindow");
	virtual ~AppWindow();

    virtual bool renderLoop();

    void setAsCurrentContext(){ glfwMakeContextCurrent(_win); }
    void setTitle(const std::string& title) { glfwSetWindowTitle(_win, title.c_str()); }

    void addRenderer(const std::string& id, std::shared_ptr<Renderer> r) { 

        if(_renderers.find(id) != _renderers.end()){
            std::cerr << "[addRenderer] Ignoring new " << id << " renderer as one already exists" << std::endl;
            return;
        }

        r->set_projection(&_projection);
        r->set_view(&_view);
        _renderers[id] = r; 
        }
    void removeRenderer(const std::string& id) { _renderers.erase(id); }

    void setWireframe(const std::string& id, bool status){ _renderers[id]->set_wireframe(status); }

    void setWireframe(){
        _wireframe = !_wireframe;
        for(auto it = _renderers.begin(); it != _renderers.end(); it++)
            it->second->set_wireframe(_wireframe);
    }

    void setWireframe(bool status){
        for(auto it = _renderers.begin(); it != _renderers.end(); it++)
            it->second->set_wireframe(status);
    }

    GLFWwindow* getWindowPointer() { return _win; }

private:
    virtual void controls();
    virtual void moveControls();

    void render();
    static void error_callback(int error, const char* description);
    inline static void resize_callback(GLFWwindow* win, int height, int width);
    static void InitGLFW();
    static void InitGLEW();

    static GLFWwindow* createWindow(int width, int height, const std::string& title);


private:
// Reactions

    void close(){
        glfwSetWindowShouldClose(_win, GLFW_TRUE);
    };

    void moveView(Direction d){
        switch(d){
            case FORWARD: _view = glm::translate(_view, -Z_AXIS * dmove); break;
            case BACKWARDS: _view = glm::translate(_view, Z_AXIS * dmove); break;
            case UP: _view = glm::translate(_view, -Y_AXIS * dmove);break; 
            case DOWN: _view = glm::translate(_view, Y_AXIS * dmove);break;
            case LEFT: _view = glm::translate(_view, X_AXIS * dmove); break;
            case RIGHT: _view = glm::translate(_view, -X_AXIS * dmove); break;
            case PITCH_PLUS: _view = glm::rotate(_view, dmove, Y_AXIS); break;
            case PITCH_MINUS: _view = glm::rotate(_view, dmove, -Y_AXIS); break;
            case ROLL_PLUS: _view = glm::rotate(_view, dmove, X_AXIS); break;
            case ROLL_MINUS: _view = glm::rotate(_view, dmove, -X_AXIS); break;
            case YAW_PLUS: _view = glm::rotate(_view, dmove, Z_AXIS); break;
            case YAW_MINUS: _view = glm::rotate(_view, dmove, -Z_AXIS); break;
            case ZOOM_PLUS: _view = _view; break;
            case ZOOM_MINUS: _view = _view; break;
        }
    }

private:
    GLFWwindow* _win;
    std::unordered_map<std::string, std::shared_ptr<Renderer>> _renderers;

    const float dmove = 0.01f;
    glm::mat4 _view = glm::mat4(1.0f);
    glm::mat4 _projection = glm::mat4(1.0f);

    bool _wireframe = false;
};



