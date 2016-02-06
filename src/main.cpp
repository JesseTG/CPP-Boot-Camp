#include <cstdlib>
#include <iostream>

#include <Box2D/Box2D.h>

#include "Vector2.hpp"
#include "Vector3.hpp"

using std::cout;
using std::endl;
using std::system;

using namespace cse380;

int main() {
  b2World world(b2Vec2_zero);
  Vector2 a(2, 3);
  Vector3 b;

  cout << "Hello world!" << endl;
  system("PAUSE");
}