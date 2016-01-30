#include <cstdint>
#include <cstring>

using std::memcpy;
using std::size_t;

class FloatArray@\tikzmark{raii_dont}@ {
  public:
    FloatArray(size_t size) : _size@\tikzmark{raii_init}@(size), _array(new float[size]) {}@\tikzmark{raii_ctor}@

    FloatArray(const FloatArray& other) : _size(other._size), _array(new float[other._size]) {@\tikzmark{raii_copyctor}@
      memcpy(_array, other._array, other._size * sizeof@\tikzmark{raii_sizeof}@(float));
    }

    FloatArray& operator=(const FloatArray& other) {@\tikzmark{raii_copyeq}@
      if (this != &other) { // Watch for self-assignment!
        float* temp = new float[other._size];
        memcpy(temp, other._array, other._size * sizeof(float));
        delete[] _array;
        _array = temp;
        return *this;
      }
    }

    ~FloatArray() {@\tikzmark{raii_dtor}@
      delete[] floats;@\tikzmark{raii_dtor_b}@
    }

  private:
    size_t _size;
    float* _array;
};