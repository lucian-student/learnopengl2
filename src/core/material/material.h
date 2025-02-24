#pragma once
#include <program.h>
#include <glm/glm.hpp>

class Material
{
protected:
public:
    Material();
    virtual ~Material();
    virtual void setUniforms(Program& program) = 0;
    virtual void setShaders(Program& program) = 0;
};