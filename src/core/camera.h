#pragma once
#include <glm/glm.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <object3D.h>

class Camera : public Object3D
{
private:
    glm::mat4 _projectionMatrix;
    
    glm::vec3 _cameraTarget;
    glm::vec3 _cameraDirection;
    glm::vec3 _up;
    glm::vec3 _right;
    glm::mat4 _lookAt;

    void updateModelMatrix() override;
    glm::vec3 calculateDirectionVector() const;
    glm::vec3 calculateRightVector() const;
    glm::vec3 caculateUpVector() const;
public:
    Camera(float fov, float aspect, float near, float far);
    ~Camera();
    const glm::mat4 &projectionMatrix() const;
    const glm::mat4 &viewMatrix() const;

    void draw(const glm::mat4 &projection, const glm::mat4 &view) override;


    
};
