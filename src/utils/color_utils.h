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
    double _alpha;

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

    double alpha();

    double clampedRed();
    double clampedBlue();
    double clampedGreen();
};

class InvalidColorError : public std::runtime_error
{
private:
public:
    InvalidColorError(const std::string &message);
};
