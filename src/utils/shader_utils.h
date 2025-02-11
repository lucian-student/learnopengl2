#pragma once
#include <string>
#include <glad/glad.h>

namespace shader_utils
{
    bool shaderCompiled(GLuint shader);

    std::string getShaderLog(GLuint shader);

    GLuint initalizeShader(const GLchar* code,GLenum shaderType);
}