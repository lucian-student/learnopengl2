#include "shader_utils.h"
#include <glfw_exception.h>

bool shader_utils::shaderCompiled(GLuint shader)
{
    GLint status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    return status == GL_TRUE;
}

std::string shader_utils::getShaderLog(GLuint shader)
{
    GLint logLenght;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLenght);
    GLchar *message = new GLchar[logLenght];
    glGetShaderInfoLog(shader, logLenght, NULL, message);
    std::string messageStr(message);
    delete[] message;
    return messageStr;
}

GLuint shader_utils::initalizeShader(const GLchar *code, GLenum shaderType)
{
    GLuint shader = glCreateShader(shaderType);
    if (shader == 0)
        throw ShaderCreationError("Nepodařílo se vytvořit shader!");
    glShaderSource(shader, 1, &code, NULL);
    glCompileShader(shader);
    if (!shaderCompiled(shader))
    {
        std::string errorMessage = "Shader error: " + getShaderLog(shader);
        throw ShaderCompilationError(errorMessage);
    }
    return shader;
}