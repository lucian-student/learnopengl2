#include "camera.h"

Camera::Camera(float fov, float aspect, float near, float far) : _projectionMatrix(glm::perspective(fov, aspect, near, far))
{
}

Camera::~Camera()
{
}