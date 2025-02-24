#pragma once
#include "buffer_geometry.h"

class BoxGeometry : public BufferGeometry
{
private:
    float _side;

    std::vector<float> getData(float side);
    std::vector<unsigned int> indices();
public:
    BoxGeometry(float side);
    ~BoxGeometry();
};