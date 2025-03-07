#include "scene.h"
#include <algorithm>
#include <iostream>

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::push_back(const std::shared_ptr<Object3D> &object)
{
    _objects.push_back(object);
}

void Scene::draw(const glm::mat4 &projection, const glm::mat4 &view)
{
    std::for_each(_objects.begin(), _objects.end(), [&](const std::shared_ptr<Object3D> &object)
                  { object->draw(projection,view); });
}