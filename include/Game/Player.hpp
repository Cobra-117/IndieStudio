/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-adrien.michaud
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "../Engine/Models/models.hpp"
#include "../Engine/Colliders/SquareCollider.hpp"
#include "Game.hpp"
#include <chrono>
#include <ctime>

#define PLAYERSPEED 0.05f
#define PLAYERTOPCOLLIDER 0.2f

class Game;
class SquareCOllider;

class Player {
    public:
        Player(int texId, int corner, bool isHuman);
        ~Player();
        void move(int, Map *);
        void placeBomb(Game *game);
        bool isOnTile(int y, int x, int yOffset, int xOffset);
        bool isActive();
        void kill();
        void checkCollisionUp(Map *map);
        void checkCollisionDown(Map *map);
        void checkCollisionRight(Map *map);
        void checkCollisionLeft(Map *map);
    public:
        IndieModel _model;
        std::chrono::steady_clock::time_point _clock;
        bool _isActive;
        bool _isHuman;
        SquareCollider _collider;
        int _score = 0;
        int _animCount = 0;
        int _animFrameCounter = 0;
        float _speed = 0.05f;
        bool _isInvincible = false;
        bool _canPassWall = false;
    protected:
    private:
};

class AIPlayer: public Player
{
    public:
        //AIPlayer() {}
        AIPlayer(int texId, int corner, int id);
        void AI(Game *game);
        void finishCase(Map *map);
        void AIMove(int, Map *);
        void chooseTarget(Game *game);
        void rushTarget(Game *game);
        void stupidMode(Game *game);
        bool isInBombRange(Game *game);
    private:
        int _id;
        int _lastMovement;
        int targetCase;
        int _targetedPlayer;
        Vector2 _TargetPos;
};

#endif /* !PLAYER_HPP_ */
