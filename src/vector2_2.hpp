#pragma once

namespace cse380 {
  class Vector2 {
  public:
    Vector2();
    Vector2(float, float);
    // Can omit names in declaration

    float x, y;

    Vector2& operator+=(const Vector2&);
  };

  Vector2 operator+(const Vector2&, const Vector2&);
}