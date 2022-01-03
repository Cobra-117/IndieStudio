/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-adrien.michaud
** File description:
** myTextures
*/

#ifndef MYTEXTURES_HPP_
#define MYTEXTURES_HPP_

extern "C" {
    #include "raylib.h"
}

#include <iostream>
#include <string>
#include <cstring>

class IndieTextures
{
    public:
        IndieTextures() = default;
        IndieTextures(std::string, int, int, float, float, Color);
        IndieTextures(int, int, float, float, Color);
        ~IndieTextures() = default;
        void IndieLoadNewTexture(std::string);
        void IndieLoadNewTextureFromImage(Image image);
        void IndieUnloadTexture(void);
        Image IndieGetTextureData(Texture2D texture);
        Image IndieGetScreenData(void);
        void IndieDrawTexture(void);
        void IndieDrawTextureAdvanced(void);
        void IndieDrawTextureRec(Rectangle source);
        void IndieSetTextureColor(Color);
        void IndieSetTexturePosition(int, int);
        void IndieSetTextureRotation(float);
        void IndieSetTextureScale(float);
        float IndieGetTextureWidth(void);
        float IndieGetTextureHeight(void);
        int IndieGetTexturePosX(void);
        int IndieGetTexturePosY(void);
        Color IndieGetTextureColor(void);
        float IndieGetTextureScale(void);
        Texture2D getTexture(void);

    public:
        Texture2D _texture;
        int _posX;
        int _posY;
        float _rotation;
        float _scale;
        Color _color;
};

#endif /* !MYTEXTURES_HPP_ */
