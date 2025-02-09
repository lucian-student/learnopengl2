#include "triangle.h"

Triangle::Triangle() : _a(0, 0, 0), _b(0, 0, 0), _c(0, 0, 0)
{
}

Triangle::Triangle(const glm::vec3 a, const glm::vec3 &b, const glm::vec3 &c) : _a(a), _b(b), _c(c)
{
}

Triangle::Triangle(const Triangle &triangle) : _a(triangle._a), _b(triangle._b), _c(triangle._c)
{
}

Triangle &Triangle::operator=(const Triangle &triangle)
{
    _a = triangle._a;
    _b = triangle._b;
    _c = triangle._c;
    return *this;
}

Triangle::~Triangle()
{
}

glm::vec3 &Triangle::a() { return _a; };
glm::vec3 &Triangle::b() { return _b; };
glm::vec3 &Triangle::c() { return _c; };

const glm::vec3 &Triangle::a() const { return _a; };
const glm::vec3 &Triangle::b() const { return _b; };
const glm::vec3 &Triangle::c() const { return _c; };

float *Triangle::data()
{
    return reinterpret_cast<float *>(this);
}

const float *Triangle::data() const
{
    return reinterpret_cast<const float *>(this);
}