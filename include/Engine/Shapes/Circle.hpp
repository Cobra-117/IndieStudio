/*
** EPITECH PROJECT, 2021
** sdfghj
** File description:
** jhgfd
*/

#ifndef CICLE
#define CICLE

extern "C" {
    #include "raylib.h"
}

#include <iostream>
#include <string>
#include <cstring>

class IndieCircle
{
    private:
        Vector2 _center;
        int _centerX;
        int _centerY;
        float _radius;
        float _startAngle;
        float _endAngle;
        int _segments;
        int _circleType;
        Color _color1;
        Color _color2;
    public:
        IndieCircle(int, int, float, Color);
        IndieCircle(Vector2, float, float, float, int, Color);
        IndieCircle(int, int, float, Color, Color);
        IndieCircle(const IndieCircle &);
        IndieCircle &operator=(const IndieCircle &);
        ~IndieCircle() = default;
        void IndieDrawCircle(void);
        void IndieDrawCircleLine(void);
        void IndieSetCircleCenter(int, int);
        void IndieSetCircleColor(Color);
        void IndieSetCircleGradient(Color, Color);
        void IndieSetCircleRadius(float);
        Vector2 IndieGetCircleCenter(void);
        Color IndieGetCircleColor(void);
        float IndieGetCircleRadius(void);
};

#endif