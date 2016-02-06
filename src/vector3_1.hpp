#pragma once
#include "Vector2.hpp"

namespace cse380 {
  class Vector3 {
  public:
    Vector3();
    Vector3(float, float, float);

    float x, y, z;

    Vector3& operator+=(const Vector3&);
    explicit operator Vector2() const;
  };

  Vector3 operator+(const Vector3&, const Vector3&);
}