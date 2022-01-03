/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-adrien.michaud
** File description:
** Player
*/

#include <cmath>
#include "../../include/Game/Player.hpp"
#include "../../include/indie.hpp"
#include "../../include/Game/Tools/DirectoryReader.hpp"

Player::Player(int texId, int corner, bool isHuman)
{
    DirectoryReader reader(SKINS_PATH);
    std::vector<std::string> files = reader.getFiles();
    std::string texPath = PLAYER_TEX + files[texId];
    _model.tex = new IndieTextures(texPath, 0, 0, 0, 1, WHITE);
    _model.loadFromFile(PLAYER_MOD);
    _model.IndieSetMaterialTexture(0, *_model.tex);
    _model.IndieLoadModelAnimations("../ressource/3DModels/players/walking_animation.iqm", &this->_animCount);
    if (corner == 0)
        _model._position = {-6.0f, 0.0f, -8.0f };
    if (corner == 1)
        _model._position = {6.0f, 0.0f, -8.0f };
    if (corner == 2)
        _model._position = {-6.0f, 0.0f, 4.0f };
    if (corner == 3)
        _model._position = {6.0f, 0.0f, 4.0f };
    _model._rotationAxis = { 1.0f, 0.0f, 0.0f };
    _model._scale = {0.1f, 0.1f, 0.1f };
    _isActive = true;
    _isHuman = isHuman;
    _collider.SetUp(0.6f);
    _collider.SetDown(0.3f);
    _collider.SetLeft(0.1f);
    _collider.SetRight(0.1f);
}

Player::~Player()
{
    for (int i = 0; i < _animCount; i++)
        _model.IndieUnloadModelAnimation(_model._animation[i]);
    RL_FREE(_model._animation);
    _model.tex->IndieUnloadTexture();
}

void Player::move(int dir, Map *map)
{
    _animFrameCounter++;
    _model.IndieUpdateModelAnimation(_animFrameCounter);
    if (_animFrameCounter >= _model._animation[0].frameCount)
        _animFrameCounter = 0;
    _model.IndieDrawEx(-90.0f, WHITE);
    switch (dir) {
    case 0:
        _model._position.z -= PLAYERSPEED;
        _model.IndieModelRotation(Vector3({ 0, 0, 180 }));
        checkCollisionUp(map);
        break;
    case 1:
        _model._position.x += PLAYERSPEED;
        _model.IndieModelRotation(Vector3({ 0, 0, 90 }));
        checkCollisionRight(map);
        break;
    case 2:
        _model._position.x -= PLAYERSPEED;
        _model.IndieModelRotation(Vector3({ 0, 0, -90 }));
        checkCollisionLeft(map);
        break;
    case 3:
        _model._position.z += PLAYERSPEED;
        _model.IndieModelRotation(Vector3({ 0, 0, 0 }));
        checkCollisionDown(map);
        break;
    default:
        break;
    }
}

void Player::placeBomb(Game *game)
{
    Bomb *bomb = new Bomb();

    bomb->_clock = std::chrono::steady_clock::now();
    Vector3 BombPosition {(float)round(_model._position.x), 0.5f
    , (float)round(_model._position.z)};
    bomb->_model.setPosition(BombPosition);
    game->_PlacedBombs.push_back(bomb);
}

void Player::kill()
{
    _model._position.x = -10;
    _isActive = false;
}

bool Player::isOnTile(int y, int x, int yOffset, int xOffset)
{
    if (ceil(_model._position.x + xOffset) == x + xOffset
    && ceil(_model._position.z + yOffset) == y + yOffset)
        return true;
    if (ceil(_model._position.x + xOffset) == x  + xOffset
    && trunc(_model._position.z + yOffset) == y + yOffset)
        return true;
    if (trunc(_model._position.x + xOffset) == x + xOffset 
    && ceil(_model._position.z + yOffset) == y + yOffset)
        return true;
    if (trunc(_model._position.x + xOffset) == x + xOffset 
    && trunc(_model._position.z + yOffset) == y + yOffset)
        return true;
    return false;
}

void Player::checkCollisionRight(Map *map)
{
    size_t ZPos = (size_t)(_model._position.z + map->YOffset);
    size_t XPos = (size_t)((_model._position.x + map->XOffset));

    if (_model._position.x + map->XOffset - _collider.GetRight() > map->_length - 1 + 0.3f) {
        _model._position.x =  map->_length - map->XOffset + _collider.GetRight() - 1 + 0.3f;
        return;
    }
    if (_model._position.x +  map->XOffset < 0)
        return;
    if (map->_ascii_map[ZPos][XPos + 1] == '#'||map->_ascii_map[ZPos][XPos + 1] == 'x')
    if ((map->_ascii_map[ZPos][XPos + 1] == '#'||map->_ascii_map[ZPos][XPos + 1] == 'x')
    && (_model._position.z +  map->YOffset) - ZPos < _collider.GetUp() - 0.1f
    && _model._position.x + map->XOffset - 0.3f > floor(_model._position.x + map->XOffset) + _collider.GetLeft() ) {
       _model._position.x -= PLAYERSPEED;
        return;
    }
    if (_model._position.z + map->YOffset >= map->_heigth - 1)
        return;
    if (map->_ascii_map[ZPos + 1][XPos + 1] == '#'|| map->_ascii_map[ZPos + 1][XPos + 1] == 'x')
    if ((map->_ascii_map[ZPos + 1][XPos + 1] == '#'||map->_ascii_map[ZPos + 1][XPos + 1] == 'x')
    && (_model._position.z +  map->YOffset) - ZPos > _collider.GetUp()
    && _model._position.x + map->XOffset - 0.3f > floor(_model._position.x + map->XOffset) + _collider.GetLeft() ) {
       _model._position.x -= PLAYERSPEED;
        return;
    }
}

