#include @\cppref{header/cstdlib}{<cstdlib>}@

using std::size_t;

class FloatArray {
  public:
    FloatArray(size_t s) : size(s), floats(new float[s]) {}

    FloatArray(const FloatArray&) = delete;@\tikzmark{deleted_a}@
    FloatArray& operator=(const FloatArray&) = delete;@\tikzmark{deleted_b}@

    ~FloatArray() {@\tikzmark{deleted_cleanup}@
      delete[] floats;
    }

  private:
    size_t size;
    float* floats;
};

int main() {
  FloatArray stack(64);@\tikzmark{deleted_should}@

  FloatArray* heap = new FloatArray(42);
  delete heap;
  // No memory leaks here (or in the previous slide)!
}