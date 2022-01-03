/*
** EPITECH PROJECT, 2021
** dfghj
** File description:
** jhgfd
*/

#ifndef CURSOR
#define CURSOR

extern "C" {
    #include "raylib.h"
}

class Cursor
{
    private:
    public:
        Cursor();
        ~Cursor() = default;
        void showCursor(void);
        void hideCursor(void);
        bool isCursorHidden(void);
        void enableCursor(void);
        void disableCursor(void);
        bool isCursorOnScreen(void);
};

#endif