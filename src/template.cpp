#include <iostream>
#include <string>
#include <typeinfo>

using std::cout;
using std::endl;
using std::string; 

template<class T>@\tikzmark{template_stl}@
struct Value {@\tikzmark{template_class}@
  using Type = T;@\tikzmark{template_typedef}@
  T data;

  Value(const T& d) : data(d) {}
};

template<class T>@\tikzmark{template_function}@
void printIt(const Value<T>& val) {
  cout << typeid(typename@\tikzmark{template_depend}@ Value<T>::Type).name() << ' ' << val.data << endl; 
}

struct Dummy {};

int main() { 
  Value<string> text("My name is Beavis");@\tikzmark{template_diff_a}@
  Value<int> number(47);@\tikzmark{template_diff_b}@
  Value<Dummy> dummy(Dummy());@\tikzmark{template_diff_c}@

  printIt(text);@\tikzmark{template_function_deduce}@
  printIt(number);
  // printIt(dummy);@\tikzmark{template_no_print}@
}