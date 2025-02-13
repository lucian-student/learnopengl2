#pragma once
#include <glm/vec3.hpp>
#include <program.h>
#include <vertex_array_object.h>
#include <buffer_object.h>
#include <texture.h>
#include <vector>

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

    std::vector<float> getData();
    std::vector<unsigned int> indices();
public:
    SquareMesh(float width);
    ~SquareMesh();

    void draw();
};