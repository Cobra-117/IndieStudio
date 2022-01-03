/*
** EPITECH PROJECT, 2021
** sdfghjk
** File description:
** kjhgfd
*/

#ifndef PLAYERS_INFO
#define PLAYERS_INFO

#include "../../Engine/Textures/Textures.hpp"
#include "../../Engine/Text/Text.hpp"

class Skin
{
    private:
        IndieTextures _texture;
        IndieText _skinName;
        int _idTexture;
    public:
        Skin(IndieTextures texture, IndieText text, int i) {
            _texture = texture;
            _skinName = text;
            _idTexture = i;
        };
        Skin(const Skin &s) {
            _texture = s._texture;
            _skinName = s._skinName;
            _idTexture = s._idTexture;
        };
        Skin &operator=(const Skin &s) {
            _texture = s._texture;
            _skinName = s._skinName;
            _idTexture = s._idTexture;
            return *this;
        };
        ~Skin() = default;
        IndieTextures &getTextureSkin() {
            return _texture;
        };
        IndieText &getSkinName() {
            return _skinName;
        };
        int getIdTexture() {
            return _idTexture;
        };
        void setIdTexture(int i) {
            _idTexture = i;
        };
};

class PlayersInfo
{
    private:
        Skin _skin;
        IndieText _text;
        int _idPlayer;
        std::string _namePlayer;
        bool _isHuman;
        
    public:
        PlayersInfo(Skin skin, int i) : _text("", 0, 0, 30, 30, BLACK), _skin(skin) {
            _idPlayer = i;
            _namePlayer = "";
            _isHuman = false;
        };
        PlayersInfo(const PlayersInfo &p) : _skin(p._skin) {
            _text = p._text;
            _idPlayer = p._idPlayer;
            _namePlayer = p._namePlayer;
            _isHuman = p._isHuman;
        };
        PlayersInfo &operator=(const PlayersInfo &p) {
            _skin = p._skin;
            _text = p._text;
            _idPlayer = p._idPlayer;
            _namePlayer = p._namePlayer;
            _isHuman = p._isHuman;
            return *this;
        };
        ~PlayersInfo() = default;
        IndieTextures &getTexture() {
            return _skin.getTextureSkin();
        };
        IndieText &getSkinName() {
            return _skin.getSkinName();
        };
        IndieText &getSimpleText() {
            return _text;
        };
        void SetSimpleText(IndieText &t) {
            _text = t;
        }
        int getIdTexture() {
            return _skin.getIdTexture();
        };
        void setIdTexture(int i) {
            _skin.setIdTexture(i);
        };
        void setPlayerName(std::string str) {
            _namePlayer = str;
        };
        std::string getPlayerName(void) {
            return _namePlayer;
        };
        void setIsHuman(bool b) {
            _isHuman = b;
        };
        bool getIsHuman(void) {
            return _isHuman;
        };
};

#endif