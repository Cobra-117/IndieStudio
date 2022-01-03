/*
** EPITECH PROJECT, 2021
** sdfghjk
** File description:
** kjhgfd
*/

#include "../../../include/Game/Menu/ScreenShot.hpp"
#include "../../../include/Game/Menu/MainMenu.hpp"
#include "../../../include/Exceptions.hpp"
#include "../../../include/Game/Tools/DirectoryReader.hpp"

ScreenShot::ScreenShot()
{
    try {
        _window.checkWindow();
    } catch (const Exceptions &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
    _window.setWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    _window.setWindowPosition(0, 0);
    _window.setWindowTitle(WINDOW_TITLE);
    _window.setTargetFPS(TARGET_FPS);
}

int ScreenShot::MenuScreenShot(void)
{
    DirectoryReader reader(SCREENSHOT_PATH);
    std::vector<std::string> list = reader.getFiles();
    std::vector<IndieTextures> textures;
    int j = 0;
    int x = 0;

    for (size_t i = 0; i < list.size(); i++, x++) {
        IndieTextures a(SCREENSHOT_PATH + list[i], 10, 50, 0, 0.32, WHITE);
        if (i == 3) {
            j++;
            x = 0;
        }
        a.IndieSetTexturePosition(10 + x * 640, 100 + j * 500);
        textures.push_back(a);
    }

    while (_window.keepWindowOpen()) {
        _drawer.beginDrawing();
        _drawer.clearBackground(RED);
        for (IndieTextures &e : textures)
            e.IndieDrawTextureAdvanced();
        _drawer.endDrawing();
        _misc.CheckScreenShotToTake();
    }
    _window.closeWindow();
    return 0;
}

int MainMenu::GoScreenShot(void)
{
    ScreenShot screen;

    screen.MenuScreenShot();
    return 0;
}