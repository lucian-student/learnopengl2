#pragma once
#include <stdexcept>
#include <string>

class WindowInitializationError : public std::runtime_error
{
private:
public:
    WindowInitializationError(const std::string &message);
};

class GladLoadError : public std::runtime_error
{
private:
public:
    GladLoadError(const std::string &message);
};

class ShaderCompilationError : public std::runtime_error
{
private:
public:
    ShaderCompilationError(const std::string &message);
};

/*
Používám pro chyby, které nastaly při volání glCreateShader
*/
class ShaderCreationError : public std::runtime_error
{
private:
public:
    ShaderCreationError(const std::string &message);
};

/*
Používám pro chyby, které nastaly při volání glCreateProgram
*/
class ProgramCreationError : public std::runtime_error
{
private:
public:
    ProgramCreationError(const std::string &message);
};

class ProgramLinkError : public std::runtime_error
{
private:
public:
    ProgramLinkError(const std::string &message);
};

class BufferGenError : public std::runtime_error
{
private:
public:
    BufferGenError(const std::string &message);
};

class LocationError: public std::runtime_error{
    private:
    public:
        LocationError(const std::string& message);
};