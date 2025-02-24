#pragma once
#include "material.h"
#include <color_utils.h>

class LightMaterial : public Material
{
private:
    RGBColor _color;
    glm::vec3 _ambient;
    glm::vec3 _diffuse;
    glm::vec3 _specular;
    float _shininess;

public:
    LightMaterial(const RGBColor &color);
    LightMaterial(const RGBColor &color, const glm::vec3 &ambient, const glm::vec3 &diffuse, const glm::vec3 &specular,float shininess);
    ~LightMaterial();
    void setUniforms(Program &program) override;
    void setShaders(Program &program) override;
};