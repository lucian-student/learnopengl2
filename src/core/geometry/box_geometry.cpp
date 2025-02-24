#include "geometry/box_geometry.h"
#include <glm/glm.hpp>
#include <algorithm>

std::vector<float> BoxGeometry::getData()
{
    float textureRange = 1.0;
    float strechedTextureRange = 2.0;
    std::vector<std::pair<glm::vec3, glm::vec2>> data = {
        // front
        {
            glm::vec3(-_side / 2, -_side / 2, _side / 2),
            glm::vec2(0.0, 0.0),
        },
        {
            glm::vec3(_side / 2, -_side / 2, _side / 2),
            glm::vec2(textureRange, 0.0),
        },
        {
            glm::vec3(_side / 2, _side / 2, _side / 2),
            glm::vec2(textureRange, textureRange),
        },
        {
            glm::vec3(-_side / 2, _side / 2, _side / 2),
            glm::vec2(0.0, textureRange),
        },
        // back
        {
            glm::vec3(_side / 2, -_side / 2, -_side / 2),
            glm::vec2(0.0, 0.0),
        },
        {
            glm::vec3(-_side / 2, -_side / 2, -_side / 2),
            glm::vec2(textureRange, 0.0),
        },
        {
            glm::vec3(-_side / 2, _side / 2, -_side / 2),
            glm::vec2(textureRange, textureRange),
        },
        {
            glm::vec3(_side / 2, _side / 2, -_side / 2),
            glm::vec2(0.0, textureRange),
        },
        // left
        {
            glm::vec3(-_side / 2, -_side / 2, -_side / 2),
            glm::vec2(0.0, 0.0),
        },
        {
            glm::vec3(-_side / 2, -_side / 2, _side / 2),
            glm::vec2(textureRange, 0.0),
        },
        {
            glm::vec3(-_side / 2, _side / 2, _side / 2),
            glm::vec2(textureRange, textureRange),
        },
        {
            glm::vec3(-_side / 2, _side / 2, -_side / 2),
            glm::vec2(0.0, textureRange),
        },
        // right
        {
            glm::vec3(_side / 2, -_side / 2, _side / 2),
            glm::vec2(0.0, 0.0),
        },
        {
            glm::vec3(_side / 2, -_side / 2, -_side / 2),
            glm::vec2(textureRange, 0.0),
        },
        {
            glm::vec3(_side / 2, _side / 2, -_side / 2),
            glm::vec2(textureRange, textureRange),
        },
        {
            glm::vec3(_side / 2, _side / 2, _side / 2),
            glm::vec2(0.0, textureRange),
        },
        // top
        {
            glm::vec3(-_side / 2, _side / 2, _side / 2),
            glm::vec2(0.0, 0.0),
        },
        {
            glm::vec3(_side / 2, _side / 2, _side / 2),
            glm::vec2(textureRange, 0.0),
        },
        {
            glm::vec3(_side / 2, _side / 2, -_side / 2),
            glm::vec2(textureRange, textureRange),
        },
        {
            glm::vec3(-_side / 2, _side / 2, -_side / 2),
            glm::vec2(0.0, textureRange),
        },
        // bottom
        {
            glm::vec3(-_side / 2, -_side / 2, -_side / 2),
            glm::vec2(0.0, 0.0),
        },
        {
            glm::vec3(_side / 2, -_side / 2, -_side / 2),
            glm::vec2(textureRange, 0.0),
        },
        {
            glm::vec3(_side / 2, -_side / 2, _side / 2),
            glm::vec2(textureRange, textureRange),
        },
        {
            glm::vec3(-_side / 2, -_side / 2, _side / 2),
            glm::vec2(0.0, textureRange),
        },
    };
    std::vector<float> simplifiedData;
    std::for_each(data.begin(), data.end(), [&](const std::pair<glm::vec3, glm::vec2> &x)
                  { simplifiedData.insert(simplifiedData.end(), {x.first[0], x.first[1], x.first[2], x.second[0], x.second[1]}); });
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

BoxGeometry::BoxGeometry(float side) : _side(side), BufferGeometry({{0, 3}, {1, 2}}, getData(), indices())
{
}

BoxGeometry::~BoxGeometry()
{
}