/*
** EPITECH PROJECT, 2021
** sdfghjk
** File description:
** lkjhgf
*/

#ifndef PLAYER_CHOICE
#define PLAYER_CHOICE

#include "../../indie.hpp"
#include "../../Engine/Core/Window.hpp"
#include "../../Engine/Core/Drawer.hpp"
#include "../../Engine/Textures/Textures.hpp"
#include "../../Engine/Text/Text.hpp"
#include "../../Engine/Core/InputKey.hpp"
#include "./GameButton.hpp"
#include "../../Engine/Audio/Music.hpp"
#include "./PlayersInfo.hpp"
#include "./BoxText.hpp"
#include "../../Engine/Core/InputMouse.hpp"
#include "../../Engine/Core/InputKey.hpp"
#include "../../Engine/Shapes/CollisionChecker.hpp"

class PlayerChoice
{
    private:
        Window _window;
        Drawer _drawer;
        IndieMusic _music;
        float _volMusic;
        bool _needToClose;
        int _maxIdTexture;
        IndieTextures _background;
        std::vector<Skin> _listSkins;
        std::vector<PlayersInfo> _listPlayersInfo;
        std::vector<GameButton<PlayerChoice>> _lauchGame;
        std::vector<GameButton<PlayerChoice>> _listButtons;
        std::vector<GameButton<PlayerChoice>> _nbPlayerButtons;
        std::vector<BoxText> _listBoxTexts;
        int LaunchGame(void);
        void DrawPlayerChoice(void);
        int ChangeNbPlayers(int);
        int SelectSkin(PlayersInfo *, int);
        void SetWindowProperties(void);
        void MakeSkins(void);
        void MakeNbPlayerButtons(void);
        void MakeBoxText(void);
        void HandleClickButtons(void);
        void HandleBoxTexts(void);

    public:
        PlayerChoice(IndieMusic, float);
        ~PlayerChoice();
        int ChoicePlayer(void);
};

#endif