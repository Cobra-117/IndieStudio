/*
** EPITECH PROJECT, 2021
** sdfghjk
** File description:
** jhgfd
*/

#ifndef TRIANGLE
#define TRIANGLE

extern "C" {
    #include "raylib.h"
}

#include <iostream>
#include <string>
#include <cstring>

class IndieTriangle
{
    private:
        Vector2 _v1;
        Vector2 _v2;
        Vector2 _v3;
        Color _color;
    public:
        IndieTriangle(Vector2, Vector2, Vector2, Color);
        ~IndieTriangle() = default;
        IndieTriangle(const IndieTriangle &);
        IndieTriangle &operator=(const IndieTriangle &);
        void IndieDrawTriangle(void);
        void IndieDrawTriangleLine(void);
        void IndieSetTriangleColor(Color);
        void IndieSetTriangleV1(Vector2);
        void IndieSetTriangleV2(Vector2);
        void IndieSetTriangleV3(Vector2);
        Color IndieGetTriangleColor(void);
        Vector2 IndieGetTriangleV1(void);
        Vector2 IndieGetTriangleV2(void);
        Vector2 IndieGetTriangleV3(void);
};

#endif