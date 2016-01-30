#include <string>

using std::string;

class Person {
  public:@\tikzmark{class_access_a}@
    int cantBeOverridden(int a, int b) { return this->integer + b; }@\tikzmark{class_no_override}@
    virtual@\tikzmark{class_virtual}@ float canBeOverridden(double d) { return d * 2; }
    virtual ~Person()@\tikzmark{class_virtual_dtor}@ {}
  protected:@\tikzmark{class_access_b}@
    float number;
  private:@\tikzmark{class_access_c}@
    int integer;
};@\tikzmark{class_semicolon}@

struct IBeeGee {@\tikzmark{class_struct}@
  string stayAlive() @\tikzmark{class_abstract}@= 0;
};

class MauriceGibb : public Person, public IBeeGee {@\tikzmark{class_inheritance}@
  void stayAlive() override {
    return "Well, you can tell by the way I use my walk";
  }

  float canBeOverridden(double d) override@\tikzmark{class_override}@ {
    return Person@\tikzmark{class_super}@::canBeOverridden(d) + 23;
  }
};