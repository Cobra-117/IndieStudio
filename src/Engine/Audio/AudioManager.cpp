/*
** EPITECH PROJECT, 2020
** INDIE
** File description:
** myAudio.cpp
*/

#include "../../../include/Engine/Audio/AudioManager.hpp"

IndieAudioManager::IndieAudioManager()
{
    InitAudioDevice();
}

IndieAudioManager::IndieAudioManager(float vol)
{
    InitAudioDevice();
    SetMasterVolume(vol);
    _volume = vol;
}

bool IndieAudioManager::IndieIsAudioDeviceReady(void)
{
    return IsAudioDeviceReady();
}

void IndieAudioManager::IndieCloseAudioDevice(void)
{
    CloseAudioDevice();
}

void IndieAudioManager::IndieSetMasterVolume(float vol)
{
    SetMasterVolume(vol);
    _volume = vol;
}
