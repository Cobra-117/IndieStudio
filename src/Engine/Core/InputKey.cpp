/*
** EPITECH PROJECT, 2021
** sdfghj
** File description:
** jhgfd
*/

#include "../../../include/Exceptions.hpp"
#include "../../../include/Engine/Core/InputKey.hpp"

InputKey::InputKey(int key)
{
    if (key < 32 || key > 127)
        throw Exceptions("Invalid key.");
    SetExitKey(key);
    _exitKey = key;
}

InputKey::InputKey(const InputKey &a)
{
    _exitKey = a._exitKey;
    SetExitKey(_exitKey);
}

InputKey &InputKey::operator=(const InputKey &a)
{
    _exitKey = a._exitKey;
    SetExitKey(_exitKey);
    return *this;
}

bool InputKey::isKeyPressed(int key)
{
    return IsKeyPressed(key);
}

bool InputKey::isKeyDown(int key)
{
    return IsKeyDown(key);
}

bool InputKey::isKeyReleased(int key)
{
    return IsKeyReleased(key);
}

bool InputKey::isKeyUp(int key)
{
    return IsKeyUp(key);
}

void InputKey::setExitKey(int key)
{
    SetExitKey(key);
    _exitKey = key;
}

int InputKey::getKeyPressed(void)
{
    return GetKeyPressed();
}

int InputKey::getCharPressed(void)
{
    return GetCharPressed();
}

int InputKey::getExitKey(void)
{
    return _exitKey;
}