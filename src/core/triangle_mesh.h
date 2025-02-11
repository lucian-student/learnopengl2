#pragma once
#include <glad/glad.h>
#include "triangle.h"
#include <color_utils.h>
#include <vector>
#include <shader.h>
#include <vertex_array_object.h>
#include <vertex_buffer_object.h>

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
    GLuint _arrayId;
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

class IndexedTriangleMesh
{
    /*
    Bude mít stejnou funkcionalitu jako triangle Mesh, ale použije EBO
    */
private:
    constexpr static const char *VERTEX_SHADER = "#version 330\n"
                                                 "layout (location=0) in vec3 vertexPosition; \n"
                                                 "\n"
                                                 "void main()\n"
                                                 "{\n"
                                                 "  gl_Position = vec4(vertexPosition,1.0);"
                                                 "}\n";

    constexpr static const char *FRAGMENT_SHADER = "#version 330\n"
                                                   "uniform vec4 inputColor = vec4(0.0,0.0,0.0,1.0);\n"
                                                   "out vec4 fragmentColor;\n"
                                                   "\n"
                                                   "void main()\n"
                                                   "{\n"
                                                   " fragmentColor = inputColor;"
                                                   "\n}";

    constexpr static const int VERTICES[3] = {1, 2, 3};

    Triangle _triangle;
    RGBColor _color;
    GLuint _vertexArray;
    GLuint _vertexBuffer;
    GLuint _elementBuffer;
    GLuint _program;

    GLuint _vertexShader;
    GLuint _fragmentShader;

    void init();

public:
    IndexedTriangleMesh();
    IndexedTriangleMesh(const Triangle &triangle, const RGBColor &color);
    ~IndexedTriangleMesh();

    void draw();
};

class MultiColorTriangleMesh
{
private:
    Shader _vertexShader;
    Shader _fragmentShader;

    // color + triangle
    constexpr static int SIZE_OF_BUFFER = sizeof(Triangle) + (12 * sizeof(float));

    Triangle _triangle;
    RGBColor _a;
    RGBColor _b;
    RGBColor _c;

    VertexArrayObject _vertexArray;
    VertexBufferObject _bufferObject;
    GLuint _program;
    std::vector<float> buildBuffer();

public:
    MultiColorTriangleMesh(const Triangle &triangle, const RGBColor &a, const RGBColor &b, const RGBColor &c);
    ~MultiColorTriangleMesh();
    void draw();
};