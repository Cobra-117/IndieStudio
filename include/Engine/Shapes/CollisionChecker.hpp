/*
** EPITECH PROJECT, 2021
** sdfghjk
** File description:
** jhgfd
*/

#ifndef COLLISION_CHECKER
#define COLLISION_CHECKER

extern "C" {
    #include "raylib.h"
}

#include <iostream>
#include <string>
#include <cstring>

class CollisionChecker
{
    private:

    public:
        CollisionChecker() = default;
        ~CollisionChecker() = default;
        bool IndieCheckCollisionRecs(Rectangle rec1, Rectangle rec2);
        bool IndieCheckCollisionCircles(Vector2 center1, float radius1, Vector2 center2, float radius2);
        bool IndieCheckCollisionCircleRec(Vector2 center, float radius, Rectangle rec);
        bool IndieCheckCollisionPointRec(Vector2 point, Rectangle rec);
        bool IndieCheckCollisionPointCircle(Vector2 point, Vector2 center, float radius);
        bool IndieCheckCollisionPointTriangle(Vector2 point, Vector2 p1, Vector2 p2, Vector2 p3);
        bool IndieCheckCollisionLines(Vector2 startPos1, Vector2 endPos1, Vector2 startPos2, Vector2 endPos2, Vector2 *collisionPoint);
        Rectangle IndieGetCollisionRec(Rectangle rec1, Rectangle rec2);
};


#endif