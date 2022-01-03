/*
** EPITECH PROJECT, 2021
** sdfghj
** File description:
** kjhgf
*/

#include "../../indie.hpp"
#include "../../Engine/Text/Text.hpp"
#include "../../Engine/Core/Window.hpp"
#include "../../Engine/Core/Drawer.hpp"
#include "../../Engine/Audio/Music.hpp"

class Credits
{
    private:
        Window _window;
        Drawer _drawer;
        IndieMusic _music;
        float _volMusic;
        bool _needToClose;
        std::vector<IndieText> _listTexts;
    public:
        Credits(IndieMusic, float);
        ~Credits();
        int PrintCredits(void);
};
