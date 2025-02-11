#include "vertex_buffer_object.h"
#include <glfw_exception.h>

VertexBufferObject::VertexBufferObject(const std::vector<float> data, GLenum usage) : _usage(usage), _data(data)
{
    glGenBuffers(1, &_id);
    if (_id == 0)
    {
        throw BufferGenError("Failed to bind buffer!");
    }
    bind();
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * _data.size(), _data.data(), usage);
    unbind();
}

VertexBufferObject::~VertexBufferObject(){
    glDeleteBuffers(1,&_id);
}

GLuint VertexBufferObject::id()
{
    return _id;
}

void VertexBufferObject::bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, _id);
}

void VertexBufferObject::unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}