#include "square_mesh.h"
#include <vector>
#include <glm/vec2.hpp>
#include <algorithm>

std::vector<float> SquareMesh::getData()
{
    float textureRange = 1.0;
    std::vector<std::pair<glm::vec3, glm::vec2>> data = {
        {
            glm::vec3(-_width / 2, -_width / 2, 0.0),
            glm::vec2(0.0, 0.0),
        },
        {
            glm::vec3(_width / 2, -_width / 2, 0.0),
            glm::vec2(textureRange, 0.0),
        },
        {
            glm::vec3(_width / 2, _width / 2, 0.0),
            glm::vec2(textureRange, textureRange),
        },
        {
            glm::vec3(-_width / 2, _width / 2, 0.0),
            glm::vec2(0.0, textureRange),
        },
    };
    std::vector<float> simplifiedData;
    std::for_each(data.begin(), data.end(), [&](const std::pair<glm::vec3, glm::vec2> &x)
                  { simplifiedData.insert(simplifiedData.end(), {x.first[0], x.first[1], x.first[2], x.second[0], x.second[1]}); });
    return simplifiedData;
}

std::vector<unsigned int> SquareMesh::indices()
{
    return {0,1,3,3,2,1};
}

SquareMesh::SquareMesh(float width) : _width(width),
                                      _vertexArray(),
                                      _vertextBufferObject(getData(), GL_STATIC_DRAW, GL_ARRAY_BUFFER),
                                      _elementBufferObject(indices(), GL_STATIC_DRAW, GL_ELEMENT_ARRAY_BUFFER),
                                      _program(),
                                      _texture("container.jpg", GL_RGB, GL_RGB),
                                      _texture2("awesomeface.png", GL_RGB, GL_RGBA)
{
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(3 * sizeof(float)));

    _program.emplace_shader(GL_VERTEX_SHADER, "square\\square_texture.vert");
    _program.emplace_shader(GL_FRAGMENT_SHADER, "square\\one_reverse.frag");
    _program.link();
    _program.use();
    _vertexArray.unbind();
}

SquareMesh::~SquareMesh()
{
}

void SquareMesh::draw()
{
    _vertexArray.bind();
    _program.use();
    _texture.bind(GL_TEXTURE0);
    _texture2.bind(GL_TEXTURE1);
    _program.setUniform(0,"fragmentTexture1");
    _program.setUniform(1,"fragmentTexture2");
    _program.setUniform(0.5f,"mixture");
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    _vertexArray.unbind();
}