/*
** EPITECH PROJECT, 2021
** dfgh
** File description:
** jhgf
*/

#ifndef WINDOW
#define WINDOW

#include <iostream>

extern "C" {
    #include "raylib.h"
}

class Window
{
    private:
        int _sizeX;
        int _sizeY;
        std::string _title;
    public:
        Window();
        Window(int, int, std::string);
        Window(int, int);
        Window(std::string);
        Window(const Window &);
        Window &operator=(const Window &);
        ~Window() = default;
        void closeWindow(void);
        void checkWindow(void);
        bool keepWindowOpen(void);
        void clearWindow(Color);
        void setWindowSize(int, int);
        void setWindowPosition(int, int);
        void setWindowTitle(std::string);
        void setWindowIcon(Image);
        std::pair<int, int> getScreenSize(void);
        Vector2 getWindowPosition(void);
        void setClipboardText(std::string);
        std::string getClipboardText(void);
        void setTargetFPS(int);
        int getFPS(void);
        float getFrameTime(void);
        double getTime(void);
        void reopenWindow(void);
};

#endif