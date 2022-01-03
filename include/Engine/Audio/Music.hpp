/*
** EPITECH PROJECT, 2021
** sdfghjk
** File description:
** kjhgfds
*/

#ifndef MUSIC
#define MUSIC

extern "C" {
    #include "raylib.h"
}

#include <iostream>
#include <string>
#include <cstring>

class IndieMusic
{
    public:
        IndieMusic(std::string);
        ~IndieMusic() = default;
        IndieMusic(const IndieMusic &);
        IndieMusic &operator=(const IndieMusic &);
        void IndieLoadMusicStream(std::string);
        void IndieUnloadMusicStream();
        void IndieUpdateMusicStream();
        void IndiePlayMusicStream();
        void IndieStopMusicStream();
        void IndiePauseMusicStream();
        void IndieResumeMusicStream();
        void IndieSetMusicVolume(float);
    
    public:    
        Music _music;
};

#endif