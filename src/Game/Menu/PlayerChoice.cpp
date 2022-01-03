/*
** EPITECH PROJECT, 2021
** sdfjkl
** File description:
** kjhgfd
*/

#include "../../../include/Game/Menu/PlayerChoice.hpp"
#include "../../../include/Game/Menu/MainMenu.hpp"
#include "../../../include/Exceptions.hpp"
#include "../../../include/Game/Tools/DirectoryReader.hpp"
#include "../../../include/Game/Tools/Utilities.hpp"

void PlayerChoice::SetWindowProperties(void)
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
    _needToClose = true;
}

void PlayerChoice::MakeSkins(void)
{
    DirectoryReader reader(SKINS_PATH);
    std::vector<std::string> listFiles = reader.getFiles();

    if (listFiles.size() < 1)
        throw Exceptions("Invalid number of skins.");
    for (size_t i = 0; i < listFiles.size(); i++) {
        IndieTextures textureSkin(SKINS_PATH + listFiles[i], 0, 0, 0, 1, WHITE);
        IndieText textSkin(removeExtension(listFiles[i]), 0, 0, 30, 30, BLACK);
        if (i % 2 == 0) {
            textureSkin.IndieSetTexturePosition(20, (float)(10 + i * 290));
            textSkin.IndieSetTextPosition(Vector2({190, (float)(375 + i * 290)}));
        } else {
            textureSkin.IndieSetTexturePosition(1482, (float)(10 + (i - 1) * 290));
            textSkin.IndieSetTextPosition(Vector2({1650, (float)(375 + (i - 1) * 290)}));
        }
        Skin skin(textureSkin, textSkin, i);
        _listSkins.push_back(skin);
    }
    _maxIdTexture = listFiles.size() - 1;
    if (_listSkins.size() < 4) {
        for (size_t i = _listSkins.size() - 1; i < 3; i++) {
            IndieTextures textureSkin(SKINS_PATH + listFiles.back(), 0, 0, 0, 1, WHITE);
            IndieText textSkin(removeExtension(listFiles.back()), 0, 0, 30, 30, BLACK);
            if (i % 2 == 1) {
                textureSkin.IndieSetTexturePosition(20, (float)(10 + (i + 1) * 290));
                textSkin.IndieSetTextPosition(Vector2({190, (float)(375 + (i + 1) * 290)}));
            } else {
                textureSkin.IndieSetTexturePosition(1482, (float)(10 + (i) * 290));
                textSkin.IndieSetTextPosition(Vector2({1650, (float)(375 + (i) * 290)}));
            }
            Skin skin(textureSkin, textSkin, i);
            _listSkins.push_back(skin);
            listFiles.push_back(listFiles.back());
        }
    }
    for (size_t i = 0; i < 4; i++) {
        IndieText textPlayer("", 0, 0, 30, 30, BLACK);
        IndieTextures textureButton1("../ressource/Menu/select_right.png", 0, 0, 0, 1, WHITE);
        IndieTextures textureButton2("../ressource/Menu/select_left.png", 0, 0, 0, 1, WHITE);
        if (i % 2 == 0) {
            textureButton1.IndieSetTexturePosition(370, 360 + i * 290);
            textureButton2.IndieSetTexturePosition(30, 360 + i * 290);
            textPlayer.IndieSetTextPosition(Vector2({ 190, (float)(20 + i * 290) }));
            if (i == 0) {
                textPlayer.IndieSetNewText("Player 1");
            } else {
                textPlayer.IndieSetNewText("  IA 1  ");
            }
        } else {
            textureButton1.IndieSetTexturePosition(1820, 360 + (i - 1) * 290);
            textureButton2.IndieSetTexturePosition(1500, 360 + (i - 1) * 290);
            textPlayer.IndieSetTextPosition(Vector2({ 1650, (float)(20 + (i - 1) * 290) }));
            if (i == 3) {
                textPlayer.IndieSetNewText("Player 2");
            } else {
                textPlayer.IndieSetNewText("  IA 2  ");
            }
        }
        PlayersInfo player(_listSkins[i], i);
        if (i > _maxIdTexture)
            player.setIdTexture(_maxIdTexture);
        player.SetSimpleText(textPlayer);
        if (i == 0)
            player.setIsHuman(true);
        player.getSkinName().IndieSetNewText(removeExtension(listFiles[i]));
        _listPlayersInfo.push_back(player);
        IndieRectangle rec1(textureButton1);
        IndieRectangle rec2(textureButton2);
        GameButton<PlayerChoice> button1("right", textureButton1, rec1, this, &PlayerChoice::SelectSkin);
        GameButton<PlayerChoice> button2("left", textureButton2, rec2, this, &PlayerChoice::SelectSkin);
        _listButtons.push_back(button1);
        _listButtons.push_back(button2);
    }
}

