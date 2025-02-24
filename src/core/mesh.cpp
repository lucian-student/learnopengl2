#include "mesh.h"
#include <iostream>

Mesh::Mesh(std::unique_ptr<BufferGeometry> &&geometry, std::unique_ptr<Material> &&material) : _geometry(std::move(geometry)), _material(std::move(material)), _program()
{
    _material->setShaders(_program);
    _program.link();
    _geometry->unbind();
}

Mesh::~Mesh()
{
}

void Mesh::draw(const glm::mat4 &projection, const glm::mat4 &view)
{
    _geometry->bind();
    _program.use();
    _material->setUniforms(_program);
    _program.setUniform(projection, "projection");
    _program.setUniform(view, "view");
    _program.setUniform(modelMatrix(), "model");
    glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(_geometry->verticesCount()), GL_UNSIGNED_INT, 0);
    _geometry->unbind();
}