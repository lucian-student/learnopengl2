#pragma once
#include <unordered_set>
#include <glad/glad.h>
#include "shader.h"

class Program
{
private:
    std::unordered_set<Shader> _shaders;
    GLuint _id;

public:
    Program();
    ~Program();

    template <typename... Ts>
    void emplace_shader(Ts &&...values)
    {
        Shader shader(std::forward<Ts>(values)...);
        shader.attach(id());
        _shaders.insert(std::move(shader));
    }
    void link();
    std::string log();
    void setUniform(float value,const std::string& name);

    GLuint id();
    void use();
};