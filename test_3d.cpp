/*
** EPITECH PROJECT, 2021
** test_iqm
** File description:
** main
*/

#include "raylib.h"

#include "include/indie.hpp"
#include "include/Game/Menu.hpp"

#include <stdlib.h>
#include <stdio.h>


int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [models] example - model animation");

    // Define the camera to look into our 3d world
    Camera camera = { 0 };
    camera.position = (Vector3){ 10.0f, 10.0f, 10.0f }; // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;                   // Camera mode type

    IndieTextures tex("../ressource/3DModels/Zombie/zombie_texture.png", 0, 0, 0, 0, WHITE);
    IndieModel Mod("../ressource/3DModels/Zombie/zombie_guy.iqm");            // Load the animated model mesh and basic data

    Mod.IndieSetMaterialTexture(0, tex);

    Mod._position = { 0.0f, 0.0f, 0.0f };            // Set model position
    Mod._rotationAxis = { 1.0f, 0.0f, 0.0f };
    Mod._scale = {1.0f, 1.0f, 1.0f };
    // Load animation data
    int animsCount = 0;
    Mod.IndieLoadModelAnimations("../ressource/3DModels/Zombie/anim.iqm", &animsCount);
    int animFrameCounter = 0;

    SetCameraMode(camera, CAMERA_FREE); // Set free camera mode

    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())        // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        UpdateCamera(&camera);

        // Play animation when spacebar is held down
        if (IsKeyDown(KEY_SPACE))
        {
            animFrameCounter++;
            UpdateModelAnimation(Mod._model, Mod._animation[0], animFrameCounter);
            if (animFrameCounter >= Mod._animation[0].frameCount)
                animFrameCounter = 0;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);

                //DrawModelEx(Mod._model, Mod._position, (Vector3){ 1.0f, 0.0f, 0.0f }, -90.0f, (Vector3){ 1.0f, 1.0f, 1.0f }, WHITE);
                Mod.IndieDrawEx(-90.0f, WHITE);
                // for (int i = 0; i < Mod._model.boneCount; i++)
                // {
                //     DrawCube(Mod._animation[0].framePoses[animFrameCounter][i].translation, 0.2f, 0.2f, 0.2f, RED);
                // }

                DrawGrid(10, 1.0f);         // Draw a grid

            EndMode3D();

            DrawText("PRESS SPACE to PLAY MODEL ANIMATION", 10, 10, 20, MAROON);
            DrawText("(c) Guy IQM 3D model by @culacant", screenWidth - 200, screenHeight - 20, 10, GRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    //UnloadTexture(texture);     // Unload texture
    tex.IndieUnloadTexture();
    // Unload model animations data
    for (int i = 0; i < animsCount; i++) UnloadModelAnimation(Mod._animation[i]);
    RL_FREE(Mod._animation);

    UnloadModel(Mod._model);         // Unload model

    CloseWindow();              // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
