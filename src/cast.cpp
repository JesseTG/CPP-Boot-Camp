#include <iostream>

using std::cout;
using std::endl;

struct Base { 
  virtual ~Base() {}
};

struct Derived : public Base {
  int thing;
};

int main() {
  Base base;@\tikzmark{cast_poly}@
  Derived derived;

  Base* b_base = &base;
  Base* b_derived = &derived;@\tikzmark{cast_upcast_a}@
  Base& base_ref = base;
  Base& derived_ref = derived;@\tikzmark{cast_upcast_b}@
  
  Derived* d1 = dynamic_cast@\tikzmark{cast_dynamic}@<Derived*>(b_derived);@\tikzmark{cast_dynamic_pass}@
  Derived* d2 = dynamic_cast<Derived*>(b_base);@\tikzmark{cast_dynamic_fail}@

  Derived* d3 = static_cast@\tikzmark{cast_static}@<Derived*>(b_derived);@\tikzmark{cast_static_pass}@
  Derived* d4 = static_cast<Derived*>(b_base);@\tikzmark{cast_static_fail}@

  cout << d1 << ' ' << d2 << ' ' << d3 << ' ' << d4 << endl;
  d4->thing = 52;@\tikzmark{cast_ub}@
}