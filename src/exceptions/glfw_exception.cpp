#include "glfw_exception.h"

WindowInitializationError::WindowInitializationError(const std::string &message) : std::runtime_error(message)
{
}

GladLoadError::GladLoadError(const std::string &message) : std::runtime_error(message)
{
}