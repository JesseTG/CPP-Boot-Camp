#include @\cppref{header/exception}{<exception>}@@\tikzmark{except_header}@
#include <iostream>

using std::cout;
using std::endl;
using std::@\cppref{error/exception}{exception}@;

int couldThrow(int x) {@\tikzmark{except_nocheck}@
  if (x % 2 == 0) throw exception("No new statement (more info later)");
  return x;
}

int willNotThrow(int x) noexcept {@\tikzmark{except_noexcept}@
  return x * x;
}

int main(int argc) {
  int a = willNotThrow(argc);
  try {  
    couldThrow(functionThrow(a));
  }
  catch (exception e)@\tikzmark{except_type}@ {
    cout << e.what();
  }
  catch (...) {@\tikzmark{except_swallow}@
    cout << "What the fuck?";
  }@\tikzmark{except_nofinally}@
}