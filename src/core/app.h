#pragma once
/*
Je potřeba vždy includnout glad a až potom glwf
*/
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class App
{
private:
    const static int DEFAULT_HEIGHT = 800;
    const static int DEFAULT_WIDTH = 800;

    GLFWwindow* _window;


    void processInput();

    void update();

public:
    App();
    ~App();

    void run();
};


