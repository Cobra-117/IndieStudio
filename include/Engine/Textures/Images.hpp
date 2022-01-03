/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-adrien.michaud
** File description:
** myTextures
*/

#ifndef MYIMAGES_HPP_
#define MYIMAGES_HPP_

extern "C" {
    #include "raylib.h"
}

#include <iostream>
#include <string>
#include <cstring>

class IndieImages
{
    public:
        IndieImages(std::string);
        IndieImages(std::string, int, int, int, int);
        ~IndieImages() = default;

        void IndieLoadImage(const char *fileName);
        void IndieLoadImageRaw(const char *fileName, int width, int height, int format, int headerSize);
        void IndieLoadImageAnim(const char *fileName, int *frames);      
        void IndieLoadImageFromMemory(const char *fileType, const unsigned char *fileData, int dataSize);
        void IndieUnloadImage();
        
        Image IndieImageCopy();
        void IndieImageResize(int newWidth, int newHeight);
        void IndieImageResizeNN(int newWidth,int newHeight);
        void IndieImageFlipVertical();
        void IndieImageFlipHorizontal();
    public:
        Image _image;
        int _width;
        int _height;
        int format;
        int headerSize;
        int *frames;
};

#endif /* !MYTEXTURES_HPP_ */
