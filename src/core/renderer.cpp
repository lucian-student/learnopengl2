#include "renderer.h"

Renderer::Renderer(std::unique_ptr<Camera> &&camera, std::unique_ptr<Scene> &&scene) : _camera(std::move(camera)), _scene(std::move(scene))
{
}

Renderer::~Renderer()
{
}

void Renderer::render() const
{
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
