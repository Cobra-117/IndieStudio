/*
** EPITECH PROJECT, 2021
** sdfghjk
** File description:
** kjhgfds
*/

#include "../../../include/Game/Menu/EndGame.hpp"
#include "../../../include/Exceptions.hpp"
#include "../../../include/Game/Tools/DirectoryReader.hpp"
#include "../../../include/Engine/Shapes/Rectangle.hpp"
#include "../../../include/Engine/Core/InputMouse.hpp"
#include "../../../include/Engine/Shapes/CollisionChecker.hpp"

EndGame::EndGame(IndieMusic music, float volume, PlayersInfo player) : _music(music), _PlayersWon(player)
{
    IndieSound s("../ressource/Musics/SoundEffects/you_win.mp3");
    s.IndiePlaySoundMulti();
    try {
        _window.checkWindow();
    } catch (const Exceptions &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
    _needToClose = true;
    _window.setWindowPosition(0, 0);
    _window.setWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    _window.setTargetFPS(TARGET_FPS);
    _window.setWindowTitle(WINDOW_TITLE);
    _volMusic = volume;
    _music.IndieSetMusicVolume(_volMusic);
    _music.IndiePlayMusicStream();
    _needToClose = true;
    IndieTextures texture(BACKGROUND_MENU, 0, 0, 0, 1, WHITE);
    _listTextures.push_back(texture);
    DirectoryReader reader(SKINS_PATH);
    std::string skinName = reader.getFiles()[player.getIdTexture()];
    IndieTextures skin(SKINS_PATH + skinName, 0, 0, 0, 1, WHITE);
    skin.IndieSetTexturePosition(WINDOW_WIDTH / 2 - skin.IndieGetTextureWidth() / 2, 150);
    _listTextures.push_back(skin);
    IndieText texte("", 0, 0, 50, 30, BLACK);
    texte.IndieSetNewText("Congratulation " + player.getSimpleText().IndieGetText() + ", you won.");
    Vector2 vector = {525, 50};
    texte.IndieSetTextPosition(vector);
    _lisTexts.push_back(texte);
    IndieTextures textureButton(BUTTON_TEXTURE, 0, 0, 0, 0.25, WHITE);
    textureButton.IndieSetTexturePosition(WINDOW_WIDTH / 2 - textureButton.IndieGetTextureWidth() * textureButton.IndieGetTextureScale() / 2, 900);
    IndieRectangle recButton(textureButton);
    GameButton<EndGame> button("Back", textureButton, recButton, this, &EndGame::GoBack);
    _listButtons.push_back(button);

    std::vector<Color> vec{RED, BLUE, GREEN, BLACK, WHITE, GRAY, LIGHTGRAY, DARKGRAY, YELLOW, GOLD, ORANGE, PINK, MAROON, LIME, DARKGREEN, SKYBLUE, DARKBLUE, PURPLE, VIOLET, DARKPURPLE, BEIGE, BROWN, DARKBROWN};
    for (size_t i = 0; i < 10; i++) {
        FireWork firework(vec.at(rand() % vec.size()), rand() % 1920, rand() % 1080, 1);
        _listFireWorks.push_back(firework);
    }
}

int EndGame::GoBack(void)
{
    _window.closeWindow();
    _needToClose = false;
    return 0;
}

EndGame::~EndGame(void)
{
    if (_needToClose)
        _window.closeWindow();
}

int EndGame::PrintEndGame(void)
{
    IndieRectangle rec(_lisTexts[0]);
    rec.IndieSetRectangleColor(RED);
    InputMouse mouse;
    CollisionChecker cc;

    while (_window.keepWindowOpen()) {
        _music.IndieUpdateMusicStream();
        _drawer.beginDrawing();
        for (IndieTextures &e : _listTextures)
            e.IndieDrawTextureAdvanced();
        rec.IndieDrawRectangle();
        for (IndieText &e : _lisTexts)
            e.IndieDrawText();
        for (GameButton<EndGame> &e : _listButtons) {
            e.getTexture().IndieDrawTextureAdvanced();
            e.getText().IndieDrawText();
        }
        for (GameButton<EndGame> &e : _listButtons) {
            if (cc.IndieCheckCollisionPointRec(mouse.getMousePosition(), e.getRectangle().IndieGetRectangleRec())) {
                e.getTexture().IndieSetTextureColor(RED);
                if (mouse.isMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    e.DoFunction();
                    return 0;
                }
            } else {
                e.getTexture().IndieSetTextureColor(WHITE);
            }
        }
        for (FireWork &e : _listFireWorks) {
            e.DoAnimation();
        }
        _drawer.endDrawing();
    }
    return 0;
}
