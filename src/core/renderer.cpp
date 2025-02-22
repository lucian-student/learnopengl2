#include "renderer.h"
#include <glad/glad.h>

Renderer::Renderer(std::unique_ptr<Camera> &&camera, std::unique_ptr<Scene> &&scene) : _camera(std::move(camera)), _scene(std::move(scene))
{
    glEnable(GL_DEPTH_TEST);
}

Renderer::~Renderer()
{
}

void Renderer::render() const
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    _scene->draw();
}

std::unique_ptr<Camera> &Renderer::camera()
{
    return _camera;
}

std::unique_ptr<Scene> &Renderer::scene()
{
    return _scene;
}
