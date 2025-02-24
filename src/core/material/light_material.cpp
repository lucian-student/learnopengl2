#include "material/light_material.h"

LightMaterial::LightMaterial(const RGBColor &color) : Material(),
                                                      _color(color),
                                                      _ambient(glm::vec3(0.1)),
                                                      _diffuse(glm::vec3(1.0)),
                                                      _specular(glm::vec3(0.5)),
                                                      _shininess(32.0)
{
}

LightMaterial::LightMaterial(
    const RGBColor &color,
    const glm::vec3 &ambient,
    const glm::vec3 &diffuse,
    const glm::vec3 &specular,
    float shininess) : Material(),
                       _color(color),
                       _ambient(ambient),
                       _diffuse(diffuse),
                       _specular(specular),
                       _shininess(shininess)
{
}

LightMaterial::~LightMaterial()
{
}

void LightMaterial::setUniforms(Program &program)
{
    program.setUniform(glm::vec4(_color.clampedRed(), _color.clampedGreen(), _color.clampedBlue(), _color.alpha()), "color");

    program.setUniform(_ambient, "material.ambient");
    program.setUniform(_diffuse, "material.diffuse");
    program.setUniform(_specular, "material.specular");
    program.setUniform(_shininess, "material.shininess");

    program.setUniform(glm::vec3(-2.0, 2.0, -3.0), "light.position");
    program.setUniform(glm::vec3(1.0), "light.ambient");
    program.setUniform(glm::vec3(1.0), "light.diffuse");
    program.setUniform(glm::vec3(1.0), "light.specular");
}

void LightMaterial::setShaders(Program &program)
{
    program.emplace_shader(GL_VERTEX_SHADER, "light\\box.vert");
    program.emplace_shader(GL_FRAGMENT_SHADER, "light\\box.frag");
}