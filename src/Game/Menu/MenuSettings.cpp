/*
** EPITECH PROJECT, 2021
** sdfghjk
** File description:
** jhgfd
*/

#include "../../../include/Game/Menu/MainMenu.hpp"
#include "../../../include/Game/Menu/Settings.hpp"
#include "../../../include/indie.hpp"
#include "../../../include/Exceptions.hpp"
#include "../../../include/Game/Tools/DirectoryReader.hpp"
#include "../../../include/Game/Tools/Utilities.hpp"

int Settings::SetVolume(int i)
{
    i -= 500;
    _music.IndieSetMusicVolume((float) i / 1000);
    _volMusic = (float)i / 1000;
    return 0;
}

int Settings::SetMusic(int i)
{
    _music.IndieStopMusicStream();
    _music.IndieUnloadMusicStream();
    _music.IndieLoadMusicStream(MUSIC_PATH + _listMusic[i]);
    _music.IndiePlayMusicStream();
    _music.IndieSetMusicVolume(_volMusic);
    return 0;
}

void Settings::GetMusicsFiles(void)
{
    DirectoryReader reader(MUSIC_PATH);

    _listMusic = reader.getFiles();
    std::sort(_listMusic.begin(), _listMusic.end());
    for (size_t i = 0; i < _listMusic.size(); i++) {
        IndieText text("", WINDOW_WIDTH / 2 - 80, 400 + i * 80, 40, 10, BLACK);
        text.IndieSetNewText(removeExtension(_listMusic[i]));
        IndieRectangle rec(text);
        GameButton<Settings> button(text, rec, this, &Settings::SetMusic);
        _musicButton.push_back(button);
    }
}

int Settings::BackMenu(void)
{
    _window.closeWindow();
    _needToClose = false;
    return -1;
}

IndieMusic Settings::getMusic(void)
{
    return _music;
}

float Settings::getVolume(void)
{
    return _volMusic;
}

void Settings::drawSettingsMenu(void)
{
    _drawer.beginDrawing();
    _drawer.clearBackground(WHITE);
    _background.IndieDrawTexture();
    _line.IndieDrawLine();
    _textureCursor.IndieDrawTextureAdvanced();
    for (GameButton<Settings> &e : _musicButton)
        e.getText().IndieDrawText();
    for (GameButton<Settings> &e : _backButton) {
        e.getTexture().IndieDrawTextureAdvanced();
        e.getText().IndieDrawText();
    }
    for (IndieText &e : _listTexts)
        e.IndieDrawText();
    _drawer.endDrawing();
}

int Settings::ChooseRandomMusic(void)
{
    int i = rand() % _listMusic.size();

    _music.IndieStopMusicStream();
    _music.IndieUnloadMusicStream();
    _music.IndieLoadMusicStream(MUSIC_PATH + _listMusic[i]);
    _music.IndiePlayMusicStream();
    _music.IndieSetMusicVolume(_volMusic);
    return 0;
}

