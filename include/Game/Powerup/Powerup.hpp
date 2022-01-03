/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-adrien.michaud
** File description:
** Powerup.hpp
*/

#ifndef __POWUP_
#define __POWUP_

#include "../../Game/Player.hpp"
#include "../../Engine/Models/models.hpp"
#include "../../Game/Bombs/bomb.hpp"
#include "../../Engine/Audio/Sound.hpp"
#include "../../Engine/Audio/AudioManager.hpp"

/*type of the powerup:
    1:cancel_explosion
    2:instant_explosion
    3:invincibility
    4:radius_down
    5:radius_up
    6:speed_down
    7:speed_up
    8:wall_pass
*/
class Player;
class AIPlayer;
class Bomb;

class Powerup {

    public:
        Powerup(int type, Vector3 _position, std::vector<Player *> *_players, std::vector<Bomb *> *_bombs, Map *_map, std::vector<AIPlayer *> *_IA);
        ~Powerup();
        int IsPlayerOnPowerUp(std::vector<Player *> *_players, Map *_map, std::vector<AIPlayer *> *);
        int checkPowerup(std::vector<Player *> *_players, std::vector<Bomb *> *_bombs, Map *_map, std::vector<AIPlayer *> *_IA);
        IndieModel _model;
        IndieTextures *_tex;
        int _type;
};
#endif
