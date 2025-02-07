#pragma once
/*
Je potřeba vždy includnout glad a až potom glwf
*/
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class App
{
private:
    const static int DEFAULT_HEIGHT = 400;
    const static int DEFAULT_WIDTH = 400;

    GLFWwindow* _window;

public:
    App();
    ~App();

    void run();
};


