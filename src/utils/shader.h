#pragma once
#include <glad/glad.h>
#include <string>

class Shader
{
private:
    GLuint _id;

public:
    Shader() noexcept;
    Shader(GLenum type, const std::string &filename);
    ~Shader();
    void attach(GLuint program);
    std::string log();

    /*
    Davejte is bacháče set potřebuje const comparison operátor
    */
    bool operator==(const Shader& shader) const noexcept;

    GLuint id() const noexcept;
};

template <>
struct std::hash<Shader>
{
    size_t operator()(const Shader &x) const
    {
        return std::hash<GLint>()(x.id());
    }
};
