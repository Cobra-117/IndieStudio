/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-adrien.michaud
** File description:
** Powerup.cpp
*/

#include "../../../include/Game/Powerup/Powerup.hpp"

Powerup::Powerup(int type, Vector3 _position, std::vector<Player *> *_players, std::vector<Bomb *> *_bombs, Map *_map, std::vector<AIPlayer *> *_IA)
{
    int myPlayer = 0;

    _type = type;
    if (_type == 1) {
        _model.loadFromFile("../ressource/3DModels/powerups/powerups.iqm");
        _tex = new IndieTextures("../ressource/3DModels/powerups/cancel_explosion.png", 0, 0, 0, 1, WHITE);
        _model.tex = _tex;
        _model.IndieSetMaterialTexture(0, *_model.tex);
        _model._position.x = _position.x;
        _model._position.y = _position.y;
        _model._position.z = _position.z;
        _model._rotationAxis = { 1.0f, 0.0f, 0.0f };
        _model._scale = {0.2f, 0.2f, 0.2f };
    }
    if (_type == 2) {
        _tex = new IndieTextures("../ressource/3DModels/powerups/instant_explosion.png", 0, 0, 0, 1, WHITE);
        _model.tex = _tex;
        _model.loadFromFile("../ressource/3DModels/powerups/powerups.iqm");
        _model.IndieSetMaterialTexture(0, *_model.tex);
        _model._position.x = _position.x;
        _model._position.y = _position.y;
        _model._position.z = _position.z;
        _model._rotationAxis = { 1.0f, 0.0f, 0.0f };
        _model._scale = {0.2f, 0.2f, 0.2f };
    }
    if (_type == 3) {
        _tex = new IndieTextures("../ressource/3DModels/powerups/invincibility.png", 0, 0, 0, 1, WHITE);
        _model.tex = _tex;
        _model.loadFromFile("../ressource/3DModels/powerups/invincibility.iqm");
        _model.IndieSetMaterialTexture(0, *_model.tex);
        _model._position.x = _position.x;
        _model._position.y = _position.y;
        _model._position.z = _position.z;
        _model._rotationAxis = { 1.0f, 0.0f, 0.0f };
        _model._scale = {0.5f, 0.5f, 0.5f };
    }
    if (_type == 4) {
        _tex = new IndieTextures("../ressource/3DModels/powerups/radius_down.png", 0, 0, 0, 1, WHITE);
        _model.tex = _tex;
        _model.loadFromFile("../ressource/3DModels/powerups/powerups.iqm");
        _model.IndieSetMaterialTexture(0, *_model.tex);
        _model._position.x = _position.x;
        _model._position.y = _position.y;
        _model._position.z = _position.z;
        _model._rotationAxis = { 1.0f, 0.0f, 0.0f };
        _model._scale = {0.2f, 0.2f, 0.2f };
    }
    if (_type == 5) {
        _tex = new IndieTextures("../ressource/3DModels/powerups/radius_up.png", 0, 0, 0, 1, WHITE);
        _model.tex = _tex;
        _model.loadFromFile("../ressource/3DModels/powerups/powerups.iqm");
        _model.IndieSetMaterialTexture(0, *_model.tex);
        _model._position.x = _position.x;
        _model._position.y = _position.y;
        _model._position.z = _position.z;
        _model._rotationAxis = { 1.0f, 0.0f, 0.0f };
        _model._scale = {0.2f, 0.2f, 0.2f };
    }
    if (_type == 6) {
        _tex = new IndieTextures("../ressource/3DModels/powerups/speed_down.png", 0, 0, 0, 1, WHITE);
        _model.tex = _tex;
        _model.loadFromFile("../ressource/3DModels/powerups/speed_down.iqm");
        _model.IndieSetMaterialTexture(0, *_model.tex);
        _model._position.x = _position.x;
        _model._position.y = _position.y;
        _model._position.z = _position.z;
        _model._rotationAxis = { 1.0f, 0.0f, 0.0f };
        _model._scale = {0.5f, 0.5f, 0.5f };
    }
    if (_type == 7) {
        _tex = new IndieTextures("../ressource/3DModels/powerups/speed_up.png", 0, 0, 0, 1, WHITE);
        _model.tex = _tex;
        _model.loadFromFile("../ressource/3DModels/powerups/speed_up.iqm");
        _model.IndieSetMaterialTexture(0, *_model.tex);
        _model._position.x = _position.x;
        _model._position.y = _position.y;
        _model._position.z = _position.z;
        _model._rotationAxis = { 1.0f, 0.0f, 0.0f };
        _model._scale = {0.5f, 0.5f, 0.5f };
    }
    if (_type == 8) {
        _tex = new IndieTextures("../ressource/3DModels/powerups/wall_pass.png", 0, 0, 0, 1, WHITE);
        _model.tex = _tex;
        _model.loadFromFile("../ressource/3DModels/powerups/powerups.iqm");
        _model.IndieSetMaterialTexture(0, *_model.tex);
        _model._position.x = _position.x;
        _model._position.y = _position.y;
        _model._position.z = _position.z;
        _model._rotationAxis = { 1.0f, 0.0f, 0.0f };
        _model._scale = {0.2f, 0.2f, 0.2f };
    }
}

