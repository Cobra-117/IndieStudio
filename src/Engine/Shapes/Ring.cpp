/*
** EPITECH PROJECT, 2021
** sdfghj
** File description:
** hgfd
*/

#include "../../../include/Engine/Shapes/Ring.hpp"

IndieRing::IndieRing(Vector2 center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, Color color)
{
    _center = center;
    _innerRadius = innerRadius;
    _outerRadius = outerRadius;
    _startAngle = startAngle;
    _endAngle = endAngle;
    _segments = segments;
    _color = color;
}

IndieRing::IndieRing(const IndieRing &a)
{
    _center = a._center;
    _innerRadius = a._innerRadius;
    _outerRadius = a._outerRadius;
    _startAngle = a._startAngle;
    _endAngle = a._endAngle;
    _segments = a._segments;
    _color = a._color;
}

IndieRing &IndieRing::operator=(const IndieRing &a)
{
    _center = a._center;
    _innerRadius = a._innerRadius;
    _outerRadius = a._outerRadius;
    _startAngle = a._startAngle;
    _endAngle = a._endAngle;
    _segments = a._segments;
    _color = a._color;
    return *this;
}

void IndieRing::IndieDrawRing(void)
{
    DrawRing(_center, _innerRadius, _outerRadius, _startAngle, _endAngle, _segments, _color);
}

void IndieRing::IndieDrawRingLine(void)
{
    DrawRingLines(_center, _innerRadius, _outerRadius, _startAngle, _endAngle, _segments, _color);
}

void IndieRing::IndieSetRingCenter(Vector2 center)
{
    _center = center;
}

void IndieRing::IndieSetRingInnerRadius(float radius)
{
    _innerRadius = radius;
}

void IndieRing::IndieSetRingOuterRadius(float radius)
{
    _outerRadius = radius;
}

void IndieRing::IndieSetRingStartAngle(float angle)
{
    _startAngle = angle;
}

void IndieRing::IndieSetRingEndAngle(float angle)
{
    _endAngle = angle;
}

void IndieRing::IndieSetRingSegments(int segment)
{
    _segments = segment;
}

void IndieRing::IndieSetRingColor(Color color)
{
    _color = color;
}