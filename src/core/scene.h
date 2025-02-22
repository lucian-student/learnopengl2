#pragma once

#include <vector>
#include <memory>
#include "object3D.h"

class Scene
{
private:
    std::vector<std::shared_ptr<Object3D>> _objects;
public:
    Scene();
    ~Scene();
    void push_back(const std::shared_ptr<Object3D> &object);
    void draw(const glm::mat4 &projection, const glm::mat4 &view);
};
