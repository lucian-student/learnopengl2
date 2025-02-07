#include "app.h"

App::App(/* args */)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    _window = glfwCreateWindow(App::DEFAULT_WIDTH, App::DEFAULT_HEIGHT, "learn-opengl", NULL, NULL);
}

App::~App()
{
    glfwDestroyWindow(_window);
    glfwTerminate();
}

void App::run()
{
}