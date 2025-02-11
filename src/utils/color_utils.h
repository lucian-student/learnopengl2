#pragma once
#include <stdexcept>
#include <string>

class RGBColor
{
private:
    static const int MAX_COLOR = 255;
    static const int MIN_COLOR = 0;

    int _red;
    int _green;
    int _blue;
    float _alpha;

    bool isValid(int x);

public:
    RGBColor();
    RGBColor(int red, int green, int blue);

    RGBColor(const RGBColor &color);
    RGBColor &operator=(const RGBColor &color);

    ~RGBColor();

    int red();
    int blue();
    int green();

    float alpha();

    float clampedRed();
    float clampedBlue();
    float clampedGreen();
};

class InvalidColorError : public std::runtime_error
{
private:
public:
    InvalidColorError(const std::string &message);
};
