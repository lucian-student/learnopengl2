#include "vertex_array_object.h"

VertexArrayObject::VertexArrayObject()
{
    glGenVertexArrays(1, &_id);
}

VertexArrayObject::~VertexArrayObject()
{
    glDeleteVertexArrays(1, &_id);
}

GLuint VertexArrayObject::id()
{
    return _id;
}

void VertexArrayObject::bind()
{
    glBindVertexArray(_id);
}

void VertexArrayObject::unbind()
{
    glBindVertexArray(0);
}