#pragma once
#define GLFW_INCLUDE_NONE
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <string>
#include <unordered_map>

class AppWindow{
public:
	AppWindow(int width = 300, int height = 300, const std::string& title = "AppWindow");
	virtual ~AppWindow();

    virtual bool renderLoop();

    void setCurrent(){ glfwMakeContextCurrent(_win); }
    void setTitle(const std::string& title) { glfwSetWindowTitle(_win, title.c_str()); }

    GLFWwindow* getWindowPointer(){ return _win; }

private:
    static void error_callback(int error, const char* description);
    inline static void resize_callback(GLFWwindow* win, int height, int width);
    static GLFWwindow* createWindow(int width, int height, const std::string& title);

private:
    GLFWwindow* _win;
};



