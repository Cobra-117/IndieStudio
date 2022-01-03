/*
** EPITECH PROJECT, 2021
** sdfghjk
** File description:
** jhgfd
*/

#ifndef BOXTEXT
#define BOXTEXT

#include <vector>
#include <iostream>
#include "../../Engine/Shapes/Rectangle.hpp"
#include "../../Engine/Text/Text.hpp"

class BoxText
{
    private:
        std::string _str;
        IndieRectangle _textBox;
        IndieText _text;
        IndieText _name;
        bool _mouseOnText;
        bool _state;

    public:
        BoxText(int posX, int posY, int width, int height, Color color) : _textBox(posX, posY, width, height, color), _text("", 0, 0, 0, 0, WHITE), _name("", 0, 0, 30, 30, BLACK) {
            _str = "";
            _mouseOnText = false;
            _state = false;
        };
        BoxText(IndieRectangle rec) : _textBox(rec), _text("", 0, 0, 0, 0, WHITE), _name("", 0, 0, 30, 30, BLACK) {
            _str = "";
            _mouseOnText = false;
            _state = false;
        };
        ~BoxText() = default;
        IndieRectangle &getRectangle(void) {
            return _textBox;
        };
        bool &getBool(void) {
            return _mouseOnText;
        };
        void setBool(bool b) {
            _mouseOnText = b;
        };
        IndieText &getName(void) {
            return _name;
        };
        void addLetterToStr(char c) {
            _str.append(std::string(1, c));
        };
        void removeLastLetter(void) {
            if (_str.size() > 0)
                _str.pop_back();
        };
        std::string getStr(void) {
            return _str;
        };
        void drawStr(void) {
            _text.IndieDrawText(_str.c_str(), _textBox.IndieGetRectanglePos().first + 10, _textBox.IndieGetRectanglePos().second + 10, 30, BLACK);
        };
        bool getState(void) {
            return _state;
        };
        void Activate(void) {
            _state = true;
        };
        void Desactivate(void) {
            _state = false;
        };
};

#endif