#include "camera.h"

Camera::Camera(float fov, float aspect, float near, float far) : Object3D(),
                                                                 _projectionMatrix(glm::perspective(fov, aspect, near, far)),
                                                                 _cameraTarget(glm::vec3(0, 0, 0)),
                                                                 _cameraDirection(calculateDirectionVector()),
                                                                 _up(glm::vec3(0, 1.0, 0)),
                                                                 _lookAt(glm::mat4(1.0))

{
    updateModelMatrix();
}

Camera::~Camera()
{
}

void Camera::updateModelMatrix()
{
    Object3D::updateModelMatrix();
    _cameraDirection = calculateDirectionVector();
    _right = calculateRightVector();
    _up = caculateUpVector();
    _lookAt = glm::lookAt(
       _position,
       _cameraTarget,
       glm::vec3(0, 1.0, 0)
    );
}

const glm::mat4 &Camera::projectionMatrix() const
{
    return _projectionMatrix;
}

const glm::mat4 &Camera::viewMatrix() const
{
    return _lookAt;
}

void Camera::draw(const glm::mat4 &, const glm::mat4 &)
{
}

// reprezentuje směr z+
glm::vec3 Camera::calculateDirectionVector() const
{
    return glm::normalize(_position - _cameraTarget);
}

/*
Prý zavisí na přadí, protože potřebujeme získat x+ vektor
*/
glm::vec3 Camera::calculateRightVector() const
{
    return glm::normalize(glm::cross(_up, _cameraDirection));
}

/*
Taky zavisí na pořadí y+
*/
glm::vec3 Camera::caculateUpVector() const
{
    return glm::normalize(glm::cross(_cameraDirection, _right));
}