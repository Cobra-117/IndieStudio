/*
** EPITECH PROJECT, 2021
** sdfghjk
** File description:
** kjhgfds
*/

#include "../../../include/Game/Menu/MainMenu.hpp"
#include "../../../include/indie.hpp"
#include "../../../include/Exceptions.hpp"

int MainMenu::GoQuit(void)
{
    return -1;
}

MainMenu::MainMenu(void) : _music(DEFAULT_MUSIC), _background(BACKGROUND_MENU, 0, 0, 0, 1, WHITE)
{
    PutWindowProperties();
    _music.IndiePlayMusicStream();
    _volMusic = 0.5f;
    _music.IndieSetMusicVolume(_volMusic);
    IndieTextures buttonPlay(BUTTON_TEXTURE, WINDOW_WIDTH / 2, 400, 0, 0.25, WHITE);
    buttonPlay.IndieSetTexturePosition(WINDOW_WIDTH / 2 - (buttonPlay.IndieGetTextureWidth() * buttonPlay.IndieGetTextureScale()) / 2, buttonPlay.IndieGetTexturePosY());
    IndieRectangle rectanglePlay(buttonPlay);
    IndieTextures buttonLoadSave(BUTTON_TEXTURE, WINDOW_WIDTH / 2, 500, 0, 0.25, WHITE);
    buttonLoadSave.IndieSetTexturePosition(WINDOW_WIDTH / 2 - (buttonLoadSave.IndieGetTextureWidth() * buttonLoadSave.IndieGetTextureScale()) / 2, buttonLoadSave.IndieGetTexturePosY());
    IndieRectangle rectangleLoadSave(buttonLoadSave);
    IndieTextures buttonSettings(BUTTON_TEXTURE, WINDOW_WIDTH / 2, 600, 0, 0.25, WHITE);
    buttonSettings.IndieSetTexturePosition(WINDOW_WIDTH / 2 - (buttonSettings.IndieGetTextureWidth() * buttonSettings.IndieGetTextureScale()) / 2, buttonSettings.IndieGetTexturePosY());
    IndieRectangle rectangleSettings(buttonSettings);
    IndieTextures buttonScreenShot(BUTTON_TEXTURE, WINDOW_WIDTH / 2, 700, 0, 0.25, WHITE);
    buttonScreenShot.IndieSetTexturePosition(WINDOW_WIDTH / 2 - (buttonScreenShot.IndieGetTextureWidth() * buttonScreenShot.IndieGetTextureScale()) / 2, buttonScreenShot.IndieGetTexturePosY());
    IndieRectangle rectangleScreenShot(buttonScreenShot);
    IndieTextures buttonCredits(BUTTON_TEXTURE, WINDOW_WIDTH / 2, 800, 0, 0.25, WHITE);
    buttonCredits.IndieSetTexturePosition(WINDOW_WIDTH / 2 - (buttonCredits.IndieGetTextureWidth() * buttonCredits.IndieGetTextureScale()) / 2, buttonCredits.IndieGetTexturePosY());
    IndieRectangle rectangleCredits(buttonCredits);
    IndieTextures buttonQuit(BUTTON_TEXTURE, WINDOW_WIDTH / 2, 900, 0, 0.25, WHITE);
    buttonQuit.IndieSetTexturePosition(WINDOW_WIDTH / 2 - (buttonQuit.IndieGetTextureWidth() * buttonQuit.IndieGetTextureScale()) / 2, buttonQuit.IndieGetTexturePosY());
    IndieRectangle rectangleQuit(buttonQuit);
    _freed = false;
    _needToReload = false;
    _needToCloseWindow = true;
    GameButton<MainMenu> button1("Play", buttonPlay, rectanglePlay, this, &MainMenu::GoGame);
    GameButton<MainMenu> button2("Load Save", buttonLoadSave, rectangleLoadSave, this, &MainMenu::GoLoadSave);
    GameButton<MainMenu> button3("Settings", buttonSettings, rectangleSettings, this, &MainMenu::GoSettings);
    GameButton<MainMenu> button4("ScreenShots", buttonScreenShot, rectangleScreenShot, this, &MainMenu::GoScreenShot);
    GameButton<MainMenu> button5("Credits", buttonCredits, rectangleCredits, this, &MainMenu::GoCredits);
    GameButton<MainMenu> button6("Quit", buttonQuit, rectangleQuit, this, &MainMenu::GoQuit);
    _listButton.push_back(button1);
    _listButton.push_back(button2);
    _listButton.push_back(button3);
    _listButton.push_back(button4);
    _listButton.push_back(button5);
    _listButton.push_back(button6);
    _needToUnload = true;
}

void MainMenu::PutWindowProperties(void)
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

void MainMenu::ReloadTexture(void)
{
    if (_needToReload) {
        _background.IndieLoadNewTexture(BACKGROUND_MENU);
        for (GameButton<MainMenu> &e : _listButton)
            e.getTexture().IndieLoadNewTexture(BUTTON_TEXTURE);
        _needToReload = false;
        _needToUnload = true;
    }
}

void MainMenu::UnloadTexture(void)
{
    _background.IndieUnloadTexture();
    for (GameButton<MainMenu> &e : _listButton)
        e.getTexture().IndieUnloadTexture();
    _needToUnload = false;
}

void MainMenu::DrawMainMenu(void)
{
    _drawer.beginDrawing();
    _drawer.clearBackground(WHITE);
    _background.IndieDrawTexture();
    for (GameButton<MainMenu> &e : _listButton) {
        e.getTexture().IndieDrawTextureAdvanced();
        e.getText().IndieDrawText();
    }
    _drawer.endDrawing();
}

MainMenu::~MainMenu(void)
{
    if (_needToUnload)
        UnloadTexture();
    _listButton.clear();
    _music.IndieUnloadMusicStream();
    _audioManager.IndieCloseAudioDevice();
    if (_needToCloseWindow)
        _window.closeWindow();
}

int MainMenu::MenuWindow(void)
{
    CollisionChecker cc;
    InputMouse mouse;

    while (_window.keepWindowOpen()) {
        ReloadTexture();
        _music.IndieUpdateMusicStream();
        DrawMainMenu();
        _misc.CheckScreenShotToTake();
        for (GameButton<MainMenu> &e : _listButton) {
            if (cc.IndieCheckCollisionPointRec(mouse.getMousePosition(), e.getRectangle().IndieGetRectangleRec())) {
                e.getTexture().IndieSetTextureColor(RED);
                if (mouse.isMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    UnloadTexture();
                    _window.closeWindow();
                    _needToCloseWindow = false;
                    _needToUnload = false;
                    if (e.DoFunction() == -1)
                        return 0;
                    _window.reopenWindow();
                    PutWindowProperties();
                    _needToReload = true;
                    _needToCloseWindow = true;
                }
            } else {
                e.getTexture().IndieSetTextureColor(WHITE);
            }
        }
    }
    return 0;
}