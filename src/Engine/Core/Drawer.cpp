/*
** EPITECH PROJECT, 2021
** sdfgh
** File description:
** jhgf
*/

#include "../../../include/Exceptions.hpp"
#include "../../../include/Engine/Core/Drawer.hpp"

Drawer::Drawer(void)
{
    ClearBackground(BLACK);

    Camera2D camera = {0};
    camera.target = Vector2({ 20.0f, 20.0f });
    camera.offset = Vector2({ GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f });
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    _2Dcamera = std::move(camera);

    Camera3D camera2 = {0};
    camera2.position = Vector3({ 0.0f, 10.0f, 10.0f });  // Camera position
    camera2.target = Vector3({ 0.0f, 0.0f, 0.0f });      // Camera looking at point
    camera2.up = Vector3({ 0.0f, 1.0f, 0.0f });          // Camera up vector (rotation towards target)
    camera2.fovy = 45.0f;                                // Camera field-of-view Y
    camera2.projection = CAMERA_PERSPECTIVE;
    _3Dcamera = std::move(camera2);

    Camera camera3 = {0};
    camera3.position = Vector3({ 4.0f, 2.0f, 4.0f });
    camera3.target = Vector3({ 0.0f, 1.8f, 0.0f });
    camera3.up = Vector3({ 0.0f, 1.0f, 0.0f });
    camera3.fovy = 60.0f;
    camera3.projection = CAMERA_PERSPECTIVE;
    _camera = std::move(camera3);
}

Drawer::Drawer(Camera2D camera)
{
    ClearBackground(BLACK);
    _2Dcamera = std::move(camera);
}

Drawer::Drawer(Camera3D camera)
{
    ClearBackground(BLACK);
    _3Dcamera = std::move(camera);
}

/*Drawer::Drawer(Camera camera)
{
    ClearBackground(BLACK);
    _camera = std::move(camera);
}*/

Drawer::Drawer(Camera2D camera, Camera3D camera2, Camera camera3)
{
    ClearBackground(BLACK);
    _2Dcamera = std::move(camera);
    _3Dcamera = std::move(camera2);
    _camera = std::move(camera3);
}

Drawer::Drawer(const Drawer &a)
{
    _2Dcamera = a._2Dcamera;
    _3Dcamera = a._3Dcamera;
    _camera = a._camera;
    ClearBackground(BLACK);
}

Drawer &Drawer::operator=(const Drawer &a)
{
    _2Dcamera = a._2Dcamera;
    _3Dcamera = a._3Dcamera;
    _camera = a._camera;
    ClearBackground(BLACK);
    return *this;
}

void Drawer::clearBackground(Color c)
{
    ClearBackground(c);
}

void Drawer::beginDrawing(void)
{
    BeginDrawing();
}

void Drawer::endDrawing(void)
{
    EndDrawing();
}

void Drawer::beginMode2D(void)
{
    BeginMode2D(_2Dcamera);
}

void Drawer::endMode2D(void)
{
    EndMode2D();
}

void Drawer::beginMode3D(void)
{
    BeginMode3D(_3Dcamera);
}

void Drawer::beginMode3D(Camera camera)
{
    BeginMode3D(camera);
}

void Drawer::endMode3D(void)
{
    EndMode3D();
}

void Drawer::setCamera2DRotation(float f)
{
    _2Dcamera.rotation = f;
}

void Drawer::setCamera2DZoom(float f)
{
    _2Dcamera.zoom = f;
}

void Drawer::setCamera2DTarget(Vector2 v)
{
    _2Dcamera.target = v;
}

void Drawer::setCamera2DOffset(Vector2 v)
{
    _2Dcamera.offset = v;
}

void Drawer::setCamera3DPosition(Vector3 v)
{
    _3Dcamera.position = v;
}

void Drawer::setCamera3DTarget(Vector3 v)
{
    _3Dcamera.target = v;
}

void Drawer::setCamera3DUp(Vector3 v)
{
    _3Dcamera.up = v;
}

void Drawer::setCamera3DFovy(float f)
{
    _3Dcamera.fovy = f;
}

void Drawer::setCameraMode(int mode)
{
    SetCameraMode(_camera, mode);
}

void Drawer::updateCamera(void)
{
    UpdateCamera(&_camera);
}

void Drawer::setCameraPanControl(int keyPan)
{
    SetCameraPanControl(keyPan);
}

void Drawer::setCameraAltControl(int keyAlt)
{
    SetCameraAltControl(keyAlt);
}

void Drawer::setCameraSmoothZoomControl(int keySmoothZoom)
{
    SetCameraSmoothZoomControl(keySmoothZoom);
}

void Drawer::setCameraMoveControls(int frontKey, int backKey, int rightKey, int leftKey, int upKey, int downKey)
{
    SetCameraMoveControls(frontKey, backKey, rightKey, leftKey, upKey, downKey);
}

void Drawer::setCameraPosition(Vector3 v)
{
    _camera.position = v;
}

void Drawer::setCameraTarget(Vector3 v)
{
    _camera.target = v;
}

void Drawer::setCameraUp(Vector3 v)
{
    _camera.up = v;
}

void Drawer::setCameraFovy(float f)
{
    _camera.fovy = f;
}