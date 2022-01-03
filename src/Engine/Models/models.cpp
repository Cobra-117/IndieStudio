/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-adrien.michaud
** File description:
** models
*/

#include "../../../include/Engine/Models/models.hpp"

IndieModel::IndieModel(void) {

}

IndieModel::IndieModel(std::string path)
{
    _model = LoadModel(path.c_str());
}

void IndieModel::init(std::string texturePath, std::string modelPath,
Vector3 pos, Vector3 rotationAxis, Vector3 scale)
{
    tex = new IndieTextures(texturePath, 0, 0, 0, 1, WHITE);
    loadFromFile(modelPath);
    IndieSetMaterialTexture(0, *tex);
    _position = pos;
    _rotationAxis = rotationAxis;
    _scale = scale;
}

void IndieModel::loadFromFile(std::string path)
{
    _model = LoadModel(path.c_str());
}

void IndieModel::IndieSetMaterialTexture(int index, IndieTextures texture)
{
    SetMaterialTexture(&_model.materials[index], MAP_DIFFUSE, texture.getTexture());
}

void IndieModel::IndieDrawEx(float RotationAngle, Color tint)
{
    DrawModelEx(this->_model, this->_position, this->_rotationAxis, RotationAngle,
        this->_scale, tint);
}

void IndieModel::IndieLoadModelAnimations(std::string path, int *counter)
{
    _animation = LoadModelAnimations(path.c_str(), counter);
}

void IndieModel::IndieUpdateModelAnimation(int frame)
{
    UpdateModelAnimation(this->_model, *this->_animation, frame);
}

void IndieModel::setPosition(Vector3 newPos)
{
    _position = newPos;
}

Vector3 IndieModel::getPosition()
{
    return _position;
}

void IndieModel::changeDirection(Vector3 NewDir)
{
    //_model.
}

void IndieModel::IndieUnloadModelAnimation(ModelAnimation _anim)
{
    UnloadModelAnimation(_anim);
}

void IndieModel::IndieModelRotation(Vector3 vec)
{
    _model.transform = MatrixRotateXYZ(Vector3({DEG2RAD *vec.x, DEG2RAD *vec.y, DEG2RAD *vec.z}));
}