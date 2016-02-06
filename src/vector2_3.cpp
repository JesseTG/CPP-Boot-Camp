#include "Vector2.hpp"

namespace cse380 {
  // Omitted for brevity

  Vector2::operator Vector3() const {
    return Vector3(this->x, this->y, 0);
  }

  // Omitted for brevity
}