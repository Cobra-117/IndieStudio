/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by flavien,
*/

#ifndef MY_TEXT_
#define MY_TEXT_

extern "C" {
    #include "raylib.h"
}

#include <iostream>
#include <string>
#include <cstring>

class IndieText {
    public:
        ~IndieText();
        IndieText(std::string, int, int, int, float, Color);
        IndieText() = default;
        IndieText(const IndieText &);
        IndieText &operator=(const IndieText &);
        void IndieSetTextPosition(Vector2);
        void IndieSetNewText(std::string);
        void IndieSetColor(Color);
        void IndieSetFontSize(int);
        void IndieSetSpacing(float);
        Vector2 IndieGetTextPosition(void);
        std::string IndieGetText(void);
        Color IndieGetTextColor(void);
        int IndieGetTextFontSize(void);
        void IndieLoadFont(std::string);
        void IndieUnloadFont();
        void IndieDrawFPS();
        void IndieDrawFPS(int, int);
        void IndieDrawText();
        void IndieDrawText(const char *, int, int, int, Color);
        void IndieDrawTextCustomFont();
        int IndieMeasureText();
        int IndieMeasureText(char *, int);
        Vector2 IndieMeasureTextCustomFont();
        int IndieTextCopy(char *);
        bool IndieTextIsEqual(const char *);
        unsigned int IndieTextLength();
        const char *IndieTextSubtext(int, int);
        char *IndieTextReplace(const char *, const char *);
        char *IndieTextInsert(const char *, int );
        const char *IndieTextJoin(const char **, int, const char *);
        const char **IndieTextSplit(char, int *);
        void IndieTextAppend(const char *, int *);
        int IndieTextFindIndex(const char *);
        const char *IndieTextToUpper();
        const char *IndieTextToLower();
        const char *IndieTextToPascal();
        int IndieTextToInteger();

    public:
        bool _hasFont;
        Font _font;
        int _fontSize;
        float _spacing;
        char *_text;
        Vector2 _position;
        Color _color;
};

#endif