#include "glfw_exception.h"

WindowInitializationError::WindowInitializationError(const std::string &message) : std::runtime_error(message)
{
}

GladLoadError::GladLoadError(const std::string &message) : std::runtime_error(message)
{
}

ShaderCompilationError::ShaderCompilationError(const std::string &message) : std::runtime_error(message)
{
}

ShaderCreationError::ShaderCreationError(const std::string &message) : std::runtime_error(message)
{
}

ProgramCreationError::ProgramCreationError(const std::string &message) : std::runtime_error(message)
{
}

ProgramLinkError::ProgramLinkError(const std::string& message):std::runtime_error(message){
    
}