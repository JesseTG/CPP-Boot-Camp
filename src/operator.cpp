#include <iostream> 

using std::cout; 
using std::endl; 
using std::ostream;@\tikzmark{operator_cout}@

struct Vector2 { 
  float x, y;

  Vector2(float x, float y) : x(x), y(y) {}
  // copy assignment and constructor are implicit

  Vector2 operator+(const Vector2& other)@\tikzmark{operator_sensible}@ { 
    return Vector2(x + other.x, y + other.y); 
  } 
}; 

ostream& operator<<@\tikzmark{operator_ostream}@(ostream& out, const Vector2& v) {
  return out << '[' << v.x << ", " << v.y << ']';
}

bool operator==(const Vector2& a, const Vector2& b)@\tikzmark{operator_eq}@ noexcept {
  return a.x == b.x && a.y == b.y;
}

int main() {
  Vector2 a(1, 2); 
  Vector2 b(2, 1); 
  Vector2 c = a + b; 

  cout << c << ' ' << a == b << endl; // [3, 3] false
}