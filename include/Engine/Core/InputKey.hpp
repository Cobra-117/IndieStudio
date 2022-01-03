/*
** EPITECH PROJECT, 2021
** sdfghj
** File description:
** hgfd
*/

#ifndef INPUT_KEY
#define INPUT_KEY

extern "C" {
    #include "raylib.h"
}

class InputKey
{
    private:
        int _exitKey;
    public:
        InputKey() = default;
        InputKey(int);
        InputKey(const InputKey &);
        InputKey &operator=(const InputKey &);
        ~InputKey() = default;
        bool isKeyPressed(int);
        bool isKeyDown(int);
        bool isKeyReleased(int);
        bool isKeyUp(int);
        void setExitKey(int);
        int getKeyPressed(void);
        int getCharPressed(void);
        int getExitKey(void);
};

#endif