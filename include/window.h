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

    void addRenderer(const std::string& id, std::shared_ptr<Renderer> r) { _renderers[id] = r; }
    void removeRenderer(const std::string& id) { _renderers.erase(id); }

    GLFWwindow* getWindowPointer() { return _win; }

private:
    virtual void controls();
    void render();
    static void error_callback(int error, const char* description);
    inline static void resize_callback(GLFWwindow* win, int height, int width);
    static void InitGLFW();
    static void InitGLEW();

    static GLFWwindow* createWindow(int width, int height, const std::string& title);

private:
    GLFWwindow* _win;
    std::unordered_map<std::string, std::shared_ptr<Renderer>> _renderers;
    const std::string DEFAULT_FSHADER_PATH = "/data/Projets/opengl_boilerplate/src/shaders/simple.f.glsl";
    const std::string DEFAULT_VSHADER_PATH = "/data/Projets/opengl_boilerplate/src/shaders/simple.v.glsl";
    Program* _default;
};