void PlayerChoice::MakeNbPlayerButtons(void)
{
    for (size_t i = 0; i < 2; i++) {
        IndieTextures texture(BUTTON_TEXTURE, WINDOW_WIDTH / 3 + i * 500, WINDOW_HEIGHT / 5, 0, 0.25, WHITE);
        IndieRectangle rec(texture);
        GameButton<PlayerChoice> UIButton("1 Player", texture, rec, this, &PlayerChoice::ChangeNbPlayers);
        if (i % 2 == 0) {
            UIButton.getText().IndieSetNewText("1 Player");
            UIButton.Activate();
        } else {
            UIButton.getText().IndieSetNewText("2 Players");
            UIButton.Desactivate();
        }
        _nbPlayerButtons.push_back(UIButton);
    }
}

void PlayerChoice::MakeBoxText(void)
{
    BoxText box1(770, 400, 400, 50, LIGHTGRAY);
    box1.Activate();
    box1.getName().IndieSetNewText("Name Player 1");
    box1.getName().IndieSetTextPosition(Vector2({ 860, 360 }));
    _listBoxTexts.push_back(box1);
    BoxText box2(770, 600, 400, 50, LIGHTGRAY);
    box1.Desactivate();
    box2.getName().IndieSetNewText("Name Player 2");
    box2.getName().IndieSetTextPosition(Vector2({ 860, 560 }));
    _listBoxTexts.push_back(box2);
}

