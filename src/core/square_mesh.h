#pragma once
#include <program.h>
#include <vertex_array_object.h>
#include <buffer_object.h>
#include <texture.h>
#include <vector>
#include <glm/glm.hpp>

class SquareMesh
{
private:
    
    float _width;
    VertexArrayObject _vertexArray;
    BufferObject<float> _vertextBufferObject;
    BufferObject<unsigned int> _elementBufferObject;
    Program _program;
    Texture _texture;
    Texture _texture2;

    glm::mat4 _transform;

    std::vector<float> getData();
    std::vector<unsigned int> indices();

public:
    SquareMesh(float width);
    ~SquareMesh();

    void draw();

    void transformAppend(const glm::mat4 &matrix);
    void transformPrepend(const glm::mat4 &matrix);

    const glm::mat4& currentTransform()const;

    void rotateZ(float radians);
};