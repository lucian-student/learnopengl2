#include "shader.h"
#include <shader_utils.h>
#include <fstream>
#include <glfw_exception.h>
#include <file_exception.h>

Shader::Shader(GLenum type, const std::string &filename)
{
    _id = glCreateShader(type);
    if (_id == 0)
        throw ShaderCreationError("Nepodařilo se vytvořit shader!");

    std::ifstream shaderFile(filename);
    if (!shaderFile.good())
    {
        throw FailedToOpenFileError("Nepodařilo se otevřit soubor: " + filename + "!");
    }
}

Shader::~Shader()
{
    glDeleteShader(_id);
}

void Shader::attach(GLuint program)
{
    glAttachShader(program, _id);
}

std::string Shader::log()
{
    return shader_utils::getShaderLog(_id);
}