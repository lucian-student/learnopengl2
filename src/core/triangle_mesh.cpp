#include "triangle_mesh.h"
#include <glfw_exception.h>
#include <shader_utils.h>
#include <program_utils.h>

TriangleMesh::TriangleMesh() : _triangle()
{
    init();
}

TriangleMesh::TriangleMesh(const Triangle &triangle) : _triangle(triangle)
{
    init();
}

void TriangleMesh::init()
{
    // init buffers
    glGenBuffers(TriangleMesh::N_BUFFERS, &_bufferId);
    glBindBuffer(GL_ARRAY_BUFFER, _bufferId);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Triangle), _triangle.data(), GL_STATIC_DRAW);
    // init shaders
    _vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
    if (_vertexShaderId == 0)
        throw ShaderCreationError("Nepodařilo se vytvořit vertex shader!");
    glShaderSource(_vertexShaderId, 1, &TriangleMesh::VERTEX_SHADER, NULL);
    glCompileShader(_vertexShaderId);
    if (!shader_utils::shaderCompiled(_vertexShaderId))
        throw ShaderCompilationError(shader_utils::getShaderLog(_vertexShaderId));

    _fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
    if (_fragmentShaderId == 0)
        throw ShaderCreationError("Nepodařilo se vytvořit fragment shader!");
    glShaderSource(_fragmentShaderId, 1, &TriangleMesh::FRAGMENT_SHADER, NULL);
    glCompileShader(_fragmentShaderId);
    if (!shader_utils::shaderCompiled(_fragmentShaderId))
        throw ShaderCompilationError(shader_utils::getShaderLog(_fragmentShaderId));
    // setup program
    _programId = glCreateProgram();
    if (_programId == 0)
        throw ProgramCreationError("Nepodařílo se vytvořit program!");
    glAttachShader(_programId, _vertexShaderId);
    glAttachShader(_programId, _fragmentShaderId);
    glLinkProgram(_programId);
    if (!program_utils::programLinked(_programId))
        throw ProgramLinkError(program_utils::getProgramLog(_programId));
    glUseProgram(_programId);
}

void TriangleMesh::draw()
{
    // fill buffers
    // draw
}

TriangleMesh::~TriangleMesh()
{
    glDeleteBuffers(TriangleMesh::N_BUFFERS, &_bufferId);
    glDeleteShader(_vertexShaderId);
    glDeleteProgram(_programId);
}