#include <iostream> 

using std::cout; 
using std::endl;

enum class Direction {@\tikzmark{enum_not_object}@
  North,
  South,
  East,
  West,@\tikzmark{enum_comma}@
};

enum class Speakers { 
  Mute = 0, @\tikzmark{enum_value}@
  Mono = 1, 
  Stereo = 2, 
  Surround = 4
}; 

enum NaturalBool {@\tikzmark{enum_old}@
  Yes,
  No
};

int main() { 
  Direction dir = Direction::North;@\tikzmark{enum_scoped_a}@
  Speakers audio = Speakers::Stereo;@\tikzmark{enum_scoped_b}@
  NaturalBool yes = Yes;@\tikzmark{enum_unscoped}@

  audio = Speakers(4);@\tikzmark{enum_ub}@
  cout << int(audio) << endl;@\tikzmark{enum_int}@
}