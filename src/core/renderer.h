#pragma once
#include <memory>
#include "scene.h"
#include "camera.h"

class Renderer
{
private:
    std::unique_ptr<Camera> _camera;
    std::unique_ptr<Scene> _scene;
public:
    Renderer(std::unique_ptr<Camera> &&camera,std::unique_ptr<Scene> &&scene);
    ~Renderer();
    void render() const;
    std::unique_ptr<Camera>& camera();
    std::unique_ptr<Scene>& scene();
};