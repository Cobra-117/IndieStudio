/*
** EPITECH PROJECT, 2021
** sdfghjkl
** File description:
** kjhgfds
*/

#include "../../../include/Engine/Shapes/Triangle.hpp"

IndieTriangle::IndieTriangle(Vector2 v1, Vector2 v2, Vector2 v3, Color color)
{
    _v1 = v1;
    _v2 = v2;
    _v3 = v3;
    _color = color;
}

void IndieTriangle::IndieDrawTriangle(void)
{
    DrawTriangle(_v1, _v2, _v3, _color);
}

void IndieTriangle::IndieDrawTriangleLine(void)
{
    DrawTriangleLines(_v1, _v2, _v3, _color);
}

void IndieTriangle::IndieSetTriangleColor(Color color)
{
    _color = color;
}

void IndieTriangle::IndieSetTriangleV1(Vector2 v)
{
    _v1 = v;
}

void IndieTriangle::IndieSetTriangleV2(Vector2 v)
{
    _v2 = v;
}

void IndieTriangle::IndieSetTriangleV3(Vector2 v)
{
    _v3 = v;
}

Color IndieTriangle::IndieGetTriangleColor(void)
{
    return _color;
}

Vector2 IndieTriangle::IndieGetTriangleV1(void)
{
    return _v1;
}

Vector2 IndieTriangle::IndieGetTriangleV2(void)
{
    return _v2;
}

Vector2 IndieTriangle::IndieGetTriangleV3(void)
{
    return _v3;
}