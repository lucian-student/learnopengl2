#include "mesh.h"

Mesh::Mesh(std::unique_ptr<BufferGeometry> &&geometry, std::unique_ptr<Material> &&material) : _geometry(std::move(geometry)), _material(std::move(material))
{
}

Mesh::~Mesh()
{
}

void Mesh::draw(const glm::mat4 &projection, const glm::mat4 &view)
{
    
}