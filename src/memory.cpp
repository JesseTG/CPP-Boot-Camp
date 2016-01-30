#include @\cppref{header/string}{<string>}@

using std::@\cppref{string/basic_string}{string}@;

@\tikzmark{memory_static_b}@string a = "I'll always exist";

void scope() {
  @\tikzmark{memory_auto_b}@string b = "I'll die at the end of the block";
  @\tikzmark{memory_dynamic_b}@string* c = new string("I'll die when you kill me");

  delete c; // c is deleted
  // b is deleted
}

int main() {
  for (int i = 0; i < 100000; ++i) {
    @\tikzmark{memory_dynamic_c}@string* d = new string("Oops");
    // d is not deleted (all 100000 instances of it)
  }

  // a is deleted
}