#include "material/light_material.h"

LightMaterial::LightMaterial(const RGBColor &color) : _color(color), Material()
{
}

LightMaterial::~LightMaterial()
{
}

void LightMaterial::setUniforms(Program &program)
{
    program.setUniform(glm::vec4(_color.clampedRed(), _color.clampedGreen(), _color.clampedBlue(), _color.alpha()), "color");
    program.setUniform(glm::vec3(1.0, 1.0, 1.0), "lightColor");
    program.setUniform(glm::vec3(-2.0, 2.0,-3.0),"lightPositon");
}

void LightMaterial::setShaders(Program &program)
{
    program.emplace_shader(GL_VERTEX_SHADER, "light\\box.vert");
    program.emplace_shader(GL_FRAGMENT_SHADER, "light\\box.frag");
}