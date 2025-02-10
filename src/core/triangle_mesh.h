#pragma once
#include <glad/glad.h>
#include "triangle.h"

class TriangleMesh
{
private:
    static constexpr const char *VERTEX_SHADER = "#version 330\n"
                                                 "layout (location = 0) in vec3 vertexPosition;\n"
                                                 "\n"
                                                 "void main()\n"
                                                 "{\n"
                                                 "gl_Position = vec4(vertexPosition,1.0); \n"
                                                 "}\n";
    static constexpr const char *FRAGMENT_SHADER = "#version 330\n"
                                                   "out vec4 fragColor;\n"
                                                   "\n"
                                                   "void main()\n"
                                                   "{\n"
                                                   " fragColor = vec4(0.1,0.2,0.3,1.0);\n"
                                                   "}\n";

    const static int N_BUFFERS = 1;
    Triangle _triangle;
    GLuint _bufferId;
    GLuint _vertexShaderId;
    GLuint _fragmentShaderId;
    GLuint _programId;

    void init();

public:
    void draw();

    TriangleMesh();
    TriangleMesh(const Triangle &triangle);
    ~TriangleMesh();
};