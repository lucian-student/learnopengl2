#include "material/map_material.h"

MapMaterial::MapMaterial(const std::string &diffuseMap, const std::string &specularMap, float shininess) : Material(),
                                                                                                           _diffuseMap(diffuseMap, GL_RGB, GL_RGBA),
                                                                                                           _specularMap(diffuseMap, GL_RGB, GL_RGBA),
                                                                                                           _shininess(shininess)
{
}

MapMaterial::~MapMaterial()
{
}

void MapMaterial::setUniforms(Program &program)
{
    program.setUniform(GL_TEXTURE0,"material.diffuseMap");
    program.setUniform(GL_TEXTURE1,"material.specularMap");
    _diffuseMap.bind(GL_TEXTURE0);
    _specularMap.bind(GL_TEXTURE1);

    program.setUniform(_shininess,"material.shininess");

    program.setUniform(glm::vec3(-2.0, 2.0, -3.0), "light.position");
    program.setUniform(glm::vec3(1.0), "light.ambient");
    program.setUniform(glm::vec3(1.0), "light.diffuse");
    program.setUniform(glm::vec3(1.0), "light.specular");
}

void MapMaterial::setShaders(Program &program)
{
    program.emplace_shader(GL_VERTEX_SHADER,"light\\map.vert");
    program.emplace_shader(GL_FRAGMENT_SHADER,"light\\map.frag");
}