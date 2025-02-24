#pragma once
#include "material.h"
#include <color_utils.h>

class LightMaterial : public Material
{
private:
    RGBColor _color;

public:
    LightMaterial(const RGBColor &color);
    ~LightMaterial();
    void setUniforms(Program &program) override;
    void setShaders(Program &program) override;
};