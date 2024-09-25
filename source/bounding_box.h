#ifndef BOUNDING_BOX_H
#define BOUNDING_BOX_H

#include "vector2d.h"

class BoundingBox
{
public:
    BoundingBox();
    BoundingBox(const Vector2D& bottomLeft_, const Vector2D& topRight_);

    const Vector2D& getBottomLeft() const; // getter bottomLeft
    void setBottomLeft(const Vector2D& newBottomLeft); // setter bottomLeft

    const Vector2D& getTopRight() const; // getter topRight
    void setTopRight(const Vector2D& newTopRight); // setter topRight

    void enclose(const Vector2D& vector);
    bool collision(const BoundingBox& other, const Vector2D& thisBbox, const Vector2D& otherBbox) const;

private:
    Vector2D bottomLeft, topRight;
};

#endif // BOUNDING_BOX_H