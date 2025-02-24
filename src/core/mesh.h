#pragma once
#include <memory>
#include "object3D.h"
#include "geometry/buffer_geometry.h"
#include "material/material.h"

class Mesh : public Object3D
{
private:

    std::unique_ptr<BufferGeometry> _geometry;
    std::unique_ptr<Material> _material;

public:
    Mesh(std::unique_ptr<BufferGeometry> &&geometry, std::unique_ptr<Material> &&material);
    ~Mesh();

    void draw(const glm::mat4 &projection, const glm::mat4 &view) override;
};
