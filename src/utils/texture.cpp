#include "texture.h"
#include <file_exception.h>
#include <glfw_exception.h>
#include "utils.h"
#include <filesystem>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

Texture::Texture(const std::string &filename,GLenum internaleFormat,GLenum format)
{
    std::filesystem::path executablePath(utils::executablePath());
    std::filesystem::path texturePath = executablePath.parent_path().parent_path().parent_path().parent_path();
    texturePath /= "images";
    texturePath /= filename;

    stbi_set_flip_vertically_on_load(true);  
    glGenTextures(1, &_id);
    if (_id == 0)
    {
        throw BufferGenError("Failed to generate texture id!");
    }
    glBindTexture(GL_TEXTURE_2D, _id);

    std::string texturePathStr = texturePath.string();
    unsigned char *image = stbi_load(texturePathStr.c_str(), &_width, &_height, &_channels, 0);
    if (image == NULL)
    {
        glDeleteTextures(1, &_id);
        throw FileReadError("Failed to read texture file!");
    }
    glTexImage2D(GL_TEXTURE_2D, 0, internaleFormat, _width, _height, 0, format, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(image);
}

Texture::~Texture()
{
    glDeleteTextures(1, &_id);
}

void Texture::bind(GLenum textureUnit)
{
    glActiveTexture(textureUnit);
    glBindTexture(GL_TEXTURE_2D, id());
}

GLuint Texture::id()
{
    return _id;
}