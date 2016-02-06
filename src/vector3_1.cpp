#include "Vector3.hpp"

namespace cse380 {
  Vector3::Vector3(float x, float y, float z)
    : x(x), y(y), z(z) {}

  Vector3::Vector3() : Vector3(0, 0, 0) {}

  Vector3& Vector3::operator+=(const Vector3& v) {
    this->x += v.x;
    this->y += v.y;
    this->z += v.z;
    return *this;
  }

  Vector3::operator Vector2() const {
    return Vector2(this->x, this->y);
  }

  Vector3 operator+(const Vector3& a, const Vector3& b) {
    return Vector3(a) += b;
  }
}