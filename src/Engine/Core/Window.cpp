/*
** EPITECH PROJECT, 2021
** sdfghj
** File description:
** jhgfd
*/

#include "../../../include/Engine/Core/Window.hpp"
#include "../../../include/Exceptions.hpp"

Window::Window(void)
{
    InitWindow(800, 600, "Simple Window");
    _sizeX = 800;
    _sizeY = 600;
    _title = "Simple Window";
}

Window::Window(int x, int y)
{
    if (x < 1 || y < 1 || x > 1920 || y > 1080)
        throw Exceptions("Invalid Window size.");
    InitWindow(x, y, "Simple Window");
    _sizeX = x;
    _sizeY = y;
    _title = "Simple Window";
}

Window::Window(std::string title)
{
    InitWindow(1920, 1080, title.c_str());
    _sizeX = 1920;
    _sizeY = 1080;
    _title = title;
}

Window::Window(int x, int y, std::string title)
{
    if (x < 1 || y < 1 || x > 1920 || y > 1080)
        throw Exceptions("Invalid Window size.");
    InitWindow(x, y, title.c_str());
    _sizeX = x;
    _sizeY = y;
    _title = title;
}

Window::Window(const Window &a)
{
    _sizeX = a._sizeX;
    _sizeY = a._sizeY;
    _title = a._title;
    InitWindow(_sizeX, _sizeY, _title.c_str());
}

Window &Window::operator=(const Window &a)
{
    _sizeX = a._sizeX;
    _sizeY = a._sizeY;
    _title = a._title;
    InitWindow(_sizeX, _sizeY, _title.c_str());
    return *this;
}

bool Window::keepWindowOpen(void)
{
    return !WindowShouldClose();
}

void Window::checkWindow(void)
{
    if(!IsWindowReady()) {
        throw Exceptions("Cannot create Window.");
    }
}

void Window::closeWindow(void)
{
    if(!IsWindowReady()) {
        throw Exceptions("Cannot close Window.");
    } else {
        CloseWindow();
    }
}

void Window::clearWindow(Color color)
{
    BeginDrawing();
    ClearBackground(color);
    EndDrawing();
}

void Window::setWindowSize(int width, int height)
{
    if (width < 1 || height < 1 || width > 1920 || height > 1080)
        throw Exceptions("Invalid Window size.");
    SetWindowSize(width, height);
    _sizeX = width;
    _sizeY = height;
}

void Window::setWindowPosition(int x, int y)
{
    if (x < 0 || y < 0 || x > 1920 || y > 1080)
        throw Exceptions("Invalid Window position");
    SetWindowPosition(x, y);
}

void Window::setWindowIcon(Image image)
{
    SetWindowIcon(image);
}

void Window::setWindowTitle(std::string title)
{
    SetWindowTitle(title.c_str());
    _title = title;
}

std::pair<int, int> Window::getScreenSize(void)
{
    return std::make_pair(_sizeX, _sizeY);
}

Vector2 Window::getWindowPosition(void)
{
    return GetWindowPosition();
}

void Window::setClipboardText(std::string text)
{
    SetClipboardText(text.c_str());
}

std::string Window::getClipboardText(void)
{
    const char *a = GetClipboardText();
    return std::string(a);
}

void Window::setTargetFPS(int fps)
{
    if (fps > 0)
        SetTargetFPS(fps);
    else
        throw Exceptions("You ask for an invalid nimber of fps.");
}

int Window::getFPS(void)
{
    return GetFPS();
}

float Window::getFrameTime(void)
{
    return GetFrameTime();
}

double Window::getTime(void)
{
    return GetTime();
}

void Window::reopenWindow(void)
{
    InitWindow(_sizeX, _sizeX, _title.c_str());
}