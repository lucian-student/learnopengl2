#pragma once
#include <vector>
#include <glad/glad.h>


class VertexBufferObject
{
private:
    GLuint _id;
    GLenum _usage;
    std::vector<float> _data;
public:
    VertexBufferObject(const std::vector<float> data,GLenum usage);
    ~VertexBufferObject();

    GLuint id();

    void bind();
    void unbind();
};
