/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-adrien.michaud
** File description:
** myTextures
*/

#include "../../../include/Engine/Textures/Textures.hpp"

IndieTextures::IndieTextures(std::string fileName, int posX, int posY, float rotation, float scale, Color color)
{
    _texture = LoadTexture(fileName.c_str());
    _posX = posX;
    _posY = posY;
    _rotation = rotation;
    _scale = scale;
    _color = color;
}

IndieTextures::IndieTextures(int posX, int posY, float rotation, float scale, Color color)
{
    _posX = posX;
    _posY = posY;
    _rotation = rotation;
    _scale = scale;
    _color = color;
}

void IndieTextures::IndieLoadNewTexture(std::string fileName)
{
    _texture = LoadTexture(fileName.c_str());
}

void IndieTextures::IndieLoadNewTextureFromImage(Image image)
{
    _texture = LoadTextureFromImage(image);
}

void IndieTextures::IndieUnloadTexture(void)
{
    UnloadTexture(_texture);
}

Image IndieTextures::IndieGetTextureData(Texture2D texture)
{
    return (GetTextureData(_texture));
}

Image IndieTextures::IndieGetScreenData(void)
{
    return (GetScreenData());
}

void IndieTextures::IndieDrawTexture()
{
    DrawTexture(_texture, _posX, _posY, _color);   
}

void IndieTextures::IndieDrawTextureAdvanced(void)
{
    DrawTextureEx(_texture, Vector2({(float)_posX, (float)_posY}), _rotation, _scale, _color);
}

void IndieTextures::IndieDrawTextureRec(Rectangle source)
{
    DrawTextureRec(_texture, source, Vector2({(float)_posX, (float)_posY}), _color);
}

void IndieTextures::IndieSetTextureColor(Color color)
{
    _color = color;
}

void IndieTextures::IndieSetTexturePosition(int x, int y)
{
    _posX = x;
    _posY = y;
}

void IndieTextures::IndieSetTextureRotation(float rot)
{
    _rotation = rot;
}

void IndieTextures::IndieSetTextureScale(float scale)
{
    _scale = scale;
}

float IndieTextures::IndieGetTextureWidth(void)
{
    return _texture.width;
}

float IndieTextures::IndieGetTextureHeight(void)
{
    return _texture.height;
}

int IndieTextures::IndieGetTexturePosX(void)
{
    return _posX;
}

int IndieTextures::IndieGetTexturePosY(void)
{
    return _posY;
}

Color IndieTextures::IndieGetTextureColor(void)
{
    return _color;
}

float IndieTextures::IndieGetTextureScale(void)
{
    return _scale;
}

Texture2D IndieTextures::getTexture(void)
{
    return  _texture;
}

