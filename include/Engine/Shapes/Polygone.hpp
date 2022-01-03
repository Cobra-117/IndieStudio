/*
** EPITECH PROJECT, 2021
** sdfghjk
** File description:
** jhgfds
*/

#ifndef POLYGONE
#define POLYGONE

extern "C" {
    #include "raylib.h"
}

#include <iostream>
#include <string>
#include <cstring>

class IndiePoly
{
    private:
        Vector2 _center;
        int _sides;
        float _radius;
        float _rotation;
        Color _color;
    public:
        IndiePoly(Vector2, int, float, float, Color);
        ~IndiePoly() = default;
        IndiePoly(const IndiePoly &);
        IndiePoly &operator=(const IndiePoly &);
        void IndieDrawPoly(void);
        void IndieDrawPolyLine(void);
        void IndieSetPolyCenter(Vector2);
        void IndieSetPolySides(int);
        void IndieSetPolyRadius(float);
        void IndieSetPolyRotation(float);
        void IndieSetPolyColor(Color);
};

#endif