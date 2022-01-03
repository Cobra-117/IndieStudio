/*
** EPITECH PROJECT, 2021
** sdfghj
** File description:
** jhgfds
*/

#include "../../../include/Engine/Audio/AudioStream.hpp"

IndieAudioStream::IndieAudioStream(unsigned int sampleRate, unsigned int sampleSize, unsigned int channels)
{
    //this->_audioStream = InitAudioStream(sampleRate, sampleSize, channels);
}

void IndieAudioStream::IndieCloseAudioStream()
{
    //CloseAudioStream(this->_audioStream);
}

void IndieAudioStream::IndiePlayAudioStream()
{
    PlayAudioStream(this->_audioStream);
}

void IndieAudioStream::IndieResumeAudioStream()
{
    ResumeAudioStream(this->_audioStream);
}

void IndieAudioStream::IndieStopAudioStream()
{
    StopAudioStream(this->_audioStream);
}

void IndieAudioStream::IndieSetAudioStreamVolume(float vol)
{
    SetAudioStreamVolume(this->_audioStream, vol);
}
