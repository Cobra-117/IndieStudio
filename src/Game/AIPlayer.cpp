/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-adrien.michaud
** File description:
** AIPlayer
*/

#include <cmath>
#include "../../include/Game/Player.hpp"
#include "../../include/indie.hpp"
#include "../../include/Game/Tools/DirectoryReader.hpp"

AIPlayer::AIPlayer(int texId, int corner, int id) : Player(texId, corner, false)
{
    _lastMovement = -1;
    _targetedPlayer = -1;
    _id = id;
}

void AIPlayer::rushTarget(Game *game)
{
    if (_targetedPlayer >= 100) {
        _TargetPos.x = game->_AIplayers[_targetedPlayer - 100]->_model._position.x;
        _TargetPos.y = game->_AIplayers[_targetedPlayer - 100]->_model._position.y;
    }
    if (std::abs(_model._position.x - _TargetPos.x) < 0.5f && 
    std::abs(_model._position.z - _TargetPos.y) < 0.5f)
        return;
    if (std::abs(_model._position.z - _TargetPos.y) > std::abs(_model._position.x - _TargetPos.x))
    {
        if (_model._position.z < _TargetPos.y)
            AIMove(0, game->_map);
        else
            AIMove(3, game->_map);
    }
    else {
         if (_model._position.x < _TargetPos.x)
            AIMove(2, game->_map);
        else
            AIMove(1, game->_map);
    }
}

void AIPlayer::chooseTarget(Game *game)
{
    _targetedPlayer = rand() % 4;
    if (_targetedPlayer == _id)
        chooseTarget(game);
    std::cout << "targeted before " << _targetedPlayer << std::endl;
    if (_targetedPlayer == 3) {
        if (game->_players.size() == 1)
            _targetedPlayer = 102;
        else
            _targetedPlayer = 1;
        return;
    }
    if (_targetedPlayer == 1 || _targetedPlayer == 2) {
        _targetedPlayer += 99;
    }
}

void AIPlayer::AIMove(int dir, Map *map)
{
    _lastMovement = dir;
    move(dir, map);
    if (dir == 0)
        targetCase = round(_model._position.z + map->YOffset - 0.5f);
    if (dir == 1)
        targetCase = round(_model._position.x + map->XOffset + 1);
    if (dir == 2)
        targetCase = round(_model._position.x + map->XOffset - 1);
    if (dir == 3)
        targetCase = round(_model._position.z + map->YOffset - 0.5f + 1);
    std::cout << "model z" << _model._position.z + map->YOffset << std::endl;
    std::cout << "moved" << std::endl;
    std::cout << "dir " << dir << std::endl;
}

void AIPlayer::finishCase(Map *map)
{
    if (_lastMovement == 0) {
        std::cout << "model z" << _model._position.z + map->YOffset << std::endl;
        std::cout << "case z" << round(_model._position.z + map->YOffset - 0.5f) << std::endl;
        std::cout << "target case" << targetCase << std::endl;
        if (_model._position.z + map->YOffset <=
        targetCase) {
            std::cout << "Is equal" << std::endl;
            return;
        }
        else
            move(0, map);   
    }
    if (_lastMovement == 1) {
        std::cout << "model x" << _model._position.x + map->XOffset << std::endl;
        std::cout << "case z" << round(_model._position.z + map->YOffset - 0.5f) << std::endl;
        std::cout << "target case" << targetCase << std::endl;
        if (_model._position.x + map->XOffset >=
        targetCase) {
            std::cout << "Is equal" << std::endl;
            return;
        }
        else
            move(1, map);    
    }
    if (_lastMovement == 2) {
        std::cout << "model x" << _model._position.x + map->XOffset << std::endl;
        std::cout << "case z" << round(_model._position.z + map->YOffset - 0.5f) << std::endl;
        std::cout << "target case" << targetCase << std::endl;
        if (_model._position.x + map->XOffset <=
        targetCase) {
            std::cout << "Is equal" << std::endl;
            return;
        }
        else
            move(2, map);
    }
    if (_lastMovement == 3) {
        std::cout << "model z" << _model._position.z + map->YOffset << std::endl;
        std::cout << "case z" << round(_model._position.z + map->YOffset - 0.5f) << std::endl;
        std::cout << "target case" << targetCase << std::endl;
        if (_model._position.z + map->YOffset >=
        targetCase) {
            std::cout << "Is equal" << std::endl;
            _model._position.z = targetCase - map->YOffset; 
            return;
        }
        else
            move(3, map);
    }

}

void AIPlayer::stupidMode(Game *game)
{
    static int i = 0;
    static int dir =-1;
    if (i == 0)
        dir  = (rand() % 4);
    if (i < 50) {
        AIMove(dir, game->_map);
        i++;
    }
    if (i >= 50)
        i = 0;
}

void AIPlayer::AI(Game *game)
{
    static int debug = 0;
    static int isstupidMode = 1;
    std::cout << "x " << _model._position.x << std::endl;
    std::cout << "x2 " << round(_model._position.x) << std::endl;
    std::cout << "z " << _model._position.z  << std::endl;
    std::cout << "z2 " << round(_model._position.z) << std::endl;
    stupidMode(game);
    return;
    if (debug == 0) {
        AIMove(3, game->_map);
        debug = 1;
    }
    srand(time(NULL));
    if (_model._position.x != round(_model._position.x) ||
    _model._position.z != round(_model._position.z)) {
        if (_model._position.x != round(_model._position.x))
            std::cout << "x not equal" << std::endl;
        if (_model._position.z !=round(_model._position.z)) {
            std::cout << "z not equal" << std::endl;
            std::cout << "first " << _model._position.z << std::endl;
            std::cout << "second " << round(_model._position.z) << std::endl;
            std::cout << "calcul " <<
            _model._position.z - round(_model._position.z) << std::endl;
            std::cout << "calcul2 " <<
            std::abs(_model._position.z -round(_model._position.z)) << std::endl;
        }
        finishCase(game->_map);
        std::cout << "returned here" << std::endl;
        return;
    }
    //stupidMode(game);
    /*if (_targetedPlayer == - 1)
        chooseTarget(game);
    else
        rushTarget(game);*/
    std::cout << "target " << _targetedPlayer << std::endl;
}