Settings::Settings(IndieMusic music, float volMusic) : _music(music), _selectedButton(0, 0, 0, 0, WHITE), _background(BACKGROUND_MENU, 0, 0, 0, 1, WHITE), _textureCursor("../ressource/Menu/Scroll.png", 500, 300, 0, 0.25, WHITE), _rectangle(500, 300, 100, 100, LIGHTGRAY), _line(Vector2({ 500, 300 }), Vector2({ 1500, 300 }), 30, BLACK)
{
    try {
        _window.checkWindow();
    } catch (const Exceptions &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
    _freed = false;
    _needToClose = true;
    _window.setWindowPosition(0, 0);
    _window.setWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    _window.setTargetFPS(TARGET_FPS);
    _window.setWindowTitle(WINDOW_TITLE);
    GetMusicsFiles();
    _volMusic = volMusic;
    _music.IndieSetMusicVolume(_volMusic);
    IndieTextures texture(BUTTON_TEXTURE, 300, 600, 0, 0.25, WHITE);
    IndieRectangle rec(texture);
    GameButton<Settings> button("Back", texture, rec, this, &Settings::BackMenu);
    _backButton.push_back(button);
    IndieTextures textureRandom(BUTTON_TEXTURE, 1500, 600, 0, 0.25, WHITE);
    IndieRectangle recRandom(textureRandom);
    GameButton<Settings> buttonRandom("Random", textureRandom, recRandom, this, &Settings::ChooseRandomMusic);
    _backButton.push_back(buttonRandom);
    IndieText texte0("0", 500, 200, 50, 30, RED);
    texte0.IndieSetNewText("0");
    IndieText texte1("100", 1450, 200, 50, 30, RED);
    texte1.IndieSetNewText("100");
    _listTexts.push_back(texte0);
    _listTexts.push_back(texte1);
    _textureCursor.IndieSetTexturePosition(1000 - _textureCursor.IndieGetTextureWidth() * _textureCursor.IndieGetTextureScale() / 2, 300 - _textureCursor.IndieGetTextureHeight() * _textureCursor.IndieGetTextureScale() / 2);
    _rectangle.IndieSetRectanglePos(1000 - _rectangle.IndieGetRectangleWidthHeight().first / 2, 300 - _rectangle.IndieGetRectangleWidthHeight().second / 2);
}

Settings::~Settings(void)
{
    _background.IndieUnloadTexture();
    for (GameButton<Settings> &e : _musicButton)
        e.getTexture().IndieUnloadTexture();
    if (_needToClose)
        _window.closeWindow();
}

void Settings::HandleClickButtons(void)
{
    CollisionChecker cc;
    InputMouse mouse;

    if (cc.IndieCheckCollisionPointRec(mouse.getMousePosition(), _rectangle.IndieGetRectangleRec())) {
        if (mouse.isMouseButtonDown(MOUSE_BUTTON_LEFT) && mouse.getMousePosition().x > 500 && mouse.getMousePosition().x < 1500) {
            _rectangle.IndieSetRectanglePos(mouse.getMousePosition().x - _rectangle.IndieGetRectangleWidthHeight().first / 2, 300 - _rectangle.IndieGetRectangleWidthHeight().second / 2);
            _textureCursor.IndieSetTexturePosition(mouse.getMousePosition().x - _textureCursor.IndieGetTextureWidth() / 2 * _textureCursor.IndieGetTextureScale(), 300 - _textureCursor.IndieGetTextureHeight() / 2 * _textureCursor.IndieGetTextureScale());
            SetVolume(_rectangle.IndieGetRectanglePos().first);
        }
    }
    for (GameButton<Settings> &e : _backButton) {
        if (cc.IndieCheckCollisionPointRec(mouse.getMousePosition(), e.getRectangle().IndieGetRectangleRec())) {
            e.getTexture().IndieSetTextureColor(RED);
            if (mouse.isMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                e.DoFunction();
            }
        } else {
            e.getTexture().IndieSetTextureColor(WHITE);
        }
    }
    for (size_t i = 0; i < _musicButton.size(); i++) {
        if (cc.IndieCheckCollisionPointRec(mouse.getMousePosition(), _musicButton[i].getRectangle().IndieGetRectangleRec())) {
            _musicButton[i].getText().IndieSetColor(RED);
            if (mouse.isMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                _musicButton[i].DoFunction(i);
            }
        } else {
            _musicButton[i].getText().IndieSetColor(BLACK);
        }
    }
}

int Settings::SettingsMenu(void)
{
    while (_window.keepWindowOpen()) {
        _misc.CheckScreenShotToTake();
        _music.IndieUpdateMusicStream();
        drawSettingsMenu();
        HandleClickButtons();
    }
    return 0;
}

int MainMenu::GoSettings(void)
{
    Settings setting(_music, _volMusic);

    setting.SettingsMenu();
    _music = setting.getMusic();
    _volMusic = setting.getVolume();
    return 0;
}