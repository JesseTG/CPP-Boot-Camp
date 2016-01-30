#include <cstdint>

using std::size_t;

class FloatArray {
  public:
    FloatArray(size_t size) : _size(size), _array(new float[size]) {}

    FloatArray(const FloatArray&) = delete;@\tikzmark{deleted_a}@
    FloatArray& operator=(const FloatArray&) = delete;@\tikzmark{deleted_b}@

    ~FloatArray() {@\tikzmark{deleted_cleanup}@
      delete[] floats;
    }

  private:
    size_t _size;
    float* _array;
};

int main() {
  FloatArray stack(64);@\tikzmark{deleted_should}@

  FloatArray* heap = new FloatArray(42);
  delete heap;
  // No memory leaks here (or in the previous slide)!
}