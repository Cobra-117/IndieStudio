/*
** EPITECH PROJECT, 2021
** sdfghj
** File description:
** kjhgfd
*/

#include "../../../include/Engine/Shapes/Rectangle.hpp"

IndieRectangle::IndieRectangle(int posX, int posY, int width, int height, Color color)
{
    _posX = posX;
    _posY = posY;
    _width = width;
    _height = height;
    _rec = Rectangle({ (float)posX, (float)posY, (float)width, (float)height });
    _color1 = color;
    _recType = 0;
}

IndieRectangle::IndieRectangle(IndieTextures texture)
{
    _posX = texture._posX;
    _posY = texture._posY;
    _width = texture.IndieGetTextureWidth() * texture._scale;
    _height = texture.IndieGetTextureHeight() * texture._scale;
    _rec = Rectangle({ (float)_posX, (float)_posY, (float)_width, (float)_height });
    _color1 = texture.IndieGetTextureColor();
    _recType = 0;
}

IndieRectangle::IndieRectangle(IndieText text)
{
    _posX = text.IndieGetTextPosition().x;
    _posY = text.IndieGetTextPosition().y;
    _width = MeasureText(text.IndieGetText().c_str(), text.IndieGetTextFontSize());
    _height = text.IndieGetTextFontSize();
    _rec = Rectangle({ (float)_posX, (float)_posY, (float)_width, (float)_height });
    _color1 = text.IndieGetTextColor();
    _recType = 0;
}

IndieRectangle::IndieRectangle(Vector2 pos, int width, int height, Color color1, Color color2, int gradientType)
{
    _posX = pos.x;
    _posY = pos.y;
    _width = width;
    _height = height;
    _rec = Rectangle({ (float)_posX, (float)_posY, (float)width, (float)height });
    _color1 = color1;
    _color2 = color2;
    _gradientType = gradientType;
    _recType = 1;
}

IndieRectangle::IndieRectangle(Rectangle rec, float roundness, int segments, Color color)
{
    _rec = rec;
    _roundness = roundness;
    _segments = segments;
    _color1 = color;
    _lineThick = 1;
    _recType = 2;
}

IndieRectangle::IndieRectangle(const IndieRectangle &a)
{
    _posX = a._posX;
    _posY = a._posY;
    _width = a._width;
    _height = a._height;
    _color1 = a._color1;
    _color2 = a._color2;
    _rec = a._rec;
    _lineThick = a._lineThick;
    _roundness = a._roundness;
    _segments = a._segments;
    _recType = a._recType;
    _gradientType = a._gradientType;
}

IndieRectangle &IndieRectangle::operator=(const IndieRectangle &a)
{
    _posX = a._posX;
    _posY = a._posY;
    _width = a._width;
    _height = a._height;
    _color1 = a._color1;
    _color2 = a._color2;
    _rec = a._rec;
    _lineThick = a._lineThick;
    _roundness = a._roundness;
    _segments = a._segments;
    _recType = a._recType;
    _gradientType = a._gradientType;
    return *this;
}

void IndieRectangle::IndieDrawRectangle(void)
{
    if (_recType == 0)
        DrawRectangle(_posX, _posY, _width, _height, _color1);
    else if (_recType == 1) {
        if (_gradientType == 0)
            DrawRectangleGradientV(_posX, _posY, _width, _height, _color1, _color2);
        else if (_gradientType == 0)
            DrawRectangleGradientH(_posX, _posY, _width, _height, _color1, _color2);
        }
    else if (_recType == 2)
        DrawRectangleRounded(_rec, _roundness, _segments, _color1);
}

void IndieRectangle::IndieDrawRectangleLine(void)
{
    if (_recType == 0)
        DrawRectangleLines(_posX, _posY, _width, _height, _color1);
    else if (_recType == 1) {
        if (_gradientType == 0)
            DrawRectangleGradientV(_posX, _posY, _width, _height, _color1, _color2);
        else if (_gradientType == 0)
            DrawRectangleGradientH(_posX, _posY, _width, _height, _color1, _color2);
        }
    else if (_recType == 2)
        DrawRectangleRoundedLines(_rec, _roundness, _segments, _lineThick, _color1);
}

void IndieRectangle::IndieSetRectanglePos(int x, int y)
{
    _posX = x;
    _posY = y;
    _rec.x = x;
    _rec.y = y;
}

void IndieRectangle::IndieSetRectangleWidthHeight(int width, int height)
{
    _width = width;
    _height = height;
    _rec.width = width;
    _rec.height = height;
}

void IndieRectangle::IndieSetRectangleColor(Color color)
{
    _color1 = color;
}

void IndieRectangle::IndieSetRectangleGradient(Color color1, Color color2)
{
    _color1 = color1;
    _color2 = color2;
}

void IndieRectangle::IndieSetRectangleLineThickness(int thick)
{
    _lineThick = thick;
}

std::pair<int, int> IndieRectangle::IndieGetRectanglePos(void)
{
    return std::make_pair(_posX, _posY);
}

std::pair<int, int> IndieRectangle::IndieGetRectangleWidthHeight(void)
{
    return std::make_pair(_width, _height);
}

Color IndieRectangle::IndieGetRectangleColor(void)
{
    return _color1;
}

int IndieRectangle::IndieGetRectangleLineThickness(void)
{
    return _lineThick;
}

Rectangle IndieRectangle::IndieGetRectangleRec(void)
{
    return _rec;
}