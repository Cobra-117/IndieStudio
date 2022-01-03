/*
** EPITECH PROJECT, 2021
** sdfghj
** File description:
** jhgf
*/

#ifndef ELLIPSE
#define ELLIPSE

extern "C" {
    #include "raylib.h"
}

#include <iostream>
#include <string>
#include <cstring>

class IndieEllipse
{
    private:
        int _centerX;
        int _centerY;
        float _radiusH;
        float _radiusV;
        Color _color;

    public:
        IndieEllipse(int, int, float, float, Color);
        ~IndieEllipse() = default;
        IndieEllipse(const IndieEllipse &);
        IndieEllipse &operator=(const IndieEllipse &);
        void IndieDrawEllipse(void);
        void IndieDrawEllipseLine(void);
        void IndieSetEllipsePos(int, int);
        void IndieSetEllipseRadius(float, float);
        void IndieSetEllipseColor(Color);
};

#endif