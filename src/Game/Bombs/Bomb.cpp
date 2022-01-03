/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-adrien.michaud
** File description:
** Bomb
*/

#include "../../../include/Game/Bombs/bomb.hpp"
#include <chrono>
#include <thread>
#include <ctime>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <ctime>

Bomb::Bomb()
{
    IndieSound s("../ressource/Musics/SoundEffects/drop_bomb.mp3");
    _tex = new IndieTextures("../ressource/3DModels/bomb/bomb.png", 0, 0, 0, 1, WHITE);
    _tex_blink = new IndieTextures("../ressource/3DModels/bomb/bomb_blink.png", 0, 0, 0, 1, WHITE);
    _model.tex = _tex;
    _model.loadFromFile("../ressource/3DModels/bomb/Bomb.iqm");
    _model.IndieSetMaterialTexture(0, *_model.tex);
    _model._position = { 0.0f, 0.0f, 0.0f };
    _model._rotationAxis = { 1.0f, 0.0f, 0.0f };
    _model._scale = {2.5f, 2.5f, 2.5f };
    s.IndiePlaySoundMulti();
}

Bomb::~Bomb()
{
    _tex->IndieUnloadTexture();
    _tex_blink->IndieUnloadTexture();
    delete (_tex);
    delete (_tex_blink);
}

void Bomb::checkExplosionUp(Map *map, std::vector<Player *> *_players,
        std::vector<AIPlayer *> *_IAplayers,
        size_t ZPos, size_t XPos, IndieSound s)
{
    s.IndieLoadSound("../ressource/Musics/SoundEffects/breaking_wooden_box.mp3");
    for (int i = 0; i < _explosionRadius &&  (int)ZPos - i >= 0; i++) {
        if (map->_ascii_map[ZPos - i][XPos] == '#')
            break;
        else if (map->_ascii_map[ZPos - i][XPos] == 'x') {
            map->_ascii_map[ZPos - i][XPos] = '.';
            s.IndiePlaySoundMulti();
            break;
        }
        for (size_t n = 0; n < _players->size(); n++) {
            if (_players->at(n)->isOnTile((int)(_model._position.z - i  + 0.5f),
            (int)_model._position.x,  map->YOffset, map->XOffset)) {
                s.IndieLoadSound("../ressource/Musics/SoundEffects/you_lose.mp3");
                _players->at(n)->kill();
                _players->at(0)->_score += 100;
                s.IndiePlaySoundMulti();
            }
        }
        for (size_t n = 0; n < _IAplayers->size(); n++) {
            if (_IAplayers->at(n)->isOnTile((int)(_model._position.z - i  + 0.5f),
            (int)_model._position.x,  map->YOffset, map->XOffset)) {
                _IAplayers->at(n)->kill();
                _players->at(0)->_score += 100;
            }
        }
    }
}

void Bomb::checkExplosionDown(Map *map, std::vector<Player *> *_players,
        std::vector<AIPlayer *> *_IAplayers,
        size_t ZPos, size_t XPos, IndieSound s)
{
    s.IndieLoadSound("../ressource/Musics/SoundEffects/breaking_wooden_box.mp3");
    for (size_t i = 0; i < _explosionRadius &&  ZPos + i <  map->_heigth; i++) {
        if (map->_ascii_map[ZPos + i][XPos] == '#')
            break;
        else if (map->_ascii_map[ZPos + i][XPos] == 'x') {
            map->_ascii_map[ZPos + i][XPos] = '.';
            s.IndiePlaySoundMulti();
            break;
        }
        for (size_t n = 0; n < _players->size(); n++) {
            if (_players->at(n)->isOnTile((int)(ZPos + i  + 0.5f),
            (int)XPos,  map->YOffset, map->XOffset)) {
                s.IndieLoadSound("../ressource/Musics/SoundEffects/you_lose.mp3");
                _players->at(n)->kill();
                _players->at(0)->_score += 100;
                s.IndiePlaySoundMulti();
            }
        }
        for (size_t n = 0; n < _IAplayers->size(); n++) {
            if (_IAplayers->at(n)->isOnTile((int)(_model._position.z + i  + 0.5f),
            (int)_model._position.x,  map->YOffset, map->XOffset)) {
                _IAplayers->at(n)->kill();
                _players->at(0)->_score += 100;
            }
        }
    }
}

