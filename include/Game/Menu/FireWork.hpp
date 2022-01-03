/*
** EPITECH PROJECT, 2021
** sdfghj
** File description:
** kjhgf
*/

#include "../../indie.hpp"
#include "../../Engine/Textures/Textures.hpp"
#include "../../Engine/Shapes/Rectangle.hpp"

class FireWork
{
    private:
        IndieTextures _texture;
        IndieRectangle _rectangle;
        int currentFrameX;
        int currentFrameY;
        int framesCounter;
        int framesSpeed;
    public:
        FireWork(Color color, int posX, int posY, float scale) : _texture("../ressource/Menu/Firework.png", posX, posY, 0, scale, color), _rectangle(0, 0, 0, 0, WHITE) {
            _rectangle.IndieSetRectangleWidthHeight(float(_texture.getTexture().width / 6), float(_texture.getTexture().height / 5));
            currentFrameX = 0;
            currentFrameY = 0;
            framesCounter = 0;
            framesSpeed = 10;
        };
        ~FireWork() = default;
        void DoAnimation(void) {
            framesCounter++;
            if (framesCounter >= (60/framesSpeed)) {
                framesCounter = 0;
                currentFrameX++;
                if (currentFrameX > 5) {
                    currentFrameX = 0;
                    currentFrameY++;
                }
                if (currentFrameY > 4) {
                    currentFrameX = 0;
                    currentFrameY = 0;
                }
                _rectangle.IndieSetRectanglePos((float)currentFrameX * (float)_texture.getTexture().width / 6, (float)currentFrameY * (float)_texture.getTexture().height / 5);
            }
            _texture.IndieDrawTextureRec(_rectangle.IndieGetRectangleRec());
        };
};
