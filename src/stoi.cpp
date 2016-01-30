#include <cstdlib>
#include <string>

using std::size_t; 
using std::stoi;@\tikzmark{stoi_stoi}@
using std::stol; 
using std::stoll; 
using std::string; 
using std::to_string;@\tikzmark{stoi_wstring}@

int main() { 
  int a = stoi("42");@\tikzmark{stoi_a}@
  long b = stol(" 0x09", nullptr, 16);@\tikzmark{stoi_b}@

  size_t first_nonnumeric_char_index;
  long long c = stoll("12lbs", &first_nonnumeric_char_index, 0);@\tikzmark{stoi_c}@
  // base-0 means assume either base 8, 10, or 16 depending on the prefix

  string back = to_string(c);@\tikzmark{stoi_back}@
}