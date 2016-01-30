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
  
  Base& a = base;
  Base& b = derived; // Polymorphism
  // References must be initialized
  // And to a valid object, too
  a = derived; // Changed pointee (the object)
  
  const Base& d = a; // const data
  // References never change (they always point
  // to one address)

  cout << a.enormous[0] << a.enormous[1] << endl;
}