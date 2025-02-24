#include "material/basic_material.h"

BasicMaterial::BasicMaterial(const RGBColor &color) : _color(color), Material()
{
}

BasicMaterial::~BasicMaterial()
{
}

void BasicMaterial::setUniforms(Program &program)
{
    program.setUniform(glm::vec4(_color.clampedRed(), _color.clampedGreen(), _color.clampedBlue(), _color.alpha()), "color");
}

void BasicMaterial::setShaders(Program &program)
{
    program.emplace_shader(GL_VERTEX_SHADER, "box\\box.vert");
    program.emplace_shader(GL_FRAGMENT_SHADER, "box\\frag.vert");
}