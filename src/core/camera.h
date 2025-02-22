#pragma once
#include <glm/glm.hpp>
#include <glm/ext/matrix_clip_space.hpp>

class Camera
{
private:
    
    glm::mat4 _projectionMatrix;

public:
    Camera(float fov, float aspect, float near, float far);
    ~Camera();
};
