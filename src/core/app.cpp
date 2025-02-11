#include "app.h"
#include <glfw_exception.h>
#include <color_utils.h>
#include <triangle_mesh.h>
#include <glm/vec3.hpp>

App::App()
{
    int width = App::DEFAULT_WIDTH;
    int height = App::DEFAULT_HEIGHT;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    _window = glfwCreateWindow(width, height, "learn-opengl", NULL, NULL);
    if (_window == NULL)
        throw WindowInitializationError("Nepordařilo se incializovat okno!");
    glfwMakeContextCurrent(_window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        throw GladLoadError("Nepodařilo se načíst glad!");
    }

    glViewport(0, 0, width, height);

    auto resizeCallback = [](GLFWwindow *window, int width, int height)
    {
        glViewport(0, 0, width, height);
    };

    glfwSetFramebufferSizeCallback(_window, resizeCallback);
}

App::~App()
{
    glfwDestroyWindow(_window);
    glfwTerminate();
}

void App::run()
{
    IndexedTriangleMesh triangle1(Triangle(glm::vec3(-1, -0.5, 0.0), glm::vec3(0, -0.5, 0.0), glm::vec3(-0.5, 0.5, 0.0)), RGBColor(125, 0, 0));
    IndexedTriangleMesh triangle2(Triangle(glm::vec3(0.0, -0.5, 0.0), glm::vec3(1.0, -0.5, 0.0), glm::vec3(0.5, 0.5, 0.0)), RGBColor(0, 0, 125));

    while (!glfwWindowShouldClose(_window))
    {
        // render loop code
        processInput();
        update();
        triangle1.draw();
        triangle2.draw();
        // swap buffers
        glfwSwapBuffers(_window);
        // aspoň v tutorialu v glfw mají nejdřív swap buffers, potom pollEvenets
        glfwPollEvents();
    }
}

void App::processInput()
{
    if (glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(_window, true);
}

void App::update()
{
    // rgb(175, 225, 175)
    RGBColor backgroundColor(175, 225, 175);
    glClearColor(backgroundColor.clampedRed(), backgroundColor.clampedGreen(), backgroundColor.clampedBlue(), backgroundColor.alpha());
    glClear(GL_COLOR_BUFFER_BIT);
}
