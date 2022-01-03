/*
** EPITECH PROJECT, 2021
** sdfghj
** File description:
** jhgfd
*/

#ifndef MENU
#define MENU

#include <vector>
#include "../../indie.hpp"
#include "../../Engine/Core/Window.hpp"
#include "../../Engine/Textures/Textures.hpp"
#include "../../Engine/Shapes/Rectangle.hpp"
#include "../../Engine/Text/Text.hpp"
#include "../../Engine/Core/Drawer.hpp"
#include "../../Engine/Audio/AudioManager.hpp"
#include "../../Engine/Audio/Music.hpp"
#include "../../Engine/Shapes/CollisionChecker.hpp"
#include "../../Engine/Core/InputMouse.hpp"
#include "../../Engine/Core/Misc.hpp"
#include "GameButton.hpp"

class MainMenu;

class MainMenu
{
    private:
        Window _window;
        Drawer _drawer;
        IndieAudioManager _audioManager;
        IndieMusic _music;
        IndieTextures _background;
        Misc _misc;
        std::vector<GameButton<MainMenu>> _listButton;
        bool _freed;
        float _volMusic;
        bool _needToReload;
        bool _needToCloseWindow;
        bool _needToUnload;
        void ReloadTexture(void);
        void UnloadTexture(void);
        void DrawMainMenu(void);
        void PutWindowProperties(void);
    public:
        MainMenu(void);
        ~MainMenu();
        int MenuWindow(void);
        int GoGame(void);
        int GoSettings(void);
        int GoLoadSave(void);
        int GoScreenShot(void);
        int GoQuit(void);
        int GoCredits(void);
};

#endif