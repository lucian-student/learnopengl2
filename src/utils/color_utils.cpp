#include "color_utils.h"

bool RGBColor::isValid(int x)
{
    return x <= RGBColor::MAX_COLOR && x >= RGBColor::MIN_COLOR;
}

RGBColor::~RGBColor()
{
}

RGBColor::RGBColor() : _red(0), _green(0), _blue(0), _alpha(0.0)
{
}

RGBColor::RGBColor(int red, int green, int blue)
{
    if (!isValid(red))
        throw InvalidColorError("Červená je mimo rozsah 0-255!");
    if (!isValid(green))
        throw InvalidColorError("Zelená je mimo rozsah 0-255!");
    if (!isValid(blue))
        throw InvalidColorError("Modrá je mimo rozsah 0-255!");
    _red = red;
    _green = green;
    _blue = blue;
    _alpha = 0.0;
}

RGBColor::RGBColor(const RGBColor &color) : _red(color._red), _green(color._green), _blue(color._blue), _alpha(color._alpha)
{
}

RGBColor &RGBColor::operator=(const RGBColor &color)
{
    _red = color._red;
    _green = color._green;
    _blue = color._blue;
    _alpha = color._alpha;

    return *this;
}

int RGBColor::red()
{
    return _red;
}

int RGBColor::blue()
{
    return _blue;
}

int RGBColor::green()
{
    return _green;
}

float RGBColor::alpha()
{
    return _alpha;
}

float RGBColor::clampedRed()
{
    return static_cast<float>(_red) / 255.0;
}

float RGBColor::clampedGreen()
{
    return static_cast<float>(_green) / 255.0;
}

float RGBColor::clampedBlue()
{
    return static_cast<float>(_blue) / 255.0;
}

InvalidColorError::InvalidColorError(const std::string &message) : std::runtime_error(message)
{
}