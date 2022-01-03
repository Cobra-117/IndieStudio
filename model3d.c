#include "raylib.h"

#include <stdlib.h>


int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1080;
    const int screenHeight = 920;

    InitWindow(screenWidth, screenHeight, "3d models");

    // Define the camera to look into our 3d world
    Camera camera = { 0 };
    camera.position = (Vector3){ 10.0f, 10.0f, 10.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    Model defaultPlayer = LoadModel("./ressource/3DModels/players/default_player.iqm");               // Load the animated defaultPlayer mesh and basic data
    Texture2D defaultPlayerTexture = LoadTexture("./ressource/3DModels/players/defaultPlayer.png");    // Load defaultPlayer texture and set material
    SetMaterialTexture(&defaultPlayer.materials[0], MAP_DIFFUSE, defaultPlayerTexture);

    Model greenPlayer = LoadModel("./ressource/3DModels/players/default_player.iqm");               // Load the animated defaultPlayer mesh and basic data
    Texture2D greenPlayerTexture = LoadTexture("./ressource/3DModels/players/greenPlayer.png");    // Load defaultPlayer texture and set material
    SetMaterialTexture(&greenPlayer.materials[0], MAP_DIFFUSE, greenPlayerTexture);

    Model yellowPlayer = LoadModel("./ressource/3DModels/players/default_player.iqm");               // Load the animated defaultPlayer mesh and basic data
    Texture2D yellowPlayerTexture = LoadTexture("./ressource/3DModels/players/yellowPlayer.png");    // Load defaultPlayer texture and set material
    SetMaterialTexture(&yellowPlayer.materials[0], MAP_DIFFUSE, yellowPlayerTexture);

    Model redPlayer = LoadModel("./ressource/3DModels/players/default_player.iqm");               // Load the animated defaultPlayer mesh and basic data
    Texture2D redPlayerTexture = LoadTexture("./ressource/3DModels/players/redPlayer.png");    // Load defaultPlayer texture and set material
    SetMaterialTexture(&redPlayer.materials[0], MAP_DIFFUSE, redPlayerTexture);

    Model bomb = LoadModel("./ressource/3DModels/bomb/Bomb.iqm");
    Texture2D bombTexture = LoadTexture("./ressource/3DModels/bomb/bomb.png");    // Load defaultPlayer texture and set material
    SetMaterialTexture(&bomb.materials[0], MAP_DIFFUSE, bombTexture);

    Model blinkBomb = LoadModel("./ressource/3DModels/bomb/Bomb.iqm");
    Texture2D blinkBombTexture = LoadTexture("./ressource/3DModels/bomb/bomb_blink.png");    // Load defaultPlayer texture and set material
    SetMaterialTexture(&blinkBomb.materials[0], MAP_DIFFUSE, blinkBombTexture);

    Model border = LoadModel("./ressource/3DModels/walls/border/border.iqm");
    Texture2D borderTexture = LoadTexture("./ressource/3DModels/walls/border/border.png");    // Load defaultPlayer texture and set material
    SetMaterialTexture(&border.materials[0], MAP_DIFFUSE, borderTexture);

    Model breakable = LoadModel("./ressource/3DModels/walls/breakable/breakable.iqm");
    Texture2D breakableTexture = LoadTexture("./ressource/3DModels/walls/breakable/breakable.png");    // Load defaultPlayer texture and set material
    SetMaterialTexture(&breakable.materials[0], MAP_DIFFUSE, breakableTexture);

    Model unbreakable = LoadModel("./ressource/3DModels/walls/unbreakable/unbreakable.iqm");
    Texture2D unbreakableTexture = LoadTexture("./ressource/3DModels/walls/unbreakable/unbreakable.png");    // Load defaultPlayer texture and set material
    SetMaterialTexture(&unbreakable.materials[0], MAP_DIFFUSE, unbreakableTexture);

    Model floor = LoadModel("./ressource/3DModels/walls/floor/floor.iqm");
    Texture2D floorTexture = LoadTexture("./ressource/3DModels/walls/floor/grass.png");    // Load defaultPlayer texture and set material
    SetMaterialTexture(&floor.materials[0], MAP_DIFFUSE, floorTexture);



    Vector3 position = { 0.0f, 0.0f, 0.0f };            // Set defaultPlayer position
    Vector3 greenPosition = { 1.0f, 0.0f, 0.0f };            // Set greenPlayer position
    Vector3 yellowPosition = { 2.0f, 0.0f, 0.0f };            // Set yellowPlayer position
    Vector3 redPosition = { 3.0f, 0.0f, 0.0f };            // Set redPlayer position
    Vector3 bombPosition = { 0.0f, 0.0f, 1.0f };            // Set bomb position
    Vector3 blinkBombPosition = { 1.0f, 0.0f, 1.0f };            // Set blinkBomb position
    Vector3 borderPosition = { 0.0f, 0.0f, -1.0f };
    Vector3 breakablePosition = { 1.0f, 0.0f, -1.0f };
    Vector3 unbreakablePosition = { 2.0f, 0.0f, -1.0f };
    Vector3 floorPosition = { 3.0f, 0.0f, -1.0f };


    int animsCount = 0;
    ModelAnimation *anims = LoadModelAnimations("./ressource/3DModels/players/walking_animation.iqm", &animsCount);
    int animFrameCounter = 0;

    SetCameraMode(camera, CAMERA_FREE);
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        UpdateCamera(&camera);

        if (IsKeyDown(KEY_SPACE))
        {
            animFrameCounter++;
            UpdateModelAnimation(defaultPlayer, anims[0], animFrameCounter);
            UpdateModelAnimation(greenPlayer, anims[0], animFrameCounter);
            UpdateModelAnimation(yellowPlayer, anims[0], animFrameCounter);
            UpdateModelAnimation(redPlayer, anims[0], animFrameCounter);
            if (animFrameCounter >= anims[0].frameCount) animFrameCounter = 0;
        }
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);

                DrawModelEx(defaultPlayer, position, (Vector3){ 0.1f, 0.0f, 0.0f }, -90, (Vector3){ 0.1f, 0.1f, 0.1f }, WHITE);
                DrawModelEx(greenPlayer, greenPosition, (Vector3){ 0.1f, 0.0f, 0.0f }, -90, (Vector3){ 0.1f, 0.1f, 0.1f }, WHITE);
                DrawModelEx(yellowPlayer, yellowPosition, (Vector3){ 0.1f, 0.0f, 0.0f }, -90, (Vector3){ 0.1f, 0.1f, 0.1f }, WHITE);
                DrawModelEx(redPlayer, redPosition, (Vector3){ 0.1f, 0.0f, 0.0f }, -90, (Vector3){ 0.1f, 0.1f, 0.1f }, WHITE);
                DrawModelEx(bomb, bombPosition, (Vector3){ 0.1f, 0.0f, 0.0f }, -90, (Vector3){ 1.0f, 1.0f, 1.0f }, WHITE);
                DrawModelEx(blinkBomb, blinkBombPosition, (Vector3){ 0.1f, 0.0f, 0.0f }, -90, (Vector3){ 1.0f, 1.0f, 1.0f }, WHITE);
                DrawModelEx(border, borderPosition, (Vector3){ 0.1f, 0.0f, 0.0f }, -90, (Vector3){ 0.1f, 0.1f, 0.1f }, WHITE);
                DrawModelEx(breakable, breakablePosition, (Vector3){ 0.1f, 0.0f, 0.0f }, -90, (Vector3){ 0.1f, 0.1f, 0.1f }, WHITE);
                DrawModelEx(unbreakable, unbreakablePosition, (Vector3){ 0.1f, 0.0f, 0.0f }, -90, (Vector3){ 0.1f, 0.1f, 0.1f }, WHITE);
                DrawModelEx(floor, floorPosition, (Vector3){ 0.1f, 0.0f, 0.0f }, -90, (Vector3){ 0.1f, 0.1f, 0.1f }, WHITE);
                DrawGrid(10, 1.0f);

            EndMode3D();
            DrawText("PRESS SPACE to PLAY WALK ANIMATION", 10, 10, 20, MAROON);
        EndDrawing();
    }

    UnloadTexture(defaultPlayerTexture);
    UnloadTexture(greenPlayerTexture);
    UnloadTexture(yellowPlayerTexture);
    UnloadTexture(redPlayerTexture);
    UnloadTexture(bombTexture);
    UnloadTexture(blinkBombTexture);
    UnloadTexture(borderTexture);
    UnloadTexture(breakableTexture);
    UnloadTexture(unbreakableTexture);
    UnloadTexture(floorTexture);
    // Unload defaultPlayer animations data
    for (int i = 0; i < animsCount; i++) UnloadModelAnimation(anims[i]);
    RL_FREE(anims);

    UnloadModel(defaultPlayer);         // Unload defaultPlayer
    UnloadModel(greenPlayer);         // Unload defaultPlayer
    UnloadModel(yellowPlayer);         // Unload defaultPlayer
    UnloadModel(redPlayer);         // Unload defaultPlayer
    UnloadModel(bomb);         // Unload defaultPlayer
    UnloadModel(blinkBomb);
    UnloadModel(border);
    UnloadModel(breakable);
    UnloadModel(unbreakable);
    UnloadModel(floor);

    CloseWindow();
    return 0;
}
