/*
** EPITECH PROJECT, 2021
** sdfghj
** File description:
** hgfd
*/

#ifndef INPUT_MOUSE
#define INPUT_MOUSE

extern "C" {
    #include "raylib.h"
}

class InputMouse
{
    private:
        int _posX;
        int _posY;
    public:
        InputMouse() = default;
        InputMouse(int, int);
        InputMouse(const InputMouse &);
        InputMouse &operator=(const InputMouse &);
        ~InputMouse() = default;
        bool isMouseButtonPressed(int);
        bool isMouseButtonDown(int);
        bool isMouseButtonReleased(int);
        bool isMouseButtonUp(int);
        int getMouseX(void);
        int getMouseY(void);
        Vector2 getMousePosition(void);
        void setMousePosition(int, int);
        void setMouseOffset(int, int);
        void setMouseScale(float, float);
        float getMouseWheelMove(void);
        void setMouseCursor(int);
};

#endif