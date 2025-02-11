#include "program.h"
#include "program_utils.h"
#include <glfw_exception.h>

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