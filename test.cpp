/*
** EPITECH PROJECT, 2020
** INDIE
** File description:
** test.cpp
*/

#include "./include/Engine/Audio/Audio.hpp"
#include "./include/Engine/Core/Core.hpp"
#include "./include/Engine/Core/Window.hpp"
#include "./include/Engine/Core/Cursor.hpp"
#include "./include/Engine/Core/Drawer.hpp"
#include "./include/Engine/Core/InputKey.hpp"
#include "./include/Engine/Core/InputMouse.hpp"
#include "./include/Engine/Core/Misc.hpp"
#include "./include/Engine/Core/FileManager.hpp"
#include "./include/Exceptions.hpp"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    myAudio a;
    myMusicStream s;
    Map m;

    InitWindow(screenWidth, screenHeight, "raylib [audio] example - music playing (streaming)");

    s.IndieLoadMusicStream("../ressource/beep-beep.mp3");
    s.IndiePlayMusicStream();
    m.generateRandomMap(9, 9, 40);
    m.display();
    m.flush();

    float timePlayed = 0.0f;
    bool pause = false;

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        s.IndieUpdateMusicStream();
        if (IsKeyPressed(KEY_SPACE)) {
            s.IndieStopMusicStream();
            s.IndiePlayMusicStream();
        }
        if (IsKeyPressed(KEY_P)) {
            pause = !pause;

            if (pause) s.IndiePauseMusicStream();
            else s.IndieResumeMusicStream();
        }

        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("MUSIC SHOULD BE PLAYING!", 255, 150, 20, LIGHTGRAY);

            DrawText("PRESS SPACE TO RESTART MUSIC", 215, 250, 20, LIGHTGRAY);
            DrawText("PRESS P TO PAUSE/RESUME MUSIC", 208, 280, 20, LIGHTGRAY);

        EndDrawing();
    }
    s.IndieUnloadMusicStream();

    CloseWindow();
    return 0;
}
