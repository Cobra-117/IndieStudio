/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-adrien.michaud
** File description:
** bomb
*/

#ifndef BOMB_HPP_
#define BOMB_HPP_

#include "../Map.hpp"
#include <chrono>
#include <thread>
#include <ctime>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <ctime>
#include "../Player.hpp"
#include "../../Engine/Audio/Sound.hpp"
#include "../../Engine/Audio/AudioManager.hpp"

class Player;
class AIPlayer;

class Bomb
{
    public:
        Bomb();
        ~Bomb();
        void explode(Map *map, std::vector<Player *> *_players);
        void checkExplosionUp(Map *map, std::vector<Player *> *_players,
        std::vector<AIPlayer *> *,
        size_t Zpos, size_t XPos, IndieSound s);
        void checkExplosionDown(Map *map, std::vector<Player *> *_players,
        std::vector<AIPlayer *> *,
        size_t Zpos, size_t XPos, IndieSound s);
        void checkExplosionLeft(Map *map, std::vector<Player *> *_players,
        std::vector<AIPlayer *> *,
        size_t Zpos, size_t XPos, IndieSound s);
        void checkExplosionRight(Map *map, std::vector<Player *> *_players,
        std::vector<AIPlayer *> *,
        size_t Zpos, size_t XPos, IndieSound s);
        void explode(Map *map, std::vector<Player *> *_players, std::vector<AIPlayer *> *);
        bool isCountdownFinished();
    public:
        IndieModel _model;
        IndieTextures *_tex;
        IndieTextures *_tex_blink;
        std::chrono::steady_clock::time_point _clock;
        bool _blink = true;
        int _explosionRadius = 3;
        //std::chrono::steady_clock::now();
};

#endif /* !BOMB_HPP_ */
