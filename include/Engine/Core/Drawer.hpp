/*
** EPITECH PROJECT, 2021
** sdfgh
** File description:
** jhgf
*/

#ifndef DRAWER
#define DRAWER

extern "C" {
    #include "raylib.h"
}

class Drawer
{
    private:
        Camera2D _2Dcamera;
        Camera3D _3Dcamera;
        Camera _camera;
    public:
        Drawer();
        Drawer(Camera2D);
        Drawer(Camera3D);
        //Drawer(Camera);
        Drawer(Camera2D, Camera3D, Camera);
        Drawer(const Drawer &);
        Drawer &operator=(const Drawer &);
        ~Drawer() = default;
        void clearBackground(Color);
        void beginDrawing(void);
        void endDrawing(void);
        void beginMode2D(void);
        void endMode2D(void);
        void setCamera2DRotation(float);
        void setCamera2DZoom(float);
        void setCamera2DTarget(Vector2);
        void setCamera2DOffset(Vector2);
        void beginMode3D(void);
        void beginMode3D(Camera);
        void endMode3D(void);
        void setCamera3DPosition(Vector3);
        void setCamera3DTarget(Vector3);
        void setCamera3DUp(Vector3);
        void setCamera3DFovy(float);
        void setCameraMode(int);
        void updateCamera(void);
        void setCameraPanControl(int);
        void setCameraAltControl(int);
        void setCameraSmoothZoomControl(int);
        void setCameraMoveControls(int, int, int, int, int, int);
        void setCameraPosition(Vector3);
        void setCameraTarget(Vector3);
        void setCameraUp(Vector3);
        void setCameraFovy(float);
};

#endif