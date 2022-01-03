/*
** EPITECH PROJECT, 2021
** dfghj
** File description:
** jhgfd
*/

#include "../../../include/Exceptions.hpp"
#include "../../../include/Engine/Core/InputMouse.hpp"

InputMouse::InputMouse(int x, int y)
{
    SetMousePosition(x, y);
    _posX = x;
    _posY = y;
}

InputMouse::InputMouse(const InputMouse &a)
{
    _posX = a._posX;
    _posY = a._posY;
    SetMousePosition(_posX, _posY);
}

InputMouse &InputMouse::operator=(const InputMouse &a)
{
    _posX = a._posX;
    _posY = a._posY;
    SetMousePosition(_posX, _posY);
    return *this;
}

bool InputMouse::isMouseButtonPressed(int button)
{
    return IsMouseButtonPressed(button);
}

bool InputMouse::isMouseButtonDown(int button)
{
    return IsMouseButtonDown(button);
}

bool InputMouse::isMouseButtonReleased(int button)
{
    return IsMouseButtonReleased(button);
}

bool InputMouse::isMouseButtonUp(int button)
{
    return IsMouseButtonUp(button);
}

int InputMouse::getMouseX(void)
{
    return GetMouseX();
}

int InputMouse::getMouseY(void)
{
    return GetMouseY();
}

Vector2 InputMouse::getMousePosition(void)
{
    return GetMousePosition();
}

void InputMouse::setMousePosition(int x, int y)
{
    SetMousePosition(x, y);
    _posX = x;
    _posY = y;
}

void InputMouse::setMouseOffset(int offsetX, int offsetY)
{
    SetMouseOffset(offsetX, offsetY);
}

void InputMouse::setMouseScale(float scaleX, float scaleY)
{
    SetMouseScale(scaleX, scaleY);
}

float InputMouse::getMouseWheelMove(void)
{
    return GetMouseWheelMove();
}

void InputMouse::setMouseCursor(int cursor)
{
    SetMouseCursor(cursor);
}
