/*
** EPITECH PROJECT, 2021
** sdfgh
** File description:
** jhgf
*/

#include "../../../include/Engine/Core/Core.hpp"
#include "../../../include/Exceptions.hpp"

Core::Core(void)
{
    /*_window = new Window();
    _drawer = new Drawer();
    _inputKey = new InputKey();
    _inputMouse = new InputMouse();
    _misc = new Misc();
    _fileManager = new FileManager();*/
}

Core::~Core(void)
{
    /*delete _window;
    delete _drawer;
    delete _inputKey;
    delete _inputMouse;
    delete _misc;
    delete _fileManager;*/
}

Window Core::getWindow(void)
{
    return _window;
}

void Core::setWindow(Window w)
{
    _window = w;
}

Drawer Core::getDrawer(void)
{
    return _drawer;
}

void Core::setDrawer(Drawer d)
{
    _drawer = d;
}

InputKey Core::getInputKey(void)
{
    return _inputKey;
}

void Core::setInputKey(InputKey i)
{
    _inputKey = i;
}

InputMouse Core::getInputMouse(void)
{
    return _inputMouse;
}

void Core::setInputMouse(InputMouse i)
{
    _inputMouse = i;
}

Misc Core::getMisc(void)
{
    return _misc;
}

void Core::setMisc(Misc m)
{
    _misc = m;
}

FileManager Core::getFileManager(void)
{
    return _fileManager;
}

void Core::setFileManager(FileManager f)
{
    _fileManager = f;
}