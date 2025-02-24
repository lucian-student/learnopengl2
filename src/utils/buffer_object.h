#pragma once
#include <vector>
#include <glad/glad.h>
#include <glfw_exception.h>
#include <iostream>

template <typename T>
class BufferObject
{
private:
    GLuint _id;
    GLenum _usage;
    GLenum _target;
    std::vector<T> _data;

public:
    BufferObject();
    BufferObject(const std::vector<T> data, GLenum usage, GLenum target);
    ~BufferObject();

    GLuint id();

    void bind();
    void unbind();
};

template <typename T>
BufferObject<T>::BufferObject() : _usage(GL_STATIC_DRAW), _target(GL_ARRAY_BUFFER), _data()
{
}

template <typename T>
BufferObject<T>::BufferObject(const std::vector<T> data, GLenum usage, GLenum target) : _usage(usage), _target(target), _data(data)
{
    glGenBuffers(1, &_id);
    if (_id == 0)
    {
        throw BufferGenError("Failed to bind buffer!");
    }
    bind();
    glBufferData(_target, sizeof(T) * _data.size(), _data.data(), usage);
}

template <typename T>
BufferObject<T>::~BufferObject()
{
    glDeleteBuffers(1, &_id);
}

template <typename T>
GLuint BufferObject<T>::id()
{
    return _id;
}

template <typename T>
void BufferObject<T>::bind()
{
    glBindBuffer(_target, _id);
}

template <typename T>
void BufferObject<T>::unbind()
{
    glBindBuffer(_target, 0);
}