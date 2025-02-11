#pragma once
#include <stdexcept>

class FailedToOpenFileError : public std::runtime_error
{
private:
public:
    FailedToOpenFileError(const std::string& message);
};