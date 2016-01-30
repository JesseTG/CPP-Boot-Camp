#include <iostream>@\tikzmark{cpp_include}@

#define DEBUG@\tikzmark{cpp_define}@

// #define WINDOWS@\tikzmark{cpp_windows}@
// #define MAC@\tikzmark{cpp_mac}@

using std::cout; 
using std::endl; 

int main() { 
# ifdef DEBUG 
  cout << "Logging! Or sanity checking!" << endl;
# endif 

# ifdef WINDOWS
  cout << "Use DirectX!" << endl; 
# else 
  cout << "Use OpenGL!" << endl; 
# endif

# ifndef LINUX@\tikzmark{cpp_linux}@
  cout << "Why do you hate penguins?" << endl;
# endif

# ifdef MAC 
#   error "Jesse doesn't like Apple"@\tikzmark{cpp_error}@
# endif
}