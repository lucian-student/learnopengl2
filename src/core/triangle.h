#pragma once
#include <glm/vec3.hpp>

class Triangle
{
private:
protected:
    glm::vec3 _a;
    glm::vec3 _b;
    glm::vec3 _c;
public:
    Triangle();
    Triangle(const glm::vec3 a, const glm::vec3 &b, const glm::vec3 &c);
    Triangle(const Triangle &triangle);
    Triangle &operator=(const Triangle &triangle);

    ~Triangle();

    float *data();
    const float *data() const;

    glm::vec3 &a();
    glm::vec3 &b();
    glm::vec3 &c();

    const glm::vec3 &a() const;
    const glm::vec3 &b() const;
    const glm::vec3 &c() const;
};
