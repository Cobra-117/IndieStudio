/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by flavien,
*/

#include "../../../include/Engine/Text/Text.hpp"
#include "../../../include/Exceptions.hpp"

IndieText::IndieText(std::string text, int posX, int posY, int fontSize, float spacing, Color color) : _fontSize(fontSize),
    _color(color), _spacing(spacing), _hasFont(false)
{
    _text = const_cast<char *>(text.c_str());
    Vector2 vector2;
    vector2.x = posX;
    vector2.y = posY;
    this->_position = vector2;
}

IndieText::IndieText(const IndieText &a)
{
    _text = a._text;
    _fontSize = a._fontSize;
    _color = a._color;
    _spacing = a._spacing;
    _hasFont = a._hasFont;
    _position = a._position;
    _font = a._font;
}

IndieText &IndieText::operator=(const IndieText &a)
{
    _text = a._text;
    _fontSize = a._fontSize;
    _color = a._color;
    _spacing = a._spacing;
    _hasFont = a._hasFont;
    _position = a._position;
    _font = a._font;
    return *this;
}

IndieText::~IndieText()
{
    if (this->_hasFont)
        this->IndieUnloadFont();
}

void IndieText::IndieLoadFont(std::string fileName)
{
    this->_hasFont = true;
    this->_font = LoadFont(fileName.c_str());
}

void IndieText::IndieUnloadFont()
{
    this->_hasFont = false;
    UnloadFont(this->_font);
}

void IndieText::IndieDrawFPS()
{
    DrawFPS(this->_position.x, this->_position.y);
}

void IndieText::IndieDrawFPS(int x, int y)
{
    DrawFPS(x, y);
}

void IndieText::IndieDrawText()
{
    DrawText(this->_text, this->_position.x, this->_position.y, this->_fontSize,
        this->_color);
}

void IndieText::IndieDrawText(const char *text, int x, int y, int fsize, Color color)
{
    DrawText(text, x, y, fsize, color);
}

void IndieText::IndieDrawTextCustomFont()
{
    if (!this->_hasFont) {
        throw Exceptions("ERROR: Trying to draw a custom font text without a font!");
    }
    DrawTextEx(this->_font, this->_text, this->_position, this->_fontSize, this->_spacing,
        this->_color);
}

int IndieText::IndieMeasureText()
{
    return MeasureText(this->_text, this->_fontSize);
}

int IndieText::IndieMeasureText(char *text, int fontSize)
{
    return MeasureText(text, fontSize);
}

Vector2 IndieText::IndieMeasureTextCustomFont()
{
    if (!this->_hasFont) {
        throw Exceptions("ERROR: Trying to mesure a custom font text without a font!");
    }
    return MeasureTextEx(this->_font, this->_text, this->_fontSize, this->_spacing);
}

int IndieText::IndieTextCopy(char *dst)
{
    return TextCopy(dst, this->_text);
}

bool IndieText::IndieTextIsEqual(const char *text)
{
    return TextIsEqual(this->_text, text);
}

unsigned int IndieText::IndieTextLength()
{
    return TextLength(this->_text);
}

const char *IndieText::IndieTextSubtext(int position, int length)
{
    return TextSubtext(this->_text, position, length);
}

char *IndieText::IndieTextReplace(const char *replace, const char *by)
{
    return TextReplace(this->_text, replace, by);
}

char *IndieText::IndieTextInsert(const char *insert, int position)
{
    return TextInsert(this->_text, insert, position);
}

const char *IndieText::IndieTextJoin(const char **textList, int count,
    const char *delimiter
)
{
    return TextJoin(textList, count, delimiter);
}

const char **IndieText::IndieTextSplit(char delimiter, int *count)
{
    return TextSplit(this->_text, delimiter, count);
}

void IndieText::IndieTextAppend(const char *append, int *position)
{
    TextAppend(this->_text, append, position);
}

int IndieText::IndieTextFindIndex(const char *find)
{
    return TextFindIndex(this->_text, find);
}

const char *IndieText::IndieTextToUpper()
{
    return TextToUpper(this->_text);
}

const char *IndieText::IndieTextToLower()
{
    return TextToLower(this->_text);
}

const char *IndieText::IndieTextToPascal()
{
    return TextToPascal(this->_text);
}

int IndieText::IndieTextToInteger()
{
    return TextToInteger(this->_text);
}

void IndieText::IndieSetTextPosition(Vector2 newPos)
{
    _position = newPos;
}

void IndieText::IndieSetNewText(std::string newText)
{
    _text = new char[newText.length() + 1];
    strcpy(_text, newText.c_str());
}

void IndieText::IndieSetColor(Color newColor)
{
    _color = newColor;
}

void IndieText::IndieSetFontSize(int fsize)
{
    _fontSize = fsize;
}

void IndieText::IndieSetSpacing(float space)
{
    _spacing = space;
}

Vector2 IndieText::IndieGetTextPosition(void)
{
    return _position;
}

std::string IndieText::IndieGetText(void)
{
    return std::string(_text);
}

int IndieText::IndieGetTextFontSize(void)
{
    return _fontSize;
}

Color IndieText::IndieGetTextColor(void)
{
    return _color;
}