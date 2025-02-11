#pragma once
#include <glad/glad.h>

class VertexArrayObject
{
private:
    GLuint _id;
public:
    VertexArrayObject();
    ~VertexArrayObject();

    GLuint id();

    void bind();
    void unbind();
};

