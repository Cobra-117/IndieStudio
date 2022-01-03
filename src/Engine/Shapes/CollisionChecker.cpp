/*
** EPITECH PROJECT, 2021
** sdfghjk
** File description:
** jhgfdsq
*/

#include "../../../include/Engine/Shapes/CollisionChecker.hpp"

bool CollisionChecker::IndieCheckCollisionRecs(Rectangle rec1, Rectangle rec2)
{
    return CheckCollisionRecs(rec1, rec2);
}

bool CollisionChecker::IndieCheckCollisionCircles(Vector2 center1, float radius1, Vector2 center2, float radius2)
{
    return CheckCollisionCircles(center1, radius1, center2, radius2);
}

bool CollisionChecker::IndieCheckCollisionCircleRec(Vector2 center, float radius, Rectangle rec)
{
    return CheckCollisionCircleRec(center, radius, rec);
}

bool CollisionChecker::IndieCheckCollisionPointRec(Vector2 point, Rectangle rec)
{
    return CheckCollisionPointRec(point, rec);
}

bool CollisionChecker::IndieCheckCollisionPointCircle(Vector2 point, Vector2 center, float radius)
{
    return CheckCollisionPointCircle(point, center, radius);
}

bool CollisionChecker::IndieCheckCollisionPointTriangle(Vector2 point, Vector2 p1, Vector2 p2, Vector2 p3)
{
    return CheckCollisionPointTriangle(point, p1, p2, p3);
}

bool CollisionChecker::IndieCheckCollisionLines(Vector2 startPos1, Vector2 endPos1, Vector2 startPos2, Vector2 endPos2, Vector2 *collisionPoint)
{
    return CheckCollisionLines(startPos1, endPos1, startPos2, endPos2, collisionPoint);
}

Rectangle CollisionChecker::IndieGetCollisionRec(Rectangle rec1, Rectangle rec2)
{
    return GetCollisionRec(rec1, rec2);
}