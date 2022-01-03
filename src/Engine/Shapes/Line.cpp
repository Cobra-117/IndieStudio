/*
** EPITECH PROJECT, 2021
** dfghjkl
** File description:
** jhgfd
*/

#include "../../../include/Engine/Shapes/Line.hpp"

IndieLine::IndieLine(Vector2 startPos, Vector2 endPos, float thick, Color color)
{
    _startPos = startPos;
    _endPos = endPos;
    _color = color;
    _thick = thick;
}

IndieLine::IndieLine(const IndieLine &a)
{
    _startPos = a._startPos;
    _endPos = a._endPos;
    _color = a._color;
    _thick = a._thick;
}

IndieLine &IndieLine::operator=(const IndieLine &a)
{
    _startPos = a._startPos;
    _endPos = a._endPos;
    _color = a._color;
    _thick = a._thick;
    return *this;
}

void IndieLine::IndieDrawLine(void)
{
    DrawLineEx(_startPos, _endPos, _thick, _color);
}

void IndieLine::IndieSetLineStartPos(Vector2 pos)
{
    _startPos = pos;
}

void IndieLine::IndieSetLineEndPos(Vector2 pos)
{
    _endPos = pos;
}

void IndieLine::IndieSetLineColor(Color color)
{
    _color = color;
}

void IndieLine::IndieSetLineThickness(float thick)
{
    _thick = thick;
}