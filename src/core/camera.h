#pragma once
#include <glm/glm.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <object3D.h>

class Camera : public Object3D
{
private:
    glm::mat4 _projectionMatrix;

public:
    Camera(float fov, float aspect, float near, float far);
    ~Camera();
    const glm::mat4 &projectionMatrix() const;
    const glm::mat4 &viewMatrix() const;

    void draw(const glm::mat4 &projection, const glm::mat4 &view) override;
};
