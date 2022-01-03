/*
** EPITECH PROJECT, 2021
** sdfghj
** File description:
** jhgfd
*/

#include "../../../include/Exceptions.hpp"
#include "../../../include/Engine/Core/Cursor.hpp"

Cursor::Cursor(void)
{
    EnableCursor();
    ShowCursor();
}

void Cursor::showCursor(void)
{
    ShowCursor();
}

void Cursor::hideCursor(void)
{
    HideCursor();
}

bool Cursor::isCursorHidden(void)
{
    return IsCursorHidden();
}

void Cursor::enableCursor(void)
{
    EnableCursor();
}

void Cursor::disableCursor(void)
{
    DisableCursor();
}

bool Cursor::isCursorOnScreen(void)
{
    return IsCursorOnScreen();
}