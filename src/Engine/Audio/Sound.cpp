/*
** EPITECH PROJECT, 2021
** sdfghjk
** File description:
** jhgfd
*/

#include "../../../include/Engine/Audio/Sound.hpp"

IndieSound::IndieSound(std::string filename)
{
    this->_sound = LoadSound(filename.c_str());
}

void IndieSound::IndieLoadWave(std::string filename)
{
    this->_wave = LoadWave(filename.c_str());
}

void IndieSound::IndieLoadSound(std::string filename)
{
    this->_sound = LoadSound(filename.c_str());
}

void IndieSound::IndieLoadSoundFromWave()
{
    this->_sound = LoadSoundFromWave(this->_wave);
}

void IndieSound::IndieUnloadWave()
{
    UnloadWave(this->_wave);
}

void IndieSound::IndieUnloadSound()
{
    UnloadSound(this->_sound);
}

void IndieSound::IndiePlaySound()
{
    PlaySound(this->_sound);
}

void IndieSound::IndiePlaySoundMulti()
{
    PlaySoundMulti(this->_sound);
}

void IndieSound::IndieStopSound()
{
    StopSound(this->_sound);
}

void IndieSound::IndieStopSoundMulti()
{
    StopSoundMulti();
}

void IndieSound::IndiePauseSound()
{
    PauseSound(this->_sound);
}

void IndieSound::IndieResumeSound()
{
    ResumeSound(this->_sound);
}

void IndieSound::IndieSetSoundVolume(float vol)
{
    SetSoundVolume(this->_sound, vol);
}

void IndieSound::IndieUpdateSound(const void *data, int samplesCount)
{
    UpdateSound(this->_sound, data, samplesCount);
}
