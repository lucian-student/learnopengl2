#pragma once
#include "object3D.h"
#include <vertex_array_object.h>
#include <buffer_object.h>
#include <program.h>
#include <texture.h>

class BoxMesh : public Object3D
{
private:
    float _side;
    VertexArrayObject _vertexArray;
    BufferObject<float> _vertextBufferObject;
    BufferObject<unsigned int> _elementBufferObject;
    Program _program;
    Texture _texture;
    Texture _texture2;

    std::vector<float> getData();
    std::vector<unsigned int> indices();
public:
    BoxMesh(float side);
    ~BoxMesh();
    void draw() override;
};