void Player::checkCollisionDown(Map *map)
{
    size_t ZPos = (size_t)(_model._position.z + map->YOffset);
    size_t XPos = (size_t)((_model._position.x + map->XOffset));

    if (_model._position.z + map->YOffset - _collider.GetDown() > map->_heigth - 1) {
        _model._position.z =  map->_heigth - map->YOffset + _collider.GetDown() - 1;
        return;
    }
    if (ZPos ==  map->_heigth - 1)
        return;
    if (map->_ascii_map[ZPos + 1][XPos] == '#'||map->_ascii_map[ZPos + 1][XPos] == 'x')
    if ((map->_ascii_map[ZPos + 1][XPos] == '#'||map->_ascii_map[ZPos + 1][XPos] == 'x')
    && (_model._position.x +  map->XOffset) - XPos < 0.5f + _collider.GetLeft()
    && _model._position.z + map->YOffset > floor(_model._position.z + map->YOffset) + _collider.GetDown()) {
        _model._position.z -= PLAYERSPEED;
        return;
    }
    if ((map->_ascii_map[ZPos + 1][XPos + 1] == '#'||map->_ascii_map[ZPos + 1][XPos + 1] == 'x')
    && (_model._position.x +  map->XOffset) - XPos > 0.5f - _collider.GetRight()
    && _model._position.z + map->YOffset > floor(_model._position.z + map->YOffset) + _collider.GetDown()) {
        _model._position.z -= PLAYERSPEED;
        return;
    }
    return;
}

void Player::checkCollisionLeft(Map *map)
{
    size_t ZPos = (size_t)(_model._position.z + map->YOffset);
    size_t XPos = (size_t)((_model._position.x + map->XOffset));

    if (_model._position.x + map->XOffset - (_collider.GetLeft() + 0.5f)  < -1) {
        _model._position.x = - map->XOffset + (_collider.GetLeft() + 0.5f) - 1;
        return;
    }
    if ((map->_ascii_map[ZPos][XPos] == '#'|| map->_ascii_map[ZPos][XPos] == 'x')
    && (_model._position.z +  map->YOffset) - ZPos < _collider.GetUp()
    && _model._position.x + map->XOffset - _collider.GetLeft() - 0.5f < ceil(_model._position.x - 1 + map->XOffset)) {
        _model._position.x += PLAYERSPEED;
        return;
    }
    if (_model._position.z + map->YOffset >= map->_heigth - 1)
        return;
    if (map->_ascii_map[ZPos + 1][XPos] == '#'||map->_ascii_map[ZPos + 1][XPos] == 'x')
    if ((map->_ascii_map[ZPos + 1][XPos] == '#'|| map->_ascii_map[ZPos + 1][XPos] == 'x')
    && (_model._position.z +  map->YOffset) - ZPos > _collider.GetUp()
    && _model._position.x + map->XOffset - _collider.GetLeft() - 0.5f < ceil(_model._position.x - 1 + map->XOffset)) {
        _model._position.x += PLAYERSPEED;
        return;
    }
}

void Player::checkCollisionUp(Map *map)
{
    size_t ZPos = (size_t)(_model._position.z + map->YOffset);
    size_t XPos = (size_t)((_model._position.x + map->XOffset));
    float XPosF = _model._position.x + map->XOffset;

    if (_model._position.z + map->YOffset - _collider.GetUp() < -1) {
        _model._position.z = - map->YOffset + _collider.GetUp() - 1;
        return;
    }
    if (ZPos == 0)
        return;
    if ((map->_ascii_map[ZPos][XPos] == '#'||map->_ascii_map[ZPos][XPos] == 'x')
    && (_model._position.x +  map->XOffset) - XPos < 0.5f + _collider.GetLeft()
    && _model._position.z + map->YOffset - _collider.GetUp() < ceil(_model._position.z - 1 + map->YOffset)) {
        _model._position.z += PLAYERSPEED;
        return;
    }
    if ((map->_ascii_map[ZPos][XPos + 1] == '#'|| map->_ascii_map[ZPos][XPos + 1] == 'x')
    && (_model._position.x +  map->XOffset) - XPos > 0.5f - _collider.GetRight()
    && _model._position.z + map->YOffset - _collider.GetUp() < ceil(_model._position.z - 1 + map->YOffset)) {
        _model._position.z += PLAYERSPEED;
        return;
    }
}

bool Player::isActive()
{
    return (_isActive);
}
