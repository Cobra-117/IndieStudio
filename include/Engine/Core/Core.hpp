/*
** EPITECH PROJECT, 2021
** sdfgh
** File description:
** jhgfd
*/

#ifndef CORE
#define CORE

#include "./Window.hpp"
#include "./Drawer.hpp"
#include "./InputKey.hpp"
#include "./InputMouse.hpp"
#include "./Misc.hpp"
#include "./FileManager.hpp"

extern "C" {
    #include "raylib.h"
}

class Core
{
    private:
        Window _window;
        Drawer _drawer;
        InputKey _inputKey;
        InputMouse _inputMouse;
        Misc _misc;
        FileManager _fileManager;
    public:
        Core();
        ~Core();
        Window getWindow(void);
        void setWindow(Window);
        Drawer getDrawer(void);
        void setDrawer(Drawer);
        InputKey getInputKey(void);
        void setInputKey(InputKey);
        InputMouse getInputMouse(void);
        void setInputMouse(InputMouse);
        Misc getMisc(void);
        void setMisc(Misc);
        FileManager getFileManager(void);
        void setFileManager(FileManager);
};

#endif