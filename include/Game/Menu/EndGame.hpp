/*
** EPITECH PROJECT, 2021
** sdfghjk
** File description:
** kjhgfd
*/

#include "../../indie.hpp"
#include "../../Engine/Text/Text.hpp"
#include "../../Engine/Core/Window.hpp"
#include "../../Engine/Core/Drawer.hpp"
#include "../../Engine/Audio/Music.hpp"
#include "../../Game/Menu/PlayersInfo.hpp"
#include "../../Game/Menu/GameButton.hpp"
#include "./FireWork.hpp"

class EndGame
{
    private:
        Window _window;
        Drawer _drawer;
        IndieMusic _music;
        PlayersInfo _PlayersWon;
        std::vector<IndieTextures> _listTextures;
        std::vector<IndieText> _lisTexts;
        std::vector<GameButton<EndGame>> _listButtons;
        std::vector<FireWork> _listFireWorks;
        float _volMusic;
        bool _needToClose;
        int GoBack(void);
    public:
        EndGame(IndieMusic, float, PlayersInfo);
        ~EndGame();
        int PrintEndGame(void);
};