int Powerup::IsPlayerOnPowerUp(std::vector<Player *> *_players, Map *_map, std::vector<AIPlayer *> *_IA)
{
    for (size_t n = 0; n < _players->size(); n++) {
        if (_players->at(n)->isOnTile((int)(_model._position.z  - 0.5f),
        (int)_model._position.x, _map->YOffset, _map->XOffset)) {
            IndieSound s("../ressource/Musics/SoundEffects/powerup.mp3");
            _players->at(n)->_score += 10;
            s.IndiePlaySoundMulti();
            return n;
        }
    }
    for (size_t n = 0; n < _IA->size(); n++) {
        if (_IA->at(n)->isOnTile((int)(_model._position.z  - 0.5f),
        (int)_model._position.x, _map->YOffset, _map->XOffset)) {
            IndieSound s("../ressource/Musics/SoundEffects/powerup.mp3");
            _IA->at(n)->_score += 10;
            s.IndiePlaySoundMulti();
            return -n;
        }
    }
    return -84;
}

int Powerup::checkPowerup(std::vector<Player *> *_players, std::vector<Bomb *> *_bombs, Map *_map, std::vector<AIPlayer *> *_IA)
{
    int myPlayer = 0;

    if ((myPlayer = this->IsPlayerOnPowerUp(_players, _map, _IA)) != -84) {
        if (_type == 1) {
            _bombs->clear();
            return 1;
        }
        if (_type == 2) {
            for (unsigned int i = 0; i < _bombs->size(); i++)
                _bombs->at(i)->explode(_map, _players, _IA);
            return 1;
        }
        if (_type == 3) {
            if (myPlayer >= 0)
                _players->at(myPlayer)->_isInvincible = true;
            else
                _IA->at(myPlayer*(-1))->_isInvincible = true;
            return 1;
        }
        if (_type == 4) {
            for (unsigned int i = 0; i < _bombs->size(); i++)
                _bombs->at(i)->_explosionRadius -= 1;
            return 1;
        }
        if (_type == 5) {
            for (unsigned int i = 0; i < _bombs->size(); i++)
                _bombs->at(i)->_explosionRadius += 1;
            return 1;
        }
        if (_type == 6) {
            if (myPlayer >= 0)
                _players->at(myPlayer)->_speed -= 0.01;
            else
                _IA->at(myPlayer*(-1))->_speed -= 0.01;
            return 1;
        }
        if (_type == 7) {
            if (myPlayer >= 0)
                _players->at(myPlayer)->_speed += 0.01;
            else
                _IA->at(myPlayer*(-1))->_speed += 0.01;
            return 1;
        }
        if (_type == 8) {
            if (myPlayer >= 0)
                _players->at(myPlayer)->_canPassWall = true;
            else
                _IA->at(myPlayer*(-1))->_canPassWall = true;
            return 1;
        }
    }
    return 0;
}

Powerup::~Powerup()
{
}
