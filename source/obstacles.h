#ifndef OBSTACLES_H
#define OBSTACLES_H

#include "actor.h"

class Hydrant : public Actor
{
public:

    Hydrant(const Vector2D& position, Nothofagus::Bellota& bellota_)
        : Actor(position, Vector2D(0.0f, 0.0f), BoundingBox(Vector2D(8.0f, 4.0f),Vector2D(24.0f, 20.0f)), bellota_) {}

};

class Tree : public Actor
{
public:

    Tree(const Vector2D& position, Nothofagus::Bellota& bellota_)
        : Actor(position, Vector2D(0.0f, 0.0f), BoundingBox(Vector2D(9.0f, 4.0f),Vector2D(19.0f, 14.0f)), bellota_) {}


};
class Ramp : public Actor
{
public:

    Ramp(const Vector2D& position, Nothofagus::Bellota& bellota_)
        : Actor(position, Vector2D(0.0f, 0.0f), BoundingBox(Vector2D(0.0f, 0.0f),Vector2D(35.0f, 20.0f)), bellota_) {}


};

#endif // OBSTACLES_H
