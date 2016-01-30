#include @\cppref{header/limits}{<limits>}@
#include <string>

using std::@\cppref{types/numeric_limits}{numeric\_limits}@;
using std::string;

int something(int param) { 
  if (param > 0) return param; 
  // No return down here; now what? 
} 

string& returnsALocal() { 
  string reference = "Why are you doing this"; 
  return reference; // Uh-oh 
} 

int main() { 
  int a = numeric_limits<int>::max(); 
  a++; // Oops 

  int* pointer; // What's inside?  Beats me.
  int number = *pointer;

  int[10] array; 
  number = array[12]; // WTF 
}