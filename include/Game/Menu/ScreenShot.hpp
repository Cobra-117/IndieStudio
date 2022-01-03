/*
** EPITECH PROJECT, 2021
** sdfghjkl
** File description:
** jhgfds
*/

#ifndef SCREENSHOT
#define SCREENSHOT

#include "../../indie.hpp"
#include "../../Engine/Core/Window.hpp"
#include "../../Engine/Core/Drawer.hpp"
#include "../../Engine/Core/InputKey.hpp"
#include "../../Engine/Core/Misc.hpp"
#include "../../Engine/Textures/Textures.hpp"

class ScreenShot
{
    private:
        Window _window;
        Drawer _drawer;
        InputKey _key;
        Misc _misc;
    public:
        ScreenShot();
        ~ScreenShot() = default;
        int MenuScreenShot(void);
};

#endif