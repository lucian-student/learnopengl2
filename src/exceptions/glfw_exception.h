#pragma once
#include <stdexcept>
#include <string>

class WindowInitializationError : public std::runtime_error
{
private:
public:
    WindowInitializationError(const std::string &message);
};

class GladLoadError: public std::runtime_error
{
private:
public:
    GladLoadError(const std::string& message);
};