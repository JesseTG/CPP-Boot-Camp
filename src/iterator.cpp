#include <array>
#include <iostream>
#include <string>

using std::array; 
using std::cout; 
using std::endl; 
using std::string; 

int main() { 
  array<string, 5> strings = {"France", "Spain", "China", "America", "Sweden"};

  // No iterators
  for (int i = 0; i < strings.size(); i++) {
    cout << strings[i] << ' ';
  }
  cout << endl;

  // The clunky way (but lets you use @\cppref{iterator#Iterator_adaptors}{adaptors}@)
  for (auto@\tikzmark{iterator_auto}@ it = strings.begin()@\tikzmark{iterator_ptr}@; it != strings.end(); it++) {
    cout << *it << ' ';
  }
  cout << endl;

  // \@cppref{language/range-for}{The C++11 way}@
  for (const string&@\tikzmark{iterator_ref}@ s : strings) {@\tikzmark{iterator_begin}@
    cout << s << ' ';
  }
  cout << endl;
}