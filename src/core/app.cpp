#include "app.h"
#include <glfw_exception.h>
#include <file_exception.h>
#include <color_utils.h>
#include <square_mesh.h>
#include <iostream>
#include <stdexcept>
#include <chrono>
#include <thread>
#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "renderer.h"
#include "scene.h"
#include "camera.h"
#include "box_mesh.h"

App::App() : _fps(App::DEFAULT_FPS)
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

    try
    {
        size_t counter = 0;
        double frameWindow = 1.0 / static_cast<double>(_fps);
        double lastUpdated = glfwGetTime();

        // potřebuje opravit
        float fov = glm::radians(45.0f);
        float aspect = static_cast<float>(App::DEFAULT_HEIGHT) / static_cast<float>(App::DEFAULT_HEIGHT);
        float near = 0.1;
        float far = 100;
        Renderer renderer(std::make_unique<Camera>(fov, aspect, near, far), std::make_unique<Scene>());
        renderer.camera()->translate(glm::vec3(0.0, 0.0, -5.0));
        std::shared_ptr<BoxMesh> box = std::make_shared<BoxMesh>(0.5);
        box->translate(glm::vec3(0, 0.5, 0));
        // box->rotate(glm::radians(230.401f), glm::vec3(0, 1.0, 0));
        renderer.scene()->push_back(box);
        float rotation = 360.0f / (static_cast<float>(_fps) * 10.0f);
        while (!glfwWindowShouldClose(_window))
        {
            // render loop code
            processInput();
            update();
            renderer.render();
            box->rotate(glm::radians(rotation), glm::vec3(1.0, 1.0, 1.0));
            //  swap buffers
            glfwSwapBuffers(_window);
            // aspoň v tutorialu v glfw mají nejdřív swap buffers, potom pollEvenets
            glfwPollEvents();
            double currentTime = glfwGetTime();
            double delta = currentTime - lastUpdated;
            if (delta < frameWindow)
            {
                long long miliseconds = static_cast<long long>((frameWindow - delta) * 1000.0);
                std::this_thread::sleep_for(std::chrono::milliseconds(miliseconds));
            }
            lastUpdated = glfwGetTime();
        }
    }
    catch (const std::runtime_error &error)
    {
        std::cout << error.what() << std::endl;
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
