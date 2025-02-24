#include "geometry/buffer_geometry.h"
#include <algorithm>

BufferGeometry::BufferGeometry(
    const std::vector<VertexAttribute> &attributes,
    const std::vector<float> &vertexData,
    const std::vector<unsigned int> &elementData) : _vertexArrayObject(),
                                                    _vertexBufferObject(vertexData, GL_STATIC_DRAW, GL_ARRAY_BUFFER),
                                                    _elementBufferObject(elementData, GL_STATIC_DRAW, GL_ELEMENT_ARRAY_BUFFER),
                                                    _vertices(elementData.size())
{
    GLint totalSize = 0;
    std::for_each(attributes.begin(), attributes.end(), [&](const VertexAttribute &va)
                  { totalSize += va.size; });

    GLint index = 0;
    for (const auto &va : attributes)
    {
        glEnableVertexAttribArray(va.location);
        glVertexAttribPointer(va.location, va.size, GL_FLOAT, GL_FALSE, totalSize * sizeof(float), (void *)(index * sizeof(float)));
        index += va.size;
    }
    _vertexArrayObject.unbind();
}

BufferGeometry::~BufferGeometry()
{
}

void BufferGeometry::bind()
{
    _vertexArrayObject.bind();
}

void BufferGeometry::unbind()
{
    _vertexArrayObject.unbind();
}

size_t BufferGeometry::verticesCount()const{
    return _vertices;
}