#include "bounding_box.h"

BoundingBox::BoundingBox() :
    bottomLeft(),
    topRight()
{}

BoundingBox::BoundingBox(const Vector2D& bottomLeft_, const Vector2D& topRight_) :
    bottomLeft(bottomLeft_),
    topRight(topRight_) 
{}

const Vector2D& BoundingBox::getBottomLeft() const // getter bottomLeft
{
    return bottomLeft;
}

void BoundingBox::setBottomLeft(const Vector2D& newBottomLeft) // setter bottomLeft
{
    bottomLeft = newBottomLeft;
}

const Vector2D& BoundingBox::getTopRight() const // getter topRight
{
    return topRight;
}

void BoundingBox::setTopRight(const Vector2D& newTopRight) // setter topRight
{
    topRight = newTopRight;
}

void BoundingBox::enclose(const Vector2D& vector)
{
    if (vector.x < bottomLeft.x)
    {
        bottomLeft.x = vector.x;
    }
    if (vector.x > topRight.x)
    {
        topRight.x = vector.x;
    }
    if (vector.y < bottomLeft.y)
    {
        bottomLeft.y = vector.y;
    }
    if (vector.y > topRight.y)
    {
        topRight.y = vector.y;
    }
}

bool BoundingBox::collision(const BoundingBox& other, const Vector2D& thisBbox, const Vector2D& otherBbox) const
{
    return !(topRight.x + thisBbox.x < other.bottomLeft.x + otherBbox.x || 
             bottomLeft.x + thisBbox.x > other.topRight.x + otherBbox.x || 
             topRight.y + thisBbox.y < other.bottomLeft.y + otherBbox.y || 
             bottomLeft.y + thisBbox.y > other.topRight.y + otherBbox.y);
}
