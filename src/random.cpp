#include <iostream> 
#include <random> 

using std::cout; 
using std::default_random_engine; 
using std::endl; 
using std::normal_distribution; 
using std::random_device; 

int main() {
  random_device seed;@\tikzmark{random_device}@
  default_random_engine random(seed());@\tikzmark{random_init}@
  normal_distribution<float>@\tikzmark{random_many}@ normal(0, 1); // mean == 0, stddev == 1

  for (int i = 0; i < 100; ++i) {
    cout << normal(random@\tikzmark{random_concept}@) << ' ';
  }

  cout << endl;
}