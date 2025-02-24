#include "object3D.h"
#include <glm/gtx/quaternion.hpp>
#include <iostream>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>

Object3D::Object3D() : _position(glm::vec3(0, 0, 0)), _quaterinion(glm::angleAxis(0.0f, glm::vec3(0,0,0))), _modelMatrix(glm::mat4(1.0))
{
}

Object3D::~Object3D()
{
}

void Object3D::updateModelMatrix()
{
    _modelMatrix = glm::mat4(1.0);
    auto rotation = glm::mat4_cast(_quaterinion);
    auto translation = glm::translate(glm::mat4(1.0), _position);
    _modelMatrix = translation * rotation * _modelMatrix;
    
}

const glm::mat4 &Object3D::modelMatrix() const
{
    // zatím jsem vynechal rotaci
    return _modelMatrix;
}

void Object3D::translate(const glm::vec3 &vec)
{
    _position += vec;
    updateModelMatrix();
}

void Object3D::rotate(float angle, const glm::vec3 &vec)
{
    //zatím špatně
    _quaterinion *= glm::angleAxis(angle, vec);
    updateModelMatrix();
}