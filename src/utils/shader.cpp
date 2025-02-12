#include "shader.h"
#include <fstream>
#include <sstream>
#include <shader_utils.h>
#include <glfw_exception.h>
#include <file_exception.h>
#include <utils.h>
#include <iostream>
#include <filesystem>

/*
Zatím nedporučuju použít, porotože inicializuje objekt do nevalidního stavu
*/
Shader::Shader() noexcept : _id(0)
{
}

Shader::Shader(GLenum type, const std::string &filename) 
{
    std::filesystem::path executablePath(utils::executablePath());
    std::filesystem::path shaderPath = executablePath.parent_path().parent_path().parent_path().parent_path();
    shaderPath /= "src";
    shaderPath /= "shaders";
    shaderPath /= filename;

    _id = glCreateShader(type);
    if (_id == 0)
    {
        throw ShaderCreationError("Nepodařilo se vytvořit shader!");
    }

    std::ifstream shaderFile(shaderPath);
    if (!shaderFile.good())
    {
        glDeleteShader(_id);
        throw FailedToOpenFileError("Nepodařilo se otevřit soubor: " + shaderPath.string() + "!");
    }
    shaderFile.exceptions(std::ios::badbit | std::ios::failbit);

    try
    {
        std::stringstream fileContents;
        std::string line;
        fileContents << shaderFile.rdbuf();
        shaderFile.close();

        std::string strShaderCode = fileContents.str();
        const char *shaderCode = strShaderCode.c_str();
        glShaderSource(_id, 1, &shaderCode, NULL);
    }
    catch (const std::ifstream::failure &err)
    {
        throw FileReadError("Error while reading file!");
    }

    glCompileShader(_id);
    if (!shader_utils::shaderCompiled(_id))
    {
        glDeleteShader(_id);
        throw ShaderCompilationError("Nepodařilo se zkompilovat shader: " + log() + "!");
    }
}

Shader::~Shader()
{
    glDeleteShader(_id);
}

void Shader::attach(GLuint program)
{
    /*
    Možná by to chtělo podporu pro víc programů pro shader
    */
    glAttachShader(program, _id);
}

std::string Shader::log()
{
    return shader_utils::getShaderLog(_id);
}

GLuint Shader::id() const noexcept
{
    return _id;
}

bool Shader::operator==(const Shader &shader) const noexcept
{
    return shader.id() == id();
}