#include "box_mesh.h"
#include "algorithm"
#include <iostream>

std::vector<float> BoxMesh::getData()
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

std::vector<unsigned int> BoxMesh::indices()
{
    std::vector<unsigned int> side = {0, 1, 3, 3, 2, 1};
    std::vector<unsigned int> res;

    for (size_t i = 0; i < 6; i++)
    {
        std::for_each(side.begin(), side.end(), [&](unsigned int x) {
            res.push_back(x + (i * 4));
        });
    }
    return res;
}

BoxMesh::BoxMesh(float side) : Object3D(),
                               _side(side),
                               _vertextBufferObject(getData(), GL_STATIC_DRAW, GL_ARRAY_BUFFER),
                               _elementBufferObject(indices(), GL_STATIC_DRAW, GL_ELEMENT_ARRAY_BUFFER),
                               _program(),
                               _texture("container.jpg", GL_RGB, GL_RGB),
                               _texture2("awesomeface.png", GL_RGB, GL_RGBA)
{
    // nejdřív se musí nastavit vertex atributy
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(3 * sizeof(float)));
    // potom se musí nastavit shadery
    _program.emplace_shader(GL_VERTEX_SHADER, "square\\rotated_scaled.vert");
    _program.emplace_shader(GL_FRAGMENT_SHADER, "square\\one_reverse.frag");
    _program.link();
    _vertexArray.unbind();
    _texture.bind(GL_TEXTURE0);
    _texture2.bind(GL_TEXTURE1);
}

BoxMesh::~BoxMesh()
{
}

void BoxMesh::draw()
{
    _vertexArray.bind();
    _program.use();
    _program.setUniform(0, "fragmentTexture1");
    _program.setUniform(1, "fragmentTexture2");
    _program.setUniform(0.5f, "mixture");
    _program.setUniform(modelMatrix(), "transform");
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    _vertexArray.unbind();
}
