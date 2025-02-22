#pragma once
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/ext/quaternion_float.hpp>
#include <glm/ext/quaternion_trigonometric.hpp>

/*
Musí to fungovat, tak že se uloží pozice, rotace
Potom se z toho zkonstruuje ModelMatrix
*/
class Object3D
{
protected:
    glm::vec3 _position;
    glm::quat _quaterinion;
    glm::mat4 _modelMatrix;

    void updateModelMatrix();

public:
    Object3D();
    virtual ~Object3D();
    const glm::mat4 &modelMatrix() const;
    void translate(const glm::vec3 &vec);
    void rotate(float angle, const glm::vec3 &vec);
    virtual void draw(const glm::mat4 &projection, const glm::mat4 &view) = 0;
};