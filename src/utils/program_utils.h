#pragma once
#include <glad/glad.h>
#include <string>

namespace program_utils
{
    bool programLinked(GLuint program);

    std::string getProgramLog(GLuint program);
}