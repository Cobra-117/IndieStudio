/*
** EPITECH PROJECT, 2021
** sdfghjk
** File description:
** jhgfds
*/

#include "../../../include/Engine/Shapes/Ellipse.hpp"

IndieEllipse::IndieEllipse(int centerX, int centerY, float radiusH, float radiusV, Color color)
{
    _centerX = centerX;
    _centerY = centerY;
    _radiusH = radiusH;
    _radiusV = radiusV;
    _color = color;
}

IndieEllipse::IndieEllipse(const IndieEllipse &a)
{
    _centerX = a._centerX;
    _centerY = a._centerY;
    _radiusH = a._radiusH;
    _radiusV = a._radiusV;
    _color = a._color;
}

IndieEllipse &IndieEllipse::operator=(const IndieEllipse &a)
{
    _centerX = a._centerX;
    _centerY = a._centerY;
    _radiusH = a._radiusH;
    _radiusV = a._radiusV;
    _color = a._color;
    return *this;
}

void IndieEllipse::IndieDrawEllipse(void)
{
    DrawEllipse(_centerX, _centerY, _radiusH, _radiusV, _color);
}

void IndieEllipse::IndieDrawEllipseLine(void)
{
    DrawEllipseLines(_centerX, _centerY, _radiusH, _radiusV, _color);
}

void IndieEllipse::IndieSetEllipsePos(int x, int y)
{
    _centerX = x;
    _centerY = y;
}

void IndieEllipse::IndieSetEllipseRadius(float h, float v)
{
    _radiusH = h;
    _radiusV = v;
}

void IndieEllipse::IndieSetEllipseColor(Color color)
{
    _color = color;
}