#include "file_exception.h"

FailedToOpenFileError::FailedToOpenFileError(const std::string &message) : std::runtime_error(message)
{
}

FileReadError::FileReadError(const std::string &message) : std::runtime_error(message)
{
}