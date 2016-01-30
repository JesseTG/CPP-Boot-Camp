#include @\cppref{header/cstdlib}{<cstdlib>}@
#include @\cppref{header/cstring}{<cstring>}@@\tikzmark{raii_cstring}@

using std::@\cppref{string/byte/memcpy}{memcpy}@;@\tikzmark{raii_memcpy}@
using std::size_t;

class FloatArray@\tikzmark{raii_dont}@ {
  public:
    FloatArray(size_t s) : size(s)@\tikzmark{raii_init}@, floats(new float[s]) {}@\tikzmark{raii_ctor}@

    FloatArray(const FloatArray& other) : size(other.size), floats(new float[other.size]) {@\tikzmark{raii_copyctor}@
      memcpy(floats, other.floats, other.size * sizeof@\tikzmark{raii_sizeof}@(float));
    }

    FloatArray& operator=(const FloatArray& other) {@\tikzmark{raii_copyeq}@
      if (this != &other) { // Watch for self-assignment!
        float* temp = new float[other.size];
        memcpy(temp, other.floats, other.size * sizeof(float));
        delete[] floats;
        floats = temp;
        return *this;
      }
    }

    ~FloatArray() {@\tikzmark{raii_dtor}@
      delete[] floats;@\tikzmark{raii_dtor_b}@
    }

  private:
    size_t size;
    float* floats;
};