/*
** EPITECH PROJECT, 2021
** sdfghjk
** File description:
** jhgfds
*/

#include "../../../include/Game/Menu/MainMenu.hpp"
#include "../../../include/indie.hpp"
#include "../../../include/Exceptions.hpp"

int MainMenu::GoLoadSave(void)
{
    Window window(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

    try {
        window.checkWindow();
    } catch (const Exceptions &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    while (window.keepWindowOpen()) {
        window.clearWindow(BLUE);
    }
    return 0;
}