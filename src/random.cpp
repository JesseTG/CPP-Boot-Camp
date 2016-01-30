#include <iostream> 
#include @\cppref{numeric/random}{<random>}@

using std::cout; 
using std::@\cppref{numeric/random#Predefined_random_number_generators}{default\_random\_engine}@; 
using std::endl; 
using std::@\cppref{numeric/random/normal_distribution}{normal\_distribution}@;
using std::@\cppref{numeric/random/random_device}{random\_device}@;

int main() {
  random_device seed;@\tikzmark{random_device}@
  default_random_engine random(seed());@\tikzmark{random_init}@
  normal_distribution<float>@\tikzmark{random_many}@ normal(0, 1); // mean == 0, stddev == 1

  for (int i = 0; i < 100; ++i) {
    cout << normal(random@\tikzmark{random_concept}@) << ' ';
  }

  cout << endl;
}