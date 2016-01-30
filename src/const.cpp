#include <string>

using std::string; 

const int SOME_CONSTANT = 34; 
const string ANOTHER_CONSTANT = "More type-safe than macros!"; 

class ConstStuff { 
  public:
    ConstStuff(int i, const string& s) : m_data(i), m_text(s) {}

    int data() const { return m_data; }@\tikzmark{const_nochange}@
    const string& text() const { return m_text; }@\tikzmark{const_ref}@
    string& text() { return m_text; }@\tikzmark{const_nonconst_ref}@

    void concatenate(const string& str) { this->m_text += str; }@\tikzmark{const_nonconst}@

  private: 
    int m_data;
    string m_text; 
};

int main() {
  ConstStuff a(1, "France");
  const@\tikzmark{const_ub}@ ConstStuff b(2, "Spain");

  a.text()@\tikzmark{const_overload_a}@.append("FR");
  a.concatenate(b.text());
  // b.text()@\tikzmark{const_overload_b}@.append("SP");@\tikzmark{const_no_cat}@
}