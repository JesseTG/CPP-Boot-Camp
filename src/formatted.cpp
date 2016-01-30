#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using std::cout;
using std::endl;
using std::setprecision;@\tikzmark{formatted_modifier}@
using std::string;
using std::stringstream;@\tikzmark{formatted_stringstream}@

int main() { 
  float x = 5.6435221, y = 7.1453634545, z = -23.452354215;

  stringstream coords;

  coords << "DEBUG LOG\n"
    << "\tPosition: [" << setprecision(4) << x << ", " << y << ", " << z << "]\n";

  cout << coords.str() << endl;@\tikzmark{formatted_str}@
}