void Bomb::checkExplosionLeft(Map *map, std::vector<Player *> *_players,
        std::vector<AIPlayer *> *_IAplayers,
        size_t ZPos, size_t XPos, IndieSound s)
{
    s.IndieLoadSound("../ressource/Musics/SoundEffects/breaking_wooden_box.mp3");
    for (int i = 0; i < _explosionRadius &&  (int)XPos - i >= 0; i++) {
        if (map->_ascii_map[ZPos][XPos - i] == '#')
            break;
        else if (map->_ascii_map[ZPos][XPos - i] == 'x') {
            map->_ascii_map[ZPos][XPos - i] = '.';
            s.IndiePlaySoundMulti();
            break;
        }
        for (size_t n = 0; n < _players->size(); n++) {
            if (_players->at(n)->isOnTile((int)(_model._position.z + 0.5f),
            (int)_model._position.x - i,  map->YOffset, map->XOffset)) {
                s.IndieLoadSound("../ressource/Musics/SoundEffects/you_lose.mp3");
                _players->at(n)->kill();
                _players->at(0)->_score += 100;
                s.IndiePlaySoundMulti();
            }
        }
         for (size_t n = 0; n < _IAplayers->size(); n++) {
            if (_IAplayers->at(n)->isOnTile((int)(_model._position.z + 0.5f),
            (int)_model._position.x - i,  map->YOffset, map->XOffset)) {
                _IAplayers->at(n)->kill();
                _players->at(0)->_score += 100;
            }
        }
    }
}

void Bomb::checkExplosionRight(Map *map, std::vector<Player *> *_players,
        std::vector<AIPlayer *> *_IAplayers,
        size_t ZPos, size_t XPos, IndieSound s)
{
    s.IndieLoadSound("../ressource/Musics/SoundEffects/breaking_wooden_box.mp3");
    for (size_t i = 0; i < _explosionRadius &&  XPos + i < map->_length; i++) {
        if (map->_ascii_map[ZPos][XPos + i] == '#')
            break;
        else if (map->_ascii_map[ZPos][XPos + i] == 'x') {
            map->_ascii_map[ZPos][XPos + i] = '.';
            s.IndiePlaySoundMulti();
            break;
        }
        for (size_t n = 0; n < _players->size(); n++) {
            if (_players->at(n)->isOnTile((int)(_model._position.z + 0.5f),
            (int)_model._position.x + i, map->YOffset, map->XOffset)) {
                s.IndieLoadSound("../ressource/Musics/SoundEffects/you_lose.mp3");
                _players->at(n)->kill();
                _players->at(0)->_score += 100;
                s.IndiePlaySoundMulti();
            }
        }
        for (size_t n = 0; n <  _IAplayers->size(); n++) {
            if (_IAplayers->at(n)->isOnTile((int)(_model._position.z + 0.5f),
            (int)_model._position.x + i, map->YOffset, map->XOffset)) {
                _IAplayers->at(n)->kill();
                _players->at(0)->_score += 100;
            }
        }
    }
}

void Bomb::explode(Map *map, std::vector<Player *> *_players,
std::vector<AIPlayer *> *_AIplayers)
{
    size_t ZPos = (size_t)(_model._position.z + map->YOffset);
    size_t XPos = (size_t)(_model._position.x + map->XOffset);
    IndieSound s("../ressource/Musics/SoundEffects/bomb_sound_effect.mp3");
    s.IndiePlaySoundMulti();
    for (size_t n = 0; n < _players->size(); n++) {
        if (_players->at(n)->isOnTile((int)(_model._position.z  - 0.5f),
        (int)_model._position.x, map->YOffset, map->XOffset)) {
            _players->at(n)->kill();
            _players->at(0)->_score += 100;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
    checkExplosionUp(map, _players, _AIplayers, ZPos, XPos, s);
    checkExplosionDown(map, _players,  _AIplayers,ZPos, XPos, s);
    checkExplosionLeft(map, _players,  _AIplayers,ZPos, XPos, s);
    checkExplosionRight(map, _players,  _AIplayers, ZPos, XPos, s);
}

bool Bomb::isCountdownFinished()
{
    std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();

    if (double(std::chrono::duration_cast<std::chrono::milliseconds>(now - _clock).count()) >= 500) {
        _model.tex = _tex_blink;
        _model.IndieSetMaterialTexture(0, *_model.tex);
    }
    if (double(std::chrono::duration_cast<std::chrono::milliseconds>(now - _clock).count()) >= 1000) {
        _model.tex = _tex;
        _model.IndieSetMaterialTexture(0, *_model.tex);
    }
    if (double(std::chrono::duration_cast<std::chrono::milliseconds>(now - _clock).count()) >= 1500) {
        _model.tex = _tex_blink;
        _model.IndieSetMaterialTexture(0, *_model.tex);
    }
    if (double(std::chrono::duration_cast<std::chrono::milliseconds>(now - _clock).count()) >= 2000) {
        _model.tex = _tex;
        _model.IndieSetMaterialTexture(0, *_model.tex);
    }
    if (double(std::chrono::duration_cast<std::chrono::milliseconds>(now - _clock).count()) >= 2500) {
        _model.tex = _tex_blink;
        _model.IndieSetMaterialTexture(0, *_model.tex);
    }
    if (double(std::chrono::duration_cast<std::chrono::milliseconds>(now - _clock).count()) >= 3000) {
        return true;
    }
    return false;
}
