#include "shader_utils.h"

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