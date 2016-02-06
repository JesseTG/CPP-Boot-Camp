#include @\cppref{header/cstdlib}{<cstdlib>}@
#include <iostream>

using std::cout;
using std::endl;
using std::@\cppref{utility/program/system}{system}@;@\tikzmark{hello_system}@

int main() {
  cout << "Hello world!" << endl;

  system("PAUSE");@\tikzmark{hello_pause}@
} 
