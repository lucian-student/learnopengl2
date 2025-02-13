#pragma once
#include <string>
#include <stdexcept>
#include <glad/glad.h>

class Texture
{
private:
   GLuint _id;
   
   int _width;
   int _height;
   int _channels;

public:
    Texture(const std::string &filename,GLenum internaleFormat,GLenum format);
    ~Texture();

    void bind(GLenum textureUnit);

    GLuint id();
};