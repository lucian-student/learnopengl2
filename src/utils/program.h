#pragma once
#include <unordered_set>
#include <glad/glad.h>
#include "shader.h"
#include <glm/glm.hpp>

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

    void setUniform(const glm::mat4& value,const std::string &name);
    void setUniform(const glm::vec4& value,const std::string&name);
    void setUniform(const glm::vec3& value,const std::string&name);
    void setUniform(float value,const std::string& name);
    void setUniform(int value,const std::string& name);

    GLuint id();
    void use();
};