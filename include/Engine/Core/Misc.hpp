/*
** EPITECH PROJECT, 2021
** sdfh
** File description:
** jhgfd
*/

#ifndef MISC
#define MISC

#include <iostream>

extern "C" {
    #include "raylib.h"
}

class Misc
{
    private:
    public:
        Misc() = default;
        ~Misc() = default;
        int getRandomValue(int, int);
        void takeScreenshot(std::string);
        void CheckScreenShotToTake(void);
        void *memAlloc(int);
        void *memRealloc(void *, int);
        void memFree(void *);
};

#endif