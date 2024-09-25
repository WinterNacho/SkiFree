#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>
#include <string>
#include <format>

struct Vector2D {
    float x, y; 

    Vector2D();
    Vector2D(float x_, float y_);

    Vector2D operator+(const Vector2D& other) const;
    Vector2D& operator+=(const Vector2D& other);

    Vector2D operator-(const Vector2D& other) const;
    Vector2D& operator-=(const Vector2D& other);

    Vector2D operator*(const Vector2D& other) const;
    Vector2D& operator*=(const Vector2D& other);

    bool operator==(const Vector2D& other) const;

    Vector2D operator*(const float& num);
    //Vector2D& operator*=(const double& num);
};

#endif // VECTOR2D_H
