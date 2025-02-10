#include "program_utils.h"

bool program_utils::programLinked(GLuint program)
{
    GLint status;
    glGetProgramiv(program, GL_LINK_STATUS, &status);
    return status == GL_TRUE;
}

std::string program_utils::getProgramLog(GLuint program)
{
    GLint logLenght;
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLenght);
    GLchar *message = new GLchar[logLenght];
    glGetShaderInfoLog(program, logLenght, NULL, message);
    std::string messageStr(message);
    delete[] message;
    return messageStr;
}