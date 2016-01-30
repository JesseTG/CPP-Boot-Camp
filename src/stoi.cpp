#include <cstdlib>
#include <string>

using std::size_t; 
using std::@\cppref{string/basic_string/stol}{stoi}@;@\tikzmark{stoi_stoi}@
using std::@\cppref{string/basic_string/stof}{stof}@;
using std::@\cppref{string/basic_string/stol}{stol}@; 
using std::@\cppref{string/basic_string/stol}{stoll}@; 
using std::string; 
using std::@\cppref{string/basic_string/to_string}{to\_string}@;@\tikzmark{stoi_wstring}@

int main() { 
  int a = stoi("42");@\tikzmark{stoi_a}@
  long b = stol(" 0x09", nullptr, 16);@\tikzmark{stoi_b}@

  size_t first_nonnumeric_char_index;
  long long c = stoll("12kg", &first_nonnumeric_char_index, 0);@\tikzmark{stoi_c}@
  // base-0 means assume either base 8, 10, or 16 depending on the prefix

  float d = stof("56.7");@\tikzmark{stoi_d}@

  string back = to_string(c);@\tikzmark{stoi_back}@
}