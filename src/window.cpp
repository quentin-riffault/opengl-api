#include "window.h"

//#define RENDER_OVERRIDE



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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

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

    if(glfwGetKey(_win, GLFW_KEY_ESCAPE) == GLFW_PRESS) close();
    if(glfwGetKey(_win, GLFW_KEY_ENTER) == GLFW_PRESS) setWireframe();
    moveControls();

}

void AppWindow::moveControls(){
    if(glfwGetKey(_win, GLFW_KEY_PAGE_UP) == GLFW_PRESS) moveView(Direction::UP);
    if(glfwGetKey(_win, GLFW_KEY_PAGE_DOWN) == GLFW_PRESS) moveView(Direction::DOWN);
    if(glfwGetKey(_win, GLFW_KEY_W) == GLFW_PRESS) moveView(Direction::FORWARD);
    if(glfwGetKey(_win, GLFW_KEY_S) == GLFW_PRESS) moveView(Direction::BACKWARDS);
    if(glfwGetKey(_win, GLFW_KEY_A) == GLFW_PRESS) moveView(Direction::LEFT);
    if(glfwGetKey(_win, GLFW_KEY_D) == GLFW_PRESS) moveView(Direction::RIGHT);


    if(glfwGetKey(_win, GLFW_KEY_O) == GLFW_PRESS) moveView(Direction::ROLL_MINUS);
    if(glfwGetKey(_win, GLFW_KEY_P) == GLFW_PRESS) moveView(Direction::ROLL_PLUS);
    if(glfwGetKey(_win, GLFW_KEY_L) == GLFW_PRESS) moveView(Direction::PITCH_MINUS);
    if(glfwGetKey(_win, GLFW_KEY_M) == GLFW_PRESS) moveView(Direction::PITCH_PLUS);
    if(glfwGetKey(_win, GLFW_KEY_B) == GLFW_PRESS) moveView(Direction::YAW_MINUS);
    if(glfwGetKey(_win, GLFW_KEY_N) == GLFW_PRESS) moveView(Direction::YAW_PLUS);
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

