#include "camera.h"

Camera::Camera(float fov, float aspect, float near, float far) : Object3D(), _projectionMatrix(glm::perspective(fov, aspect, near, far))
{
}

Camera::~Camera()
{
}

const glm::mat4 &Camera::projectionMatrix() const
{
    return _projectionMatrix;
}

const glm::mat4 &Camera::viewMatrix() const
{
    return _modelMatrix;
}

void Camera::draw(const glm::mat4 &, const glm::mat4 &)
{
}