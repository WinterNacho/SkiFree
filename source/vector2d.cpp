#include <iostream>
#include <string>
#include <format>
#include "vector2d.h"

Vector2D::Vector2D() : x(0), y(0) {}

Vector2D::Vector2D(float x_, float y_) : x(x_), y(y_) {}

Vector2D Vector2D::operator+(const Vector2D& other) const {
    return {x + other.x, y + other.y};
}

Vector2D& Vector2D::operator+=(const Vector2D& other) {
    x += other.x;
    y += other.y;
    return *this;
}

Vector2D Vector2D::operator-(const Vector2D& other) const {
    return {x - other.x, y - other.y}; // Corregido: debería ser - en lugar de +.
}

Vector2D& Vector2D::operator-=(const Vector2D& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

Vector2D Vector2D::operator*(const Vector2D& other) const {
    return {x * other.x, y * other.y};
}

Vector2D& Vector2D::operator*=(const Vector2D& other) {
    x *= other.x;
    y *= other.y;
    return *this;
}

bool Vector2D::operator==(const Vector2D& other) const {
    return (x == other.x) && (y == other.y);
}

Vector2D Vector2D::operator*(const float& num) { // Cambiado a 'Vector2D' en lugar de 'Vector2D&'.
    return {x * num, y * num}; // Devuelve un nuevo Vector2D.
}