PlayerChoice::PlayerChoice(IndieMusic music, float volume) : _music(music), _background(BACKGROUND_MENU, 0, 0, 0, 1, WHITE)
{
    SetWindowProperties();
    _volMusic = volume;
    _music.IndieSetMusicVolume(_volMusic);
    try {
        MakeSkins();
    } catch (const Exceptions &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
    MakeNbPlayerButtons();
    MakeBoxText();
    IndieTextures texture(BUTTON_TEXTURE, 0, 0, 0, 0.25, WHITE);
    texture.IndieSetTexturePosition(WINDOW_WIDTH / 2 - (texture.IndieGetTextureWidth() * texture.IndieGetTextureScale()) / 2, 750);
    IndieRectangle rec(texture);
    GameButton<PlayerChoice> lauch("Launch", texture, rec, this, &PlayerChoice::LaunchGame);
    _lauchGame.push_back(lauch);
}

PlayerChoice::~PlayerChoice(void)
{
    for (PlayersInfo &e : _listPlayersInfo)
        e.getTexture().IndieUnloadTexture();
    for (GameButton<PlayerChoice> &e : _listButtons)
        e.getTexture().IndieUnloadTexture();
    for (GameButton<PlayerChoice> &e : _nbPlayerButtons)
        e.getTexture().IndieUnloadTexture();
    for (GameButton<PlayerChoice> &e : _lauchGame)
        e.getTexture().IndieUnloadTexture();
    if (_needToClose)
        _window.closeWindow();
}

int PlayerChoice::ChangeNbPlayers(int i)
{
    if (i == 0) {
        _nbPlayerButtons[1].Desactivate();
        _listBoxTexts[1].Desactivate();
        _listPlayersInfo[3].setIsHuman(false);
    } else if (i == 1) {
        _nbPlayerButtons[1].Activate();
        _listBoxTexts[1].Activate();
        _listPlayersInfo[3].setIsHuman(true);
    }
    return 0;
}

int PlayerChoice::SelectSkin(PlayersInfo *s, int nb)
{
    DirectoryReader reader(SKINS_PATH);
    std::vector<std::string> files = reader.getFiles();

    if (nb == 1) {
        if (s->getIdTexture() == _maxIdTexture) {
            s->setIdTexture(-1);
        }
        s->getTexture().IndieUnloadTexture();
        s->getTexture().IndieLoadNewTexture(SKINS_PATH + files[s->getIdTexture() + 1]);
        s->getSkinName().IndieSetNewText(removeExtension(files[s->getIdTexture() + 1]));
        s->setIdTexture(s->getIdTexture() + 1);
    } else {
        if (s->getIdTexture() == 0) {
            s->setIdTexture(_maxIdTexture + 1);
        }
        s->getTexture().IndieUnloadTexture();
        s->getTexture().IndieLoadNewTexture(SKINS_PATH + files[s->getIdTexture() - 1]);
        s->getSkinName().IndieSetNewText(removeExtension(files[s->getIdTexture() - 1]));
        s->setIdTexture(s->getIdTexture() - 1);
    }
    return 0;
}

void PlayerChoice::DrawPlayerChoice(void)
{
    _drawer.beginDrawing();
    _background.IndieDrawTextureAdvanced();
    for (size_t i = 0; i < 4; i++) {
        _listPlayersInfo[i].getTexture().IndieDrawTextureAdvanced();
        _listPlayersInfo[i].getSkinName().IndieDrawText();
        _listPlayersInfo[i].getSimpleText().IndieDrawText();
    }
    for (GameButton<PlayerChoice> &e : _listButtons) {
        e.getTexture().IndieDrawTextureAdvanced();
    }
    for (GameButton<PlayerChoice> &e : _nbPlayerButtons) {
        e.getTexture().IndieDrawTextureAdvanced();
        e.getText().IndieDrawText();
    }
    for (BoxText &e : _listBoxTexts) {
        if (e.getState()) {
            e.getRectangle().IndieDrawRectangle();
            if (e.getBool()) {
                e.getRectangle().IndieSetRectangleColor(RED);
                e.getRectangle().IndieDrawRectangleLine();
            }
            e.getRectangle().IndieSetRectangleColor(LIGHTGRAY);
            e.drawStr();
            e.getName().IndieDrawText();
        }
    }
    for (GameButton<PlayerChoice> &e : _lauchGame) {
        e.getTexture().IndieDrawTextureAdvanced();
        e.getText().IndieDrawText();
    }
    _drawer.endDrawing();
}

void PlayerChoice::HandleClickButtons(void)
{
    CollisionChecker cc;
    InputMouse mouse;

    for (size_t i = 0; i < _listButtons.size(); i++) {
        if (cc.IndieCheckCollisionPointRec(mouse.getMousePosition(), _listButtons[i].getRectangle().IndieGetRectangleRec())) {
            if (mouse.isMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                if (_listButtons[i].getText().IndieGetText() == "right") {
                    _listButtons[i].DoFunction(&_listPlayersInfo[i / 2], 1);
                } else if (_listButtons[i].getText().IndieGetText() == "left") {
                    _listButtons[i].DoFunction(&_listPlayersInfo[i / 2], -1);
                }
            }
        }
    }
    for (size_t i = 0; i < _nbPlayerButtons.size(); i++) {
        if (cc.IndieCheckCollisionPointRec(mouse.getMousePosition(), _nbPlayerButtons[i].getRectangle().IndieGetRectangleRec())) {
            _nbPlayerButtons[i].getTexture().IndieSetTextureColor(RED);
            if (mouse.isMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                _nbPlayerButtons[i].DoFunction(i);
            }
        } else {
            _nbPlayerButtons[i].getTexture().IndieSetTextureColor(WHITE);
        }
    }
    for (size_t i = 0; i < _lauchGame.size(); i++) {
        if (cc.IndieCheckCollisionPointRec(mouse.getMousePosition(), _lauchGame[i].getRectangle().IndieGetRectangleRec())) {
            _lauchGame[i].getTexture().IndieSetTextureColor(RED);
            if (mouse.isMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                _window.closeWindow();
                _lauchGame[i].DoFunction();
                _needToClose = false;
            }
        } else {
            _lauchGame[i].getTexture().IndieSetTextureColor(WHITE);
        }
    }
}

void PlayerChoice::HandleBoxTexts(void)
{
    CollisionChecker cc;
    InputMouse mouse;
    InputKey key;

    for (size_t i = 0; i < _listBoxTexts.size(); i++) {
        if (_listBoxTexts[i].getState()) {
            if (cc.IndieCheckCollisionPointRec(mouse.getMousePosition(), _listBoxTexts[i].getRectangle().IndieGetRectangleRec())) {
                _listBoxTexts[i].setBool(true);
            } else {
                _listBoxTexts[i].setBool(false);
            }
            if (_listBoxTexts[i].getBool()) {
                mouse.setMouseCursor(MOUSE_CURSOR_IBEAM);
                int k = key.getCharPressed();
                while (k > 0) {
                    if ((k >= 32) && (k <= 125) && (_listBoxTexts[i].getStr().size() < PLAYER_NAME_LENGHT)) {
                        _listBoxTexts[i].addLetterToStr(char(k));
                        _listPlayersInfo[i].setPlayerName(_listBoxTexts[i].getStr());
                    }
                    k = key.getCharPressed();
                }
                if (key.isKeyPressed(KEY_BACKSPACE)) {
                    _listBoxTexts[i].removeLastLetter();
                    _listPlayersInfo[i].setPlayerName(_listBoxTexts[i].getStr());
                }
            } else {
                mouse.setMouseCursor(MOUSE_CURSOR_DEFAULT);
            }
        }
    }
}

int PlayerChoice::ChoicePlayer(void)
{
    while (_window.keepWindowOpen()) {
        _music.IndieUpdateMusicStream();
        DrawPlayerChoice();
        HandleClickButtons();
        HandleBoxTexts();
    }
    return 0;
}

int MainMenu::GoGame(void)
{
    PlayerChoice choice(_music, _volMusic);

    choice.ChoicePlayer();
    return 0;
}