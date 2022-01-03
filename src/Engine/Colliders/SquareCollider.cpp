/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-adrien.michaud
** File description:
** SquareCollider
*/

#include "../../../include/Engine/Colliders/SquareCollider.hpp"

SquareCollider::SquareCollider(float up, float down, float left, float right)
{
    _up = up;
    _down = down;
    _left = left;
    _right = right;
}

float SquareCollider::GetUp()
{
    return (_up);
}

float SquareCollider::GetDown()
{
    return (_down);
}

float SquareCollider::GetLeft()
{
    return (_left);
}

float SquareCollider::GetRight()
{
    return (_right);
}

void SquareCollider::SetUp(float up)
{
    _up = up;
}

void SquareCollider::SetDown(float down)
{
    _down = down;
}

void SquareCollider::SetLeft(float left)
{
    _left = left;
}

void SquareCollider::SetRight(float right)
{
    _right = right;
}