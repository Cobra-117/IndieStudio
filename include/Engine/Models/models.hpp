/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-adrien.michaud
** File description:
** models
*/

#ifndef MODELS_H_
#define MODELS_H_

extern "C" {
    #include "raylib.h"
    #include "raymath.h"
}

#include <string>
#include <cstring>
#include "../Textures/Textures.hpp"

class IndieModel
{
    public:
        IndieModel();
        IndieModel(std::string path);
        ~IndieModel() = default;
        void init(std::string texturePath, std::string modelPath,
        Vector3 pos, Vector3 rotationAxis, Vector3 scale);
        void loadFromFile(std::string file);
        void IndieSetMaterialTexture(int, IndieTextures);
        void IndieDrawEx(float RotationAngle, Color tint);
        void IndieLoadModelAnimations(std::string file, int *);
        void IndieUpdateModelAnimation(int frame);
        void setPosition(Vector3);
        void changeDirection(Vector3 NewDir);
        Vector3 getPosition();
        void IndieUnloadModelAnimation(ModelAnimation _anim);
        void IndieModelRotation(Vector3);

        public:
            Model _model;
            ModelAnimation *_animation;
            Vector3 _position;
            Vector3 _rotationAxis;
            Vector3 _scale;
            IndieTextures *tex;
};

#endif /* !MODELS_H_ */
