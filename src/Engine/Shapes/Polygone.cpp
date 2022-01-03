/*
** EPITECH PROJECT, 2021
** sdfghjkl
** File description:
** kjhgfd
*/

#include "../../../include/Engine/Shapes/Polygone.hpp"

IndiePoly::IndiePoly(Vector2 center, int side, float radius, float rotation, Color color)
{
    _center = center;
    _sides = side;
    _radius = radius;
    _rotation = rotation;
    _color = color;
}

IndiePoly::IndiePoly(const IndiePoly &a)
{
    _center = a._center;
    _sides = a._sides;
    _radius = a._radius;
    _rotation = a._rotation;
    _color = a._color;
}

IndiePoly &IndiePoly::operator=(const IndiePoly &a)
{
    _center = a._center;
    _sides = a._sides;
    _radius = a._radius;
    _rotation = a._rotation;
    _color = a._color;
    return *this;
}

void IndiePoly::IndieDrawPoly(void)
{
    DrawPoly(_center, _sides, _radius, _rotation, _color);
}

void IndiePoly::IndieDrawPolyLine(void)
{
    DrawPolyLines(_center, _sides, _radius, _rotation, _color);
}

void IndiePoly::IndieSetPolyCenter(Vector2 center)
{
    _center = center;
}

void IndiePoly::IndieSetPolySides(int side)
{
    _sides = side;
}

void IndiePoly::IndieSetPolyRadius(float radius)
{
    _radius = radius;
}

void IndiePoly::IndieSetPolyRotation(float rotation)
{
    _rotation = rotation;
}

void IndiePoly::IndieSetPolyColor(Color color)
{
    _color = color;
}