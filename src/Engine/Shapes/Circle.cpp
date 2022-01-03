/*
** EPITECH PROJECT, 2021
** sdfghjk
** File description:
** jhgfd
*/

#include "../../../include/Engine/Shapes/Circle.hpp"

IndieCircle::IndieCircle(int centerX, int centerY, float radius, Color color)
{
    _centerX = centerX;
    _centerY = centerY;
    _radius = radius;
    _color1 = color;
    _circleType = 0;
}

IndieCircle::IndieCircle(Vector2 center, float radius, float startAngle, float endAngle, int segments, Color color)
{
    _center = center;
    _radius = radius;
    _startAngle = startAngle;
    _endAngle = endAngle;
    _segments = segments;
    _color1 = color;
    _circleType = 1;
}

IndieCircle::IndieCircle(int centerX, int centerY, float radius, Color color1, Color color2)
{
    _centerX = centerX;
    _centerY = centerY;
    _radius = radius;
    _color1 = color1;
    _color2 = color2;
    _circleType = 2;
}

IndieCircle::IndieCircle(const IndieCircle &a)
{
    _center = a._center;
    _centerX = a._centerX;
    _centerY = a._centerY;
    _radius = a._radius;
    _startAngle = a._startAngle;
    _endAngle = a._endAngle;
    _segments = a._segments;
    _circleType =  a._circleType;
    _color1 = a._color1;
    _color2 = a._color2;
}

IndieCircle &IndieCircle::operator=(const IndieCircle &a)
{
    _center = a._center;
    _centerX = a._centerX;
    _centerY = a._centerY;
    _radius = a._radius;
    _startAngle = a._startAngle;
    _endAngle = a._endAngle;
    _segments = a._segments;
    _circleType =  a._circleType;
    _color1 = a._color1;
    _color2 = a._color2;
    return *this;
}

void IndieCircle::IndieDrawCircle(void)
{
    if (_circleType == 0)
        DrawCircle(_centerX, _centerY, _radius, _color1);
    else if (_circleType == 1)
        DrawCircleSector(_center, _radius, _startAngle, _endAngle, _segments, _color1);
    else if (_circleType == 2)
        DrawCircleGradient(_centerX, _centerY, _radius, _color1, _color2);
}

void IndieCircle::IndieDrawCircleLine(void)
{
    if (_circleType == 0)
        DrawCircleLines(_centerX, _centerY, _radius, _color1);
    else if (_circleType == 1)
        DrawCircleSectorLines(_center, _radius, _startAngle, _endAngle, _segments, _color1);
    else if (_circleType == 2)
        DrawCircleGradient(_centerX, _centerY, _radius, _color1, _color2);
}

void IndieCircle::IndieSetCircleCenter(int x, int y)
{
    _centerX = x;
    _centerY = y;
}

void IndieCircle::IndieSetCircleColor(Color color)
{
    _color1 = color;
}

void IndieCircle::IndieSetCircleGradient(Color color1, Color color2)
{
    _color1 = color1;
    _color2 = color2;
}

void IndieCircle::IndieSetCircleRadius(float radius)
{
    _radius = radius;
}

Vector2 IndieCircle::IndieGetCircleCenter(void)
{
    return Vector2({ (float)_centerX, (float)_centerY});
}

Color IndieCircle::IndieGetCircleColor(void)
{
    return _color1;
}

float IndieCircle::IndieGetCircleRadius(void)
{
    return _radius;
}