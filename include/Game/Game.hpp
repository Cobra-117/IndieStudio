/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-adrien.michaud
** File description:
** Global
*/

#ifndef GLOBAL_HPP_
#define GLOBAL_HPP_

#include "Map.hpp"
#include "Player.hpp"
#include "Bombs/bomb.hpp"
#include "../Engine/Core/Window.hpp"
#include "../Engine/Core/Drawer.hpp"
#include "../Engine/Audio/Music.hpp"
#include "../Engine/Core/Misc.hpp"
#include "./Menu/PlayersInfo.hpp"
#include "../Game/Powerup/Powerup.hpp"

class Player;
class AIPlayer;
class Bomb;
class Powerup;

class Game {
    public:
        Game(IndieMusic, float, std::vector<PlayersInfo>);
        ~Game();
        int PlayGame(void);
        void display(void);
        void ManageAI();
        void Manage_Events();
        void Manage_Inputs();
        void ManageBombs();
        int GoEndGameScreen(int playerNbr);
        int isGameFinished();
    public:
        std::vector<Player *> _players;
        std::vector<AIPlayer *> _AIplayers;
        Map *_map;
        Window _window;
        Drawer _drawer;
        IndieMusic _music;
        std::vector<Powerup *> _powerups;
        Misc _misc;
        float _volMusic;
        std::vector<Bomb *> _PlacedBombs;
        std::vector<PlayersInfo> _listPlayer;
        std::chrono::steady_clock::time_point _main_clock;
        int _sec_clock = 0;
        int _min_clock = 0;
    protected:
    private:

};

#endif /* !GLOBAL_HPP_ */
