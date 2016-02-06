#include "Vector2.hpp"

namespace cse380 {
  Vector2::Vector2() : Vector2(0, 0) {}

  Vector2::Vector2(float x, float y) : x(x), y(y) {}

  Vector2& Vector2::operator+=(const Vector2& other) {
    this->x += other.x;
    this->y += other.y;
    return *this;
  }

  Vector2 operator+(const Vector2& a, const Vector2& b) {
    return Vector2(a.x + b.x, a.y + b.y);
  }
}