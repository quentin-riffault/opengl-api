#include "window.h"

//#define RENDER_OVERRIDE



AppWindow::AppWindow(int width, int height, const std::string& title){
    _win = createWindow(width, height, title);
    if(!_win) throw std::runtime_error("Could not create window");

    setAsCurrentContext();

    glfwSetFramebufferSizeCallback(_win, AppWindow::resize_callback);

    _default = new Program(DEFAULT_FSHADER_PATH, DEFAULT_VSHADER_PATH);

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

    #ifdef RENDER_OVERRIDE

        float vertices[] = {
            0.5f, 0.0f, 0.0f,
            0.0f, 0.5f, 0.0f,
            0.0f, 0.0f, 0.5f
        };


        //uint vao = 0;
        VAO vao;
        VBO vbo;

        vao.bind();
        
        vbo.setData<float>(sizeof(vertices), vertices, GL_STATIC_DRAW);

        vbo.bind(); 
        // index, n_elements(1/2/3/4), type(enum), stride size
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), nullptr);
        glEnableVertexAttribArray(0);

        vbo.unbind();
        _default->enable();

        glDrawArrays(GL_TRIANGLES, 0, 3);

        _default->disable();
        vao.unbind();


    #else

        for(const auto& r : _renderers){
            r.second->render();
        }

    #endif

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

