/*
** EPITECH PROJECT, 2021
** sdfghjk
** File description:
** kjhgfd
*/

#ifndef RING
#define RING

extern "C" {
    #include "raylib.h"
}

#include <iostream>
#include <string>
#include <cstring>

class IndieRing
{
    private:
        Vector2 _center;
        float _innerRadius;
        float _outerRadius;
        float _startAngle;
        float _endAngle;
        int _segments;
        Color _color;

    public:
        IndieRing(Vector2, float, float, float, float, int, Color);
        ~IndieRing() = default;
        IndieRing(const IndieRing &);
        IndieRing &operator=(const IndieRing &);
        void IndieDrawRing(void);
        void IndieDrawRingLine(void);
        void IndieSetRingCenter(Vector2);
        void IndieSetRingInnerRadius(float);
        void IndieSetRingOuterRadius(float);
        void IndieSetRingStartAngle(float);
        void IndieSetRingEndAngle(float);
        void IndieSetRingSegments(int);
        void IndieSetRingColor(Color);
};

#endif