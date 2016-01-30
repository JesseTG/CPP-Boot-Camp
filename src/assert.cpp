#include <cassert>
#include <type_traits>

// #define NDEBUG@\tikzmark{assert_ndebug}@
// ^ Uncomment this or define it in the build system to disable asserts

using std::is_base_of;
using std::is_same;

template<class T, class U>
void failIfUnrelated() {
  static_assert(
    is_base_of<T, U>::value
    || is_base_of<U, T>::value
    || is_same<T, U>::value,
    "Both types should be the same, or one should be a parent of the other"
  );
}

class Parent {};
class Child : public Parent {};

int main() {
  assert(1 + 1 == 2);@\tikzmark{assert_use}@

  failIfUnrelated<int, int>();@\tikzmark{assert_ok_a}@
  failIfUnrelated<Parent, Child>();@\tikzmark{assert_ok_b}@
  failIfUnrelated<int, Child>();@\tikzmark{assert_error}@
}