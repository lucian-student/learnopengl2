#include "triangle_mesh.h"
#include <iostream>
#include <filesystem>
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
    // init array
    glGenVertexArrays(1, &_arrayId);
    glBindVertexArray(_arrayId);
    // init buffers
    glGenBuffers(TriangleMesh::N_BUFFERS, &_bufferId);
    glBindBuffer(GL_ARRAY_BUFFER, _bufferId);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Triangle), _triangle.data(), GL_STATIC_DRAW);
    // konfigurace VAO
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
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
}

void TriangleMesh::draw()
{
    // fill buffers
    glBindVertexArray(_arrayId);
    glUseProgram(_programId);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
    // draw
}

TriangleMesh::~TriangleMesh()
{
    glDeleteVertexArrays(1, &_arrayId);
    glDeleteBuffers(TriangleMesh::N_BUFFERS, &_bufferId);
    glDeleteShader(_vertexShaderId);
    glDeleteShader(_fragmentShaderId);
    glDeleteProgram(_programId);
}

IndexedTriangleMesh::IndexedTriangleMesh() : _triangle(), _color()
{
    init();
}

IndexedTriangleMesh::IndexedTriangleMesh(const Triangle &triangle, const RGBColor &color) : _triangle(triangle), _color(color)
{
    init();
}

void IndexedTriangleMesh::init()
{
    glGenVertexArrays(1, &_vertexArray);
    glBindVertexArray(_vertexArray);

    glGenBuffers(1, &_vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Triangle), _triangle.data(), GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);

    glGenBuffers(1, &_elementBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _elementBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * 3, IndexedTriangleMesh::VERTICES, GL_STATIC_DRAW);

    _vertexShader = shader_utils::initalizeShader(IndexedTriangleMesh::VERTEX_SHADER, GL_VERTEX_SHADER);
    _fragmentShader = shader_utils::initalizeShader(IndexedTriangleMesh::FRAGMENT_SHADER, GL_FRAGMENT_SHADER);

    _program = glCreateProgram();
    if (_program == 0)
        throw ProgramCreationError("Nepodařilo se vytvořit program");
    glAttachShader(_program, _vertexShader);
    glAttachShader(_program, _fragmentShader);
    glLinkProgram(_program);
    if (!program_utils::programLinked(_program))
    {
        std::string errorMessage = "Linkování progragmu selhalo: " + program_utils::getProgramLog(_program);
        throw ProgramLinkError(errorMessage);
    }
}

IndexedTriangleMesh::~IndexedTriangleMesh()
{
    glDeleteShader(_vertexShader);
    glDeleteShader(_fragmentShader);
    glDeleteProgram(_program);
    glDeleteBuffers(1, &_vertexBuffer);
    glDeleteBuffers(1, &_elementBuffer);
    glDeleteVertexArrays(1, &_vertexArray);
}

void IndexedTriangleMesh::draw()
{
    glBindVertexArray(_vertexArray);
    glUseProgram(_program);
    GLint colorLocation = glGetUniformLocation(_program, "inputColor");
    glUniform4f(colorLocation, _color.clampedRed(), _color.clampedGreen(), _color.clampedBlue(), _color.alpha());
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}

std::vector<float> MultiColorTriangleMesh::buildBuffer()
{
    std::vector<float> buffer = {
        _triangle.a()[0],
        _triangle.a()[1],
        _triangle.a()[2],
        _a.clampedRed(),
        _a.clampedGreen(),
        _a.clampedBlue(),
        _a.alpha(),
        _triangle.b()[0],
        _triangle.b()[1],
        _triangle.b()[2],
        _b.clampedRed(),
        _b.clampedGreen(),
        _b.clampedBlue(),
        _b.alpha(),
        _triangle.c()[0],
        _triangle.c()[1],
        _triangle.c()[2],
        _c.clampedRed(),
        _c.clampedGreen(),
        _c.clampedBlue(),
        _c.alpha(),
    };
    return buffer;
}

MultiColorTriangleMesh::MultiColorTriangleMesh(
    const Triangle &triangle,
    const RGBColor &a,
    const RGBColor &b,
    const RGBColor &c) : _triangle(triangle),
                         _a(a),
                         _b(b),
                         _c(c),
                         _vertexArray(),
                         _bufferObject(buildBuffer(), GL_STATIC_DRAW),
                         _program()
{
    _vertexArray.bind();

    _bufferObject.bind();
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), reinterpret_cast<void *>(0));
    //glEnableVertexAttribArray(1);
    //glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), reinterpret_cast<void *>(3 * sizeof(float)));

    _program.emplace_shader(GL_VERTEX_SHADER, "multi_color_triangle\\position_color.vert");
    _program.emplace_shader(GL_FRAGMENT_SHADER, "multi_color_triangle\\multi_color_triangle.frag");
    _program.link();
    _vertexArray.unbind();
}

void MultiColorTriangleMesh::draw()
{
    _program.use();
    //_program.setUniform(0.5, "offset");
    _vertexArray.bind();
    glDrawArrays(GL_TRIANGLES, 0, 3);
    _vertexArray.unbind();
}

MultiColorTriangleMesh::~MultiColorTriangleMesh()
{
}