#ifndef ACTOR_H
#define ACTOR_H

#include "vector2d.h"
#include "bounding_box.h"
#include "globals.h"
#include <vector>
#include <nothofagus.h>


class Actor
{
public:
    Actor(const Vector2D& position_, const Vector2D& speed_, const BoundingBox& bbox_, Nothofagus::Bellota& bellota_);

    const Vector2D& getPosition() const; // getter position
    void setPosition(const Vector2D& newPosition); // setter position

    const Vector2D& getSpeed() const; // getter speed
    void setSpeed(const Vector2D& newSpeed); // setter speed

    const BoundingBox& getBoundingBox() const; // getter bounding box
    void setBoundingBox(const BoundingBox& newBbox); // setter bounding box

    const Nothofagus::Bellota& getBellota() const; // getter bounding box
    //void setBellota(const Nothofagus::Bellota& newBellota); // setter bounding box

    void move(float x_, float y_);

    void update(const float& delta_tiempo);
    bool collision(const Actor& other) const;


private:
    Vector2D position, speed;
    BoundingBox bbox;
    Nothofagus::Bellota& bellota;
};

#endif // ACTOR_H
