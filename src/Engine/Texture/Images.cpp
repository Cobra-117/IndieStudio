/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-adrien.michaud
** File description:
** myImages
*/

#include "../../../include/Engine/Textures/Images.hpp"

IndieImages::IndieImages(std::string fileName)
{
    _image = LoadImage(fileName.c_str());
}

IndieImages::IndieImages(std::string fileName, int width, int height,  int format, int headerSize)
{
    _image = LoadImageRaw(fileName.c_str(), width, height, format, headerSize);
}

void IndieImages::IndieLoadImage(const char *fileName)
{
    _image = LoadImage(fileName);
}

void IndieImages::IndieLoadImageRaw(const char *fileName, int width, int height,  int format, int headerSize)
{
    _image = LoadImageRaw(fileName, width, height, format, headerSize);
}
    
void IndieImages::IndieLoadImageAnim(const char *fileName, int *frames)
{
    _image = LoadImageAnim(fileName, frames);
}
    
void IndieImages::IndieLoadImageFromMemory(const char *fileType, const unsigned char *fileData, int dataSize)
{
    _image = LoadImageFromMemory(fileType, fileData, dataSize);
}
   
void IndieImages::IndieUnloadImage()
{
    UnloadImage(_image);
}
   
Image IndieImages::IndieImageCopy()
{
    return (ImageCopy(_image));
}

void IndieImages::IndieImageResize(int newWidth, int newHeight)
{
    ImageResize(&_image, newWidth, newHeight);
}
    
void IndieImages::IndieImageResizeNN(int newWidth,int newHeight)
{
    ImageResizeNN(&_image, newWidth, newHeight);
}
    
void IndieImages::IndieImageFlipVertical()
{
    ImageFlipVertical(&_image);
}
    
void IndieImages::IndieImageFlipHorizontal()
{
    ImageFlipVertical(&_image);
}