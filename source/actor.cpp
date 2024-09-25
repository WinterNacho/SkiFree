#include "actor.h"
#include "globals.h"

Actor::Actor(const Vector2D& position_, const Vector2D& speed_, const BoundingBox& bbox_, Nothofagus::Bellota& bellota_) :
    position(position_), 
    speed(speed_), 
    bbox(bbox_),
    bellota(bellota_)
{}

const Vector2D& Actor::getPosition() const // getter position
{
    return position;
}

void Actor::setPosition(const Vector2D& newPosition) // setter position
{
    position = newPosition;
}

const Vector2D& Actor::getSpeed() const // getter speed
{
    return speed;
}

void Actor::setSpeed(const Vector2D& newSpeed) // setter speed
{
    speed = newSpeed;
}

const BoundingBox& Actor::getBoundingBox() const // getter bounding box
{
    return bbox;
}

void Actor::setBoundingBox(const BoundingBox& newBbox) // setter bounding box
{
    bbox = newBbox;
}
const Nothofagus::Bellota& Actor::getBellota() const // getter bounding box
{
    return bellota;
}

void Actor::move(float x_, float y_){
    bellota.transform().location().x += x_;
    bellota.transform().location().y += y_;
    position.x += x_;
    position.y += y_;
    if(bellota.transform().location().y>600){
        float newX = randomPosition();
        bellota.transform().location().x = newX;
        bellota.transform().location().y = -400;
        position.x += newX;
        position.y += -400;
    }
}

void Actor::update(const float& delta_tiempo)
{
    position += speed * delta_tiempo;
}

bool Actor::collision(const Actor& other) const
{
    return bbox.collision(other.bbox, position, other.position);
}
