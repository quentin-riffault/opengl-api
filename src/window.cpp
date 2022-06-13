#include "window.h"
#include <stdexcept>

AppWindow::AppWindow(int width, int height, const std::string& title){
    _win = createWindow(width, height, title);
    if(!_win) throw std::runtime_error("Could not create window");

    setAsCurrentContext();

    glfwSetFramebufferSizeCallback(_win, AppWindow::resize_callback);
}

AppWindow::~AppWindow() {
    glfwTerminate();
}

GLFWwindow* AppWindow::createWindow(int width, int height, const std::string &title) {

    InitGLFW();

    GLFWwindow * win = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    glfwMakeContextCurrent(win);

    InitGLEW();

    return win;

}

void AppWindow::error_callback(int error, const char *description) {
    std::string msg = "GLFW Error " + std::to_string(error) + ": " + description;
    throw std::runtime_error(msg);
}

void AppWindow::resize_callback(GLFWwindow* /*win*/, int height, int width) {
    glViewport(0, 0, width, height);
}

void AppWindow::render(){
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    for(const auto& r : _renderers){
        r.second->render();
    }

}

bool AppWindow::renderLoop(){

    controls();

    render();

    glfwSwapBuffers(_win);
    glfwPollEvents();

    return !glfwWindowShouldClose(_win);
}

void AppWindow::controls() {
    if(glfwGetKey(_win, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(_win, GLFW_TRUE);
    }
}

void AppWindow::InitGLFW(){

    glfwSetErrorCallback(error_callback);

    GLenum initCode = glfwInit();

    if(initCode != GLFW_TRUE) throw std::runtime_error("Could not initialize GLFW - Error");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, CUSTOM_GLFW_VERSION_MAJOR);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, CUSTOM_GLFW_VERSION_MINOR);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

}

void AppWindow::InitGLEW(){
    glewExperimental = GL_TRUE;

    GLenum initCode = glewInit();

    if(initCode != GLEW_OK) {
        const char* errmsg = reinterpret_cast<const char*>(glewGetErrorString(initCode));
        throw std::runtime_error(std::string("Could not initialize GLEW - Error: ") + std::string(errmsg));
    }

    if(!CUSTOM_GLEW_VERSION) throw std::runtime_error("Custom GLEW version not supported");

}

