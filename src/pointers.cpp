#include <iostream>

using std::cout;
using std::endl;

struct Base {
  int enormous[1024];
};

struct Derived : public Base {
  float huge[1024];
};

int main() {
  Base base;
  Derived derived;
  
  Base* a = &base;
  Base* b = &derived; // Polymorphism
  Base* c; // Uninitialized (value undefined)
  c = nullptr;
  c = &derived; // Changed pointer
  
  const Base* d = a; // mutable pointer, const data
  Base const* e = a; // const pointer, mutable data
  const Base* const f = a; // pointer and data const
  
  int* ptr = a->enormous; // Pointer arithmetic
  cout << *ptr << *(ptr + 1) << (*ptr) + 1 << endl;
}