/*
** EPITECH PROJECT, 2021
** sdfghjk
** File description:
** jhgfds
*/

#include "../../include/Game/Game.hpp"
#include "../../include/Game/Menu/MainMenu.hpp"
#include "../../include/Exceptions.hpp"
#include "../../include/Game/Menu/PlayerChoice.hpp"
#include "../../include/Game/Menu/EndGame.hpp"
#include "../../include/Game/Powerup/Powerup.hpp"

Game::~Game()
{
    delete(_map);
    for (std::vector<Player *>::iterator i = _players.begin(); i != _players.end(); ++i) {
        delete *i;
    }
    for (std::vector<AIPlayer *>::iterator i = _AIplayers.begin(); i != _AIplayers.end(); ++i) {
        delete *i;
    }
}

void Game::display(void)
{
    int i = 20;

    _drawer.beginDrawing();
    _drawer.clearBackground(WHITE);
    _drawer.beginMode3D();
    for (size_t i = 0; i < _players.size(); i++)
        if (_players[i]->_isActive)
            _players[i]->_model.IndieDrawEx(-90.0f, WHITE);
    for (size_t i = 0; i < _AIplayers.size(); i++)
        if (_AIplayers[i]->_isActive)
            _AIplayers[i]->_model.IndieDrawEx(-90.0f, WHITE);
    for (size_t i = 0; i < _powerups.size(); i++)
        _powerups[i]->_model.IndieDrawEx(-90.0f, WHITE);
    //_players[0]->_model.IndieDrawEx(-90.0f, WHITE);
    _map->display();
    for (size_t i = 0; i < _PlacedBombs.size(); i++)
        _PlacedBombs[i]->_model.IndieDrawEx(90.0f, WHITE);
    DrawGrid(15, 1.0f);
    _drawer.endMode3D();
    for (size_t n = 0; n < _players.size(); n++) {
        DrawText(FormatText("Score J-%i : %i", (n + 1), _players.at(n)->_score), 10, i, 30, BLACK);
        i += 50;
    }
    DrawText(FormatText("%i : %i", _min_clock, _sec_clock), 1700, 20, 30, BLACK);
    _drawer.endDrawing();
}

int Game::isGameFinished()
{
    int winner = -1;

    for (size_t i = 0; i < _players.size(); i++) {
        if (_players[i]->_isActive == true && winner != -1) {
            return -1;
        }
        else if (_players[i]->_isActive == true) {
            winner = i + 1;
        }
    }
    for (size_t i = 0; i < _AIplayers.size(); i++) {
        if (_AIplayers[i]->_isActive == true && winner != -1) {
            return -1;
        }
        else if (_AIplayers[i]->_isActive == true) {
            winner = i + 1 + _players.size();
        }
    }
    return (winner);
}

int Game::PlayGame(void)
{
    int winner = 0;
    _window.setWindowPosition(0, 0);
    _window.setWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    _window.setTargetFPS(TARGET_FPS);
    _window.setWindowTitle(WINDOW_TITLE);
    for (int i = 0; i < 4; i++) {
        if (this->_listPlayer[i].getIsHuman() == true)
            _players.push_back(new Player(this->_listPlayer[i].getIdTexture(), i, true));
        else {
           _AIplayers.push_back(new AIPlayer(this->_listPlayer[i].getIdTexture(), i, _AIplayers.size()));
        }
    }
    _map = new Map();
    _map->generateRandomMap(13, 13, 50);
    _main_clock = std::chrono::steady_clock::now();
    while (_window.keepWindowOpen()) {
        _misc.CheckScreenShotToTake();
        _music.IndieUpdateMusicStream();
        Manage_Events();
        display();
        std::chrono::steady_clock::time_point mainTime = std::chrono::steady_clock::now();
        if (double(std::chrono::duration_cast<std::chrono::seconds>(mainTime - _main_clock).count()) >= 1) {
            for (size_t n = 0; n < _players.size(); n++) {
                _players.at(n)->_score += 1;
            }
            _sec_clock += 1;
            if (_sec_clock == 60) {
                _sec_clock = 0;
                _min_clock += 1;
            }
            _main_clock = std::chrono::steady_clock::now();
        }
        if (_sec_clock % 30 == 0) {
            _powerups.clear();
            for (int i = 0; i < 4; i++) {
                float rx = 0 + static_cast <float> (rand()%(5 - 0 + 1) + 0);
                int isNegX = rand()%2;
                if (isNegX == 0)
                    rx *= -1;
                float rz = 0 + static_cast <float> (rand()%(5 - 0 + 1) + 0);
                int isNegZ = rand()%2;
                if (isNegZ == 0)
                    rz *= -1;
                Vector3 _powerPos = {rx, 0.0f, rz};
                _powerups.push_back(new Powerup(rand()%(8-1 + 1) + 1, _powerPos, &_players, &_PlacedBombs, _map, &_AIplayers));
            }
        }
        for (int i = 0; i < _powerups.size(); i++) {
            if (_powerups[i]->checkPowerup(&_players, &_PlacedBombs, _map, &_AIplayers) == 1)
                _powerups.erase(_powerups.begin() + i);
        }
        winner = isGameFinished();

        InputKey key;
        if (winner != -1 || key.isKeyDown(KEY_N))//debug
            break;
    }
    _window.closeWindow();
    return(winner);
}

Game::Game(IndieMusic music, float volume, std::vector<PlayersInfo> list) : _music(music)
{
    try {
        _window.checkWindow();
    } catch (const Exceptions &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
    _window.setWindowPosition(0, 0);
    _window.setWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    _window.setTargetFPS(TARGET_FPS);
    _window.setWindowTitle(WINDOW_TITLE);
    _music.IndieSetMusicVolume(volume);
    _drawer.setCamera3DPosition(Vector3({ 0.0f, 15.0f, 7.0f }));
    _listPlayer = list;
}

int Game::GoEndGameScreen(int playerNbr)
{
    int playerListIndex;

    if (playerNbr == 0)
        playerListIndex = playerNbr;
    else if (playerNbr == 100 || playerNbr == 101)
        playerListIndex = playerNbr - 99;
    else if (playerNbr == 102 || playerNbr == 3)
        playerListIndex = 3;
    EndGame end_game(_music, _volMusic, _listPlayer[playerListIndex]);

    end_game.PrintEndGame();
    return 0;
}

int PlayerChoice::LaunchGame(void)
{
    int winner = -1;
    Game game(_music, _volMusic, _listPlayersInfo);

    winner = game.PlayGame();
    if (winner == -1)
        winner = 0;
    std::cout << "fin de jeu" << std::endl;
    game.GoEndGameScreen(winner);
    std::cout << "end" << std::endl;
    return 0;
}
