#pragma once
#include "material/material.h"
#include <color_utils.h>
#include <program.h>

class BasicMaterial : public Material
{
private:
    RGBColor _color;

public:
    BasicMaterial(const RGBColor &color);
    ~BasicMaterial();
    void setUniforms(Program& program) override;
    void setShaders(Program& program) override;
};