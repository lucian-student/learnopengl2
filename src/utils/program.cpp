#include "program.h"
#include "program_utils.h"
#include <glfw_exception.h>
#include <glm/gtc/type_ptr.hpp>

Program::Program()
{
    _id = glCreateProgram();
    if (_id == 0)
        throw ProgramCreationError("Failed to create program!");
}

Program::~Program()
{
    glDeleteProgram(_id);
}

void Program::link()
{
    glLinkProgram(id());
    if (!program_utils::programLinked(id()))
    {
        throw ProgramLinkError("Program link error: " + log() + "!");
    }
}

std::string Program::log()
{
    return program_utils::getProgramLog(id());
}

GLuint Program::id()
{
    return _id;
}

void Program::use()
{
    glUseProgram(_id);
}

void Program::setUniform(const glm::mat4 &value, const std::string &name)
{
    GLint location = glGetUniformLocation(id(), name.c_str());
    if (location == -1)
        throw LocationError("Couldn't find location of " + name +  " uniform!");
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
}

void Program::setUniform(const glm::vec4 &value, const std::string &name)
{
    GLint location = glGetUniformLocation(id(), name.c_str());
    if (location == -1)
        throw LocationError("Couldn't find location of " + name +  " uniform!");
    glUniform4fv(location, 1, glm::value_ptr(value));
}

void Program::setUniform(const glm::vec3 &value, const std::string &name)
{
    GLint location = glGetUniformLocation(id(), name.c_str());
    if (location == -1)
        throw LocationError("Couldn't find location of " + name +  " uniform!");
    glUniform3fv(location, 1, glm::value_ptr(value));
}

void Program::setUniform(float value, const std::string &name)
{
    GLint location = glGetUniformLocation(id(), name.c_str());
    if (location == -1)
        throw LocationError("Couldn't find location of " + name +  " uniform!");
    glUniform1f(location, value);
}

void Program::setUniform(int value, const std::string &name)
{
    GLint location = glGetUniformLocation(id(), name.c_str());
    if (location == -1)
        throw LocationError("Couldn't find location of " + name +  " uniform!");
    glUniform1i(location, value);
}
