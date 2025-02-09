#include "triangle_mesh.h"

const char *TriangleMesh::VERTEX_SHADER = "#version 330 core \n"
                                          "layout (location = 0) in vec3 aPos; \n"
                                          "\n"
                                          "void main()\n"
                                          "{\n"
                                          "gl_position = vec4(aPos.x,aPos.y,aPos.z,1.0); \n"
                                          "}\n";

TriangleMesh::TriangleMesh() : _triangle()
{
    glGenBuffers(TriangleMesh::N_BUFFERS, &_id);
}

TriangleMesh::TriangleMesh(const Triangle &triangle) : _triangle(triangle)
{
    glGenBuffers(TriangleMesh::N_BUFFERS, &_id);
}

void TriangleMesh::draw()
{

    glBindBuffer(GL_ARRAY_BUFFER, _id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Triangle), _triangle.data(), GL_STATIC_DRAW);
}

TriangleMesh::~TriangleMesh()
{
    glDeleteBuffers(TriangleMesh::N_BUFFERS, &_id);
}