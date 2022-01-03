/*
** EPITECH PROJECT, 2021
** sdfghjk
** File description:
** kjhgfd
*/

#ifndef GAME_BUTTON
#define GAME_BUTTON

#include "../../Engine/Shapes/Rectangle.hpp"
#include "../../Engine/Textures/Textures.hpp"
#include "../../Engine/Text/Text.hpp"
#include "../../Engine/Audio/Sound.hpp"
#include "../../Game/Menu/PlayersInfo.hpp"
#include "../../indie.hpp"

class MainMenu;
class Settings;

template<typename T/*, typename X*/>
class GameButton
{
    private:
        IndieTextures _texture;
        IndieRectangle _rectangle;
        IndieText _text;
        bool _isActivated;
        IndieSound _sound;
        T *_obj;
        //X _args;
        int (T::*func1)(/*X*/void);
        int (T::*func2)(/*X*/int);
        int (T::*func3)(/*X*/PlayersInfo *, int);
    public:
        GameButton(std::string texte, IndieTextures tex, IndieRectangle rec, T *obj, int(T::*f)(/*X arg*/void)) : _texture(tex), _rectangle(rec), _text(texte, 0, 0, 30, 30, BLACK), _sound(CLICK_SOUND) {
            _obj = obj;
            func1 = f;
            //_args = arg;
            _isActivated = false;
            _text.IndieSetNewText(texte);
            _text.IndieSetFontSize(tex.IndieGetTextureHeight() / _text.IndieTextLength());
            float i = 1;
            float j = _text.IndieTextLength();
            float a = float(i/j);
            _text.IndieSetTextPosition(Vector2({rec.IndieGetRectanglePos().first +
            (tex.IndieGetTextureWidth() * tex.IndieGetTextureScale()) / 2 - a * 150 - _text.IndieTextLength() * 4,
            rec.IndieGetRectanglePos().second + (tex.IndieGetTextureHeight() * tex.IndieGetTextureScale()) / 2 -
            _text.IndieGetTextFontSize() / 2}));
        };
        GameButton(std::string texte, IndieTextures tex, IndieRectangle rec, T *obj, int(T::*f)(int)) : _texture(tex), _rectangle(rec), _text(texte, 0, 0, 30, 30, BLACK), _sound(CLICK_SOUND) {
            _obj = obj;
            func2 = f;
            _isActivated = false;
            _text.IndieSetNewText(texte);
            _text.IndieSetFontSize(tex.IndieGetTextureHeight() / _text.IndieTextLength());
            float i = 1;
            float j = _text.IndieTextLength();
            float a = float(i/j);
            _text.IndieSetTextPosition(Vector2({rec.IndieGetRectanglePos().first +
            (tex.IndieGetTextureWidth() * tex.IndieGetTextureScale()) / 2 - a * 150 - _text.IndieTextLength() * 4,
            rec.IndieGetRectanglePos().second + (tex.IndieGetTextureHeight() * tex.IndieGetTextureScale()) / 2 -
            _text.IndieGetTextFontSize() / 2}));
        };
        GameButton(std::string texte, IndieTextures tex, IndieRectangle rec, T *obj, int(T::*f)(PlayersInfo *, int)) : _texture(tex), _rectangle(rec), _text(texte, 0, 0, 30, 30, BLACK), _sound(CLICK_SOUND) {
            _obj = obj;
            func3 = f;
            _isActivated = false;
            _text.IndieSetNewText(texte);
            _text.IndieSetFontSize(tex.IndieGetTextureHeight() / _text.IndieTextLength());
            float i = 1;
            float j = _text.IndieTextLength();
            float a = float(i/j);
            _text.IndieSetTextPosition(Vector2({rec.IndieGetRectanglePos().first +
            (tex.IndieGetTextureWidth() * tex.IndieGetTextureScale()) / 2 - a * 150 - _text.IndieTextLength() * 4,
            rec.IndieGetRectanglePos().second + (tex.IndieGetTextureHeight() * tex.IndieGetTextureScale()) / 2 -
            _text.IndieGetTextFontSize() / 2}));
        };
        GameButton(IndieText text, IndieRectangle rec, T *obj, int(T::*f)(int)) : _text(text), _rectangle(rec), _texture(BUTTON_TEXTURE, 0, 0, 0, 0, WHITE), _sound(CLICK_SOUND) {
            _obj = obj;
            func2 = f;
            _isActivated = false;
        };
        GameButton(IndieText text, IndieRectangle rec, T *obj, int(T::*f)(void)) : _text(text), _rectangle(rec), _texture(BUTTON_TEXTURE, 0, 0, 0, 0, WHITE), _sound(CLICK_SOUND) {
            _obj = obj;
            func1 = f;
            _isActivated = false;
        };
        GameButton(IndieText text, IndieRectangle rec, T *obj, int(T::*f)(PlayersInfo *, int)) : _text(text), _rectangle(rec), _texture(BUTTON_TEXTURE, 0, 0, 0, 0, WHITE), _sound(CLICK_SOUND) {
            _obj = obj;
            func3 = f;
            _isActivated = false;
        };
        ~GameButton() = default;
        int DoFunction(/*X arg*/void) {
            _sound.IndiePlaySound();
            return (_obj->*func1)(/*arg*/);
        };
        int DoFunction(int i) {
            _sound.IndiePlaySound();
            return (_obj->*func2)(i);
        };
        int DoFunction(PlayersInfo *s, int i) {
            _sound.IndiePlaySound();
            return (_obj->*func3)(s, i);
        };
        IndieTextures &getTexture(void) {
            return _texture;
        };
        IndieRectangle &getRectangle(void) {
            return _rectangle;
        };
        IndieText &getText(void) {
            return _text;
        };
        void Activate(void) {
            _isActivated = true;
        };
        void Desactivate(void) {
            _isActivated = false;
        };
        bool GetState(void) {
            return _isActivated;
        };
};

#endif