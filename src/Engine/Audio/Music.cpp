/*
** EPITECH PROJECT, 2021
** sdfghj
** File description:
** hgfdq
*/

#include "../../../include/Engine/Audio/Music.hpp"

IndieMusic::IndieMusic(std::string filename)
{
    this->_music = LoadMusicStream(filename.c_str());
}

IndieMusic::IndieMusic(const IndieMusic &a)
{
    _music = a._music;
}

IndieMusic &IndieMusic::operator=(const IndieMusic &a)
{
    _music = a._music;
    return *this;
}

void IndieMusic::IndieLoadMusicStream(std::string filename)
{
    this->_music = LoadMusicStream(filename.c_str());
}

void IndieMusic::IndieUnloadMusicStream()
{
    UnloadMusicStream(this->_music);
}

void IndieMusic::IndiePlayMusicStream()
{
    PlayMusicStream(this->_music);
}

void IndieMusic::IndieStopMusicStream()
{
    StopMusicStream(this->_music);
}

void IndieMusic::IndiePauseMusicStream()
{
    PauseMusicStream(this->_music);
}

void IndieMusic::IndieResumeMusicStream()
{
    ResumeMusicStream(this->_music);
}

void IndieMusic::IndieSetMusicVolume(float vol)
{
    SetMusicVolume(this->_music, vol);
}

void IndieMusic::IndieUpdateMusicStream()
{
    UpdateMusicStream(this->_music);
}