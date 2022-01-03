/*
** EPITECH PROJECT, 2021
** sdfghj
** File description:
** jhgfds
*/

#ifndef LINE
#define LINE

extern "C" {
    #include "raylib.h"
}

#include <iostream>
#include <string>
#include <cstring>

class IndieLine
{
    private:
        Vector2 _startPos;
        Vector2 _endPos;
        Color _color;
        float _thick;

    public:
        IndieLine(Vector2, Vector2, float, Color);
        ~IndieLine() = default;
        IndieLine(const IndieLine &);
        IndieLine &operator=(const IndieLine &);
        void IndieDrawLine(void);
        void IndieSetLineStartPos(Vector2);
        void IndieSetLineEndPos(Vector2);
        void IndieSetLineColor(Color);
        void IndieSetLineThickness(float);
};

#endif