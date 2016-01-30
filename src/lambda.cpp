#include @\cppref{header/algorithm}{<algorithm>}@
#include <array>
#include @\cppref{header/functional}{<functional>}@
#include <iostream>

using std::array;
using std::cout;
using std::endl;
using std::@\cppref{utility/functional/function}{function}@;
using std::@\cppref{algorithm/transform}{transform}@;

int main() { 
  array<int, 10> ints = {5, 7, 1, 2, 3, 9, 2, 1, 4, 2};

  function<bool(int)> isEven = [](int n) -> bool@\tikzmark{lambda_return}@ {
    return n % 2 == 0;
  };

  function<void(void)> printInts = [&ints] {@\tikzmark{lambda_parens}@
    for (int i : ints) {
      cout << i << ' ';
    }
    cout << endl;
  };

  printInts();

  transform(ints.@\tikzmark{lambda_begin}@begin(), ints.@\tikzmark{lambda_end}@end(), ints.@\tikzmark{lambda_inplace}@begin(), [&isEven@\tikzmark{lambda_capture}@](int i) {
    return isEven(i) ? i : i * 2;
  }); // ^ Doubles all odd numbers
  printInts();
}