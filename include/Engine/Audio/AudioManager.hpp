/*
** EPITECH PROJECT, 2021
** dfghj
** File description:
** jhgfd
*/

#ifndef AUDIO_MANAGER
#define AUDIO_MANAGER

extern "C" {
    #include "raylib.h"
}

#include <iostream>
#include <string>
#include <cstring>

class IndieAudioManager
{
    public:
        IndieAudioManager();
        IndieAudioManager(float);
        ~IndieAudioManager() = default;
        bool IndieIsAudioDeviceReady(void);
        void IndieSetMasterVolume(float);
        void IndieCloseAudioDevice(void);
    private:
        float _volume;
};

#endif