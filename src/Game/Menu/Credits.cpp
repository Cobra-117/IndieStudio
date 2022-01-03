/*
** EPITECH PROJECT, 2021
** sdfghj
** File description:
** lkjhgfd
*/

#include "../../../include/Game/Menu/Credits.hpp"
#include "../../../include/Exceptions.hpp"
#include "../../../include/Game/Menu/MainMenu.hpp"

Credits::Credits(IndieMusic music, float volume) : _music(music)
{
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
    for (size_t i = 0; i < 6; i++) {
        IndieText text("", 600, 1080 + i * 150, 30, 30, WHITE);
        _listTexts.push_back(text);
    }
    _listTexts[0].IndieSetNewText("Directeur : Adrien Michaud (@Guide Suprême)\nÀ imposer sa vision et sa dictature à l'équipe");
    _listTexts[1].IndieSetNewText("Game Designer : Timothé Lacheroy (@Le Vilain Pangolin)\nÀ fait le jeu uniquement alimenter par du soja");
    _listTexts[2].IndieSetNewText("Bêta Testeur : Flavien Allix (@Sir Falaxir Va Durcir)\nÀ envoyer les faignéasses au goulag");
    _listTexts[3].IndieSetNewText("Texture / Audio Maker : Jérémy Braconier (@Chui Bo)\nPas un grand codeur mais un grand compositeur");
    _listTexts[4].IndieSetNewText("Stagiaire : Basile Seroul (@Basile Le Basophile)\nÀ effectuer son stage de troisième en nous apportant le café");
    _listTexts[5].IndieSetNewText("Fantôme : Paul Moccelin (@Purée Mocceline)\nÀ fait tout et rien à la fois");
}

Credits::~Credits(void)
{
    _window.closeWindow();
}

int Credits::PrintCredits(void)
{
    while (_window.keepWindowOpen()) {
        _music.IndieUpdateMusicStream();
        _drawer.beginDrawing();
        _drawer.clearBackground(BLACK);
        for (IndieText &e : _listTexts) {
            e.IndieDrawText();
            e.IndieSetTextPosition(Vector2({ 600, e.IndieGetTextPosition().y - 1 }));
        }
        _drawer.endDrawing();
        if (_listTexts.back().IndieGetTextPosition().y < 0)
            break;
    }
    return 0;
}

int MainMenu::GoCredits(void)
{
    Credits credit(_music, _volMusic);

    credit.PrintCredits();
    return 0;
}
