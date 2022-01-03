/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-adrien.michaud
** File description:
** myAudio.hpp
*/

#ifndef MY_AUDIO_
#define MY_AUDIO_

extern "C" {
    #include "raylib.h"
}

#include <iostream>
#include <string>
#include <cstring>

class IndieAudioStream
{
    public:
        IndieAudioStream(unsigned int, unsigned int, unsigned int);
        ~IndieAudioStream() = default;
        void IndieCloseAudioStream();
        void IndiePlayAudioStream();
        void IndiePauseAudioStream();
        void IndieResumeAudioStream();
        void IndieStopAudioStream();
        void IndieSetAudioStreamVolume(float);
    
    public:
        AudioStream _audioStream;
};

#endif