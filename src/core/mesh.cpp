#include "mesh.h"

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
    _program.use();
    _geometry->bind();
    _material->setUniforms(_program);
    _program.setUniform(modelMatrix(), "model");
    _program.setUniform(projection, "projection");
    _program.setUniform(view, "view");
    glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(_geometry->verticesCount()), GL_UNSIGNED_INT, 0);
    _geometry->unbind();
}