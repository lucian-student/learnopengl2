#pragma once
#include <vector>
#include <vertex_array_object.h>
#include <buffer_object.h>
#include <glad/glad.h>

struct VertexAttribute
{
    GLuint location;
    GLint size;
};

class BufferGeometry
{
protected:
    VertexArrayObject _vertexArrayObject;
    BufferObject<float> _vertexBufferObject;
    BufferObject<unsigned int> _elementBufferObject;

    size_t _vertices;

public:
    BufferGeometry(
        const std::vector<VertexAttribute> &attributes,
        const std::vector<float> &vertexData,
        const std::vector<unsigned int> &elementData);
    virtual ~BufferGeometry();

    void bind();
    void unbind();

    size_t verticesCount() const;
};