#pragma once
#include <glad/glad.h>
#include "triangle.h"

class TriangleMesh
{
private:
    const static char *VERTEX_SHADER;
    const static int N_BUFFERS = 1;

    Triangle _triangle;
    GLuint _id;
public:
    void draw();

    TriangleMesh();
    TriangleMesh(const Triangle &triangle);
    ~TriangleMesh();
};