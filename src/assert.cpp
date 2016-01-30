#include @\cppref{header/cassert}{<cassert>}@
#include @\cppref{header/type_traits}{<type\_traits>}@

// #define NDEBUG@\tikzmark{assert_ndebug}@
// ^ Uncomment this or define it in the build system to disable asserts

using std::@\cppref{types/is_base_of}{is\_base\_of}@;
using std::@\cppref{types/is_same}{is\_same}@;

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
  @\cppref{error/assert}{assert}@(1 + 1 == 2);@\tikzmark{assert_use}@

  failIfUnrelated<int, int>();@\tikzmark{assert_ok_a}@
  failIfUnrelated<Parent, Child>();@\tikzmark{assert_ok_b}@
  failIfUnrelated<int, Child>();@\tikzmark{assert_error}@
}