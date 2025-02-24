#include "geometry/box_geometry.h"
#include <glm/glm.hpp>
#include <algorithm>

std::vector<float> BoxGeometry::getData(float side)
{
    float textureRange = 1.0;
    std::vector<std::tuple<glm::vec3, glm::vec2, glm::vec3>> data = {
        // front
        {
            glm::vec3(-side / 2, -side / 2, side / 2),
            glm::vec2(0.0, 0.0),
            glm::vec3(0, 0, 1.0),
        },
        {
            glm::vec3(side / 2, -side / 2, side / 2),
            glm::vec2(textureRange, 0.0),
            glm::vec3(0, 0, 1.0),
        },
        {
            glm::vec3(side / 2, side / 2, side / 2),
            glm::vec2(textureRange, textureRange),
            glm::vec3(0, 0, 1.0),
        },
        {
            glm::vec3(-side / 2, side / 2, side / 2),
            glm::vec2(0.0, textureRange),
            glm::vec3(0, 0, 1.0),
        },
        // back
        {
            glm::vec3(side / 2, -side / 2, -side / 2),
            glm::vec2(0.0, 0.0),
            glm::vec3(0, 0, -1.0),
        },
        {
            glm::vec3(-side / 2, -side / 2, -side / 2),
            glm::vec2(textureRange, 0.0),
            glm::vec3(0, 0, -1.0),
        },
        {
            glm::vec3(-side / 2, side / 2, -side / 2),
            glm::vec2(textureRange, textureRange),
            glm::vec3(0, 0, -1.0),
        },
        {
            glm::vec3(side / 2, side / 2, -side / 2),
            glm::vec2(0.0, textureRange),
            glm::vec3(0, 0, -1.0),
        },
        // left
        {
            glm::vec3(-side / 2, -side / 2, -side / 2),
            glm::vec2(0.0, 0.0),
            glm::vec3(-1.0, 0, 0),
        },
        {
            glm::vec3(-side / 2, -side / 2, side / 2),
            glm::vec2(textureRange, 0.0),
            glm::vec3(-1.0, 0, 0),
        },
        {
            glm::vec3(-side / 2, side / 2, side / 2),
            glm::vec2(textureRange, textureRange),
            glm::vec3(-1.0, 0, 0),
        },
        {
            glm::vec3(-side / 2, side / 2, -side / 2),
            glm::vec2(0.0, textureRange),
            glm::vec3(-1.0, 0, 0),
        },
        // right
        {
            glm::vec3(side / 2, -side / 2, side / 2),
            glm::vec2(0.0, 0.0),
            glm::vec3(1.0, 0, 0),
        },
        {
            glm::vec3(side / 2, -side / 2, -side / 2),
            glm::vec2(textureRange, 0.0),
            glm::vec3(1.0, 0, 0),
        },
        {
            glm::vec3(side / 2, side / 2, -side / 2),
            glm::vec2(textureRange, textureRange),
            glm::vec3(1.0, 0, 0),
        },
        {
            glm::vec3(side / 2, side / 2, side / 2),
            glm::vec2(0.0, textureRange),
            glm::vec3(1.0, 0, 0),
        },
        // top
        {
            glm::vec3(-side / 2, side / 2, side / 2),
            glm::vec2(0.0, 0.0),
            glm::vec3(0, 1.0, 0),
        },
        {
            glm::vec3(side / 2, side / 2, side / 2),
            glm::vec2(textureRange, 0.0),
            glm::vec3(0, 1.0, 0),
        },
        {
            glm::vec3(side / 2, side / 2, -side / 2),
            glm::vec2(textureRange, textureRange),
            glm::vec3(0, 1.0, 0),
        },
        {
            glm::vec3(-side / 2, side / 2, -side / 2),
            glm::vec2(0.0, textureRange),
            glm::vec3(0, 1.0, 0),
        },
        // bottom
        {
            glm::vec3(-side / 2, -side / 2, -side / 2),
            glm::vec2(0.0, 0.0),
            glm::vec3(0, -1.0, 0),
        },
        {
            glm::vec3(side / 2, -side / 2, -side / 2),
            glm::vec2(textureRange, 0.0),
            glm::vec3(0, -1.0, 0),
        },
        {
            glm::vec3(side / 2, -side / 2, side / 2),
            glm::vec2(textureRange, textureRange),
            glm::vec3(0, -1.0, 0),
        },
        {
            glm::vec3(-side / 2, -side / 2, side / 2),
            glm::vec2(0.0, textureRange),
            glm::vec3(0, -1.0, 0),
        },
    };
    std::vector<float> simplifiedData;
    std::for_each(data.begin(), data.end(), [&](const std::tuple<glm::vec3, glm::vec2, glm::vec3> &x)
                  { simplifiedData.insert(simplifiedData.end(), {std::get<0>(x)[0], std::get<0>(x)[1], std::get<0>(x)[2], std::get<1>(x)[0], std::get<1>(x)[1], std::get<2>(x)[0], std::get<2>(x)[1], std::get<2>(x)[2]}); });
    return simplifiedData;
}

std::vector<unsigned int> BoxGeometry::indices()
{
    std::vector<unsigned int> side = {0, 1, 3, 3, 2, 1};
    std::vector<unsigned int> res;

    for (size_t i = 0; i < 6; i++)
    {
        std::for_each(side.begin(), side.end(), [&](unsigned int x)
                      { res.push_back(x + (i * 4)); });
    }
    return res;
}

BoxGeometry::BoxGeometry(float side) : BufferGeometry({{0, 3}, {1, 2}, {2, 3}}, getData(side), indices()), _side(side)
{
}

BoxGeometry::~BoxGeometry()
{
}