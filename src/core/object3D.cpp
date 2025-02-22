#include "object3D.h"
#include <glm/gtx/quaternion.hpp>

Object3D::Object3D() : _position(glm::vec3(0, 0, 0)), _quaterinion(glm::quat())
{
}

Object3D::~Object3D()
{
}

const glm::mat4 &Object3D::modelMatrix() const
{
    //zatím jsem vynechal rotaci
    return glm::translate(glm::mat4(), _position);
}

void Object3D::translate(const glm::vec3 &vec)
{
    _position += vec;
}

void Object3D::rotate(float angle, const glm::vec3 &vec)
{
    _quaterinion *= glm::angleAxis(angle, vec);
}