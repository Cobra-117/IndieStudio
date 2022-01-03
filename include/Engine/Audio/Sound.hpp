/*
** EPITECH PROJECT, 2021
** sdfghjk
** File description:
** jhgfds
*/

#ifndef SOUND
#define SOUND

extern "C" {
    #include "raylib.h"
}

#include <iostream>
#include <string>
#include <cstring>

class IndieSound
{
    public:
        IndieSound(std::string);
        ~IndieSound() = default;
        void IndieLoadSound(std::string);
        void IndieLoadSoundFromWave();
        void IndieUnloadSound();
        void IndieUpdateSound(const void *, int);
        void IndiePlaySound();
        void IndiePlaySoundMulti();
        void IndieStopSound();
        void IndieStopSoundMulti();
        void IndiePauseSound();
        void IndieResumeSound();
        void IndieSetSoundVolume(float vol);
        void IndieLoadWave(std::string);
        void IndieUnloadWave();

    public:
        Sound _sound;
        Wave _wave;
};

#endif
