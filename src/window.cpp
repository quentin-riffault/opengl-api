#include "window.h"
#include <stdexcept>

AppWindow::AppWindow(int width, int height, const std::string& title){
    _win = createWindow(width, height, title);
    if(!_win) throw std::runtime_error("Could not create window");

    glfwSetFramebufferSizeCallback(_win, AppWindow::resize_callback);
}

AppWindow::~AppWindow() {
    glfwTerminate();
}

GLFWwindow* AppWindow::createWindow(int width, int height, const std::string &title) {

    glfwSetErrorCallback(error_callback);

    if(!glfwInit()) throw std::runtime_error("Could not initialize GLFW");
    if(!glewInit()) throw std::runtime_error("Could not initialize GLEW");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    return glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

}

void AppWindow::error_callback(int error, const char *description) {
    std::string msg = "GLFW Error " + std::to_string(error) + ": " + description;
    throw std::runtime_error(msg);
}

void AppWindow::resize_callback(GLFWwindow* /*win*/, int height, int width) {
    glViewport(0, 0, width, height);
}


bool AppWindow::renderLoop(){

    glfwSwapBuffers(_win);
    glfwPollEvents();

    return !glfwWindowShouldClose(_win);
}


