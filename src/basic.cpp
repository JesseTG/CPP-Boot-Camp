#include @\cppref{header/iostream}{<iostream>}@@\tikzmark{basic_include}@

// Comments
/* Block comments */
using std::@\cppref{io/cout}{cout}@; @\tikzmark{basic_using_a}@
using std::@\cppref{io/manip/endl}{endl}@; @\tikzmark{basic_using_b}@

const int SOME_CONSTANT = 5;

// Main entry point of a C++ program
int @\cppref{language/main_function}{main}@(int argc@\tikzmark{basic_argc}@, char** argv@\tikzmark{basic_argv}@) {
  // main() args are optional

  for (int i = 0; i < argc; ++i) {
    cout << "Arg #" << i << ": " << argv[i] << endl;@\tikzmark{basic_print}@
  }

  cout << "You gave ";
  switch (argc) {@\tikzmark{basic_switch}@
    case 0:
      cout << "exactly ";
    case SOME_CONSTANT:
      cout << SOME_CONSTANT;
      break;
    default:
      cout << "some number of"
  }
  cout << " arguments." << endl;

  return 0;@\tikzmark{basic_return}@
}