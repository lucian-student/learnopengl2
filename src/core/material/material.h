#pragma once
#include <program.h>

class Material
{
protected:
public:
    Material();
    virtual ~Material();
    virtual void setUniforms(Program& program) = 0;
    virtual void setShaders(Program& program) = 0;
};