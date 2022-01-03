/*
** EPITECH PROJECT, 2021
** sdfghjk
** File description:
** jhgfd
*/

#ifndef RECTANGLE
#define RECTANGLE

extern "C" {
    #include "raylib.h"
}

#include <iostream>
#include <string>
#include <cstring>
#include "../Textures/Textures.hpp"
#include "../Text/Text.hpp"

class IndieRectangle
{
    private:
        int _posX;
        int _posY;
        int _width;
        int _height;
        Color _color1;
        Color _color2;
        Rectangle _rec;
        int _lineThick;
        float _roundness;
        int _segments;
        int _recType;
        int _gradientType;
    public:
        IndieRectangle(int, int, int, int, Color);
        IndieRectangle(IndieTextures);
        IndieRectangle(IndieText);
        IndieRectangle(Vector2, int, int, Color, Color, int);
        IndieRectangle(Rectangle, float, int, Color);
        IndieRectangle(const IndieRectangle &);
        IndieRectangle &operator=(const IndieRectangle &);
        ~IndieRectangle() = default;
        void IndieDrawRectangle(void);
        void IndieDrawRectangleLine(void);
        void IndieSetRectanglePos(int, int);
        void IndieSetRectangleWidthHeight(int, int);
        void IndieSetRectangleColor(Color);
        void IndieSetRectangleGradient(Color, Color);
        void IndieSetRectangleLineThickness(int);
        std::pair<int, int> IndieGetRectanglePos(void);
        std::pair<int, int> IndieGetRectangleWidthHeight(void);
        Color IndieGetRectangleColor(void);
        int IndieGetRectangleLineThickness(void);
        Rectangle IndieGetRectangleRec(void);
};

#endif