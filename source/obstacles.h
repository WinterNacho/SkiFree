#ifndef OBSTACLES_H
#define OBSTACLES_H

#include "actor.h"

class Hydrant : public Actor
{
public:

    Hydrant(const Vector2D& position, Nothofagus::Bellota& bellota_)
        : Actor(position, Vector2D(0.0f, 0.0f), BoundingBox(Vector2D(0.0f, 0.0f),Vector2D(200.0f, 200.0f)), bellota_) {}


};

class Tree : public Actor
{
public:

    Tree(const Vector2D& position, Nothofagus::Bellota& bellota_)
        : Actor(position, Vector2D(0.0f, 0.0f), BoundingBox(Vector2D(0.0f, 0.0f),Vector2D(5.0f, 5.0f)), bellota_) {}


};

#endif // OBSTACLES_H
