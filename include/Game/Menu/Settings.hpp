/*
** EPITECH PROJECT, 2021
** sdfghjkl
** File description:
** kjhgfd
*/

#ifndef SETTINGS
#define SETTINGS

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
#include "../../Engine/Shapes/Line.hpp"
#include "./GameButton.hpp"

class Settings
{
    private:
        Window _window;
        Drawer _drawer;
        IndieMusic _music;
        IndieTextures _background;
        std::vector<GameButton<Settings>> _backButton;
        std::vector<GameButton<Settings>> _musicButton;
        std::vector<std::string> _listMusic;
        std::vector<IndieText> _listTexts;
        Misc _misc;
        bool _freed;
        float _volMusic;
        bool _needToClose;
        IndieRectangle _selectedButton;
        IndieRectangle _rectangle;
        IndieTextures _textureCursor;
        IndieLine _line;
        void GetMusicsFiles(void);
        int SetMusic(int);
        int SetVolume(int);
        int BackMenu(void);
        void drawSettingsMenu(void);
        void HandleClickButtons(void);
        int ChooseRandomMusic(void);
    public:
        Settings(IndieMusic, float);
        ~Settings(void);
        int SettingsMenu(void);
        IndieMusic getMusic(void);
        float getVolume(void);
};

#endif