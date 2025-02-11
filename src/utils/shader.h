#pragma once
#include <glad/glad.h>
#include <string>

class Shader
{
private:
    GLuint _id;
public:
    Shader(GLenum type, const std::string &filename);
    ~Shader();
    void attach(GLuint program);
    std::string log();
};