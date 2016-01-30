#include <array>
#include <cstdint>
#include <iostream>
#include <typeinfo>@\tikzmark{typedef_typeinfo}@

using byte = std::uint8_t;@\tikzmark{typedef_using_a}@

template<class T>
using Array10 = std::array<T, 10>;@\tikzmark{typedef_using_b}@

// Traditional syntax uses "typedef" keyword:@\tikzmark{typedef_prefer}@
//    typedef existing_type new_name;
using std::cout;
using std::endl; 

int main() { 
  std::uint8_t a = 5;@\tikzmark{typedef_okay_a}@
  byte b = a;@\tikzmark{typedef_okay_b}@

  cout << typeid(std::uint8_t).name() << ' ' << typeid(byte).name() << endl;@\tikzmark{typedef_same_a}@

  Array10<byte> c;

  cout << typeid(std::array<byte, 10>).name() << ' ' << typeid(c).name() << endl;@\tikzmark{typedef_same_b}@

  // Many standard types are typedefs (but this is hidden from you)
}