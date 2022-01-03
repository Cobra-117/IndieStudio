/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-adrien.michaud
** File description:
** Events
*/

#include "../../include/Game/Game.hpp"
#include "../../include/Engine/Core/InputKey.hpp"

void Game::ManageBombs()
{
    for (size_t i = 0; i < _PlacedBombs.size(); i++) {
        if (!_PlacedBombs[i]->isCountdownFinished())
            continue;
        _PlacedBombs[i]->explode(_map, &_players, &_AIplayers);
        delete _PlacedBombs[i];
        _PlacedBombs.erase(_PlacedBombs.begin() + i);
    }
}

void Game::Manage_Inputs()
{
    InputKey key;

    if (_players[0]->isActive()) {
        if (key.isKeyDown(KEY_W))
            _players[0]->move(0, _map);
        if (key.isKeyDown(KEY_D))
            _players[0]->move(1, _map);
        if (key.isKeyDown(KEY_A))
            _players[0]->move(2, _map);
        if (key.isKeyDown(KEY_S))
            _players[0]->move(3, _map);
        if (key.isKeyPressed(KEY_SPACE))
            _players[0]->placeBomb(this);
    }
    if (_players.size() > 1 && _players[1]->isActive()) {
        if (key.isKeyDown(KEY_UP))
            _players[1]->move(0, _map);
        if (key.isKeyDown(KEY_RIGHT))
            _players[1]->move(1, _map);
        if (key.isKeyDown(KEY_LEFT))
            _players[1]->move(2, _map);
        if (key.isKeyDown(KEY_DOWN))
            _players[1]->move(3, _map);
        if (key.isKeyPressed(KEY_ENTER))
            _players[1]->placeBomb(this);
    }
}

void Game::ManageAI()
{
    for (int i = 0; i < _AIplayers.size(); i++) {
        if (_AIplayers[i]->isActive() && _AIplayers[i]->_isHuman == false) {
            _AIplayers[i]->AI(this);
        }
    }
}

void Game::Manage_Events()
{
    Manage_Inputs();
    ManageBombs();
    ManageAI();
}

