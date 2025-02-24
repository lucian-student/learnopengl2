#pragma once
#include <string>
#include <material/material.h>
#include <texture.h>

class MapMaterial : public Material
{
private:
    Texture _diffuseMap;
    Texture _specularMap;
    float _shininess;

public:
    MapMaterial(const std::string &diffuseMap, const std::string &specularMap, float shininess);
    ~MapMaterial();

    void setUniforms(Program& program) override;
    void setShaders(Program& program) override;
};