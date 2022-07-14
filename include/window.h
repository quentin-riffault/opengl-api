#pragma once

#include "gl_config.h"
#include "renderers/renderer.h"
#include "camera.h"

using RendererMap = StringMap<std::shared_ptr<Renderer>>;

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

        std::cout << "[addRenderer] New renderer " << id << std::endl;

        r->set_camera(&_cam);
        r->set_program_bank(&_pbank);
        r->set_texture_bank(&_tbank);
        
        _renderers[id] = r; 
        r->setup_after_registration();
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

/*Callbacks*/

    static void error_callback(int error, const char* description);
    inline static void resize_callback(GLFWwindow* win, int height, int width);
    virtual void mouse_callback(GLFWwindow* win, int button, int action, int mods); 
    virtual void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

/*Initialization*/
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
            case FORWARD: _cam.translate(-Z_AXIS * dmove); break;
            case BACKWARDS: _cam.translate(Z_AXIS * dmove); break;
            case UP: _cam.translate(-Y_AXIS * dmove);break; 
            case DOWN: _cam.translate(Y_AXIS * dmove);break;
            case LEFT: _cam.translate(X_AXIS * dmove); break;
            case RIGHT: _cam.translate(-X_AXIS * dmove); break;
            case PITCH_PLUS: _cam.rotate(dmove*2, Y_AXIS); break;
            case PITCH_MINUS: _cam.rotate(dmove*2, -Y_AXIS); break;
            case ROLL_PLUS: _cam.rotate(dmove*2, X_AXIS); break;
            case ROLL_MINUS: _cam.rotate(dmove*2, -X_AXIS); break;
            case YAW_PLUS: _cam.rotate(dmove*2, Z_AXIS); break;
            case YAW_MINUS: _cam.rotate(dmove*2, -Z_AXIS); break;
            case ZOOM_PLUS: break;
            case ZOOM_MINUS: break;
            default: throw std::logic_error("[moveView] unhandled direction");
        }
    }
    

private:
    GLFWwindow* _win;
    RendererMap _renderers;

    Camera _cam;


    bool _wireframe = false;
    const float dmove = 0.01f;

public: 

    TextureBank _tbank;
    ProgramBank _pbank;
};



