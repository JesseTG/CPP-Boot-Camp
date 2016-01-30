#include <cstdint>
#include <memory>

using std::size_t;
using std::unique_ptr;@\tikzmark{unique_ptr}@

class FloatArray {
  public:
    FloatArray(size_t size) : m_size(size), m_array(make_unique@\tikzmark{unique_multiple}@<float[]>(size)) {}

  private:
    size_t m_size;
    unique_ptr<float[]> m_array;@\tikzmark{unique_delete}@
};

int main() {
  FloatArray stack(64);

  FloatArray* heap = new FloatArray(42);
  delete heap;
  // No memory leaks here (or in the previous slide)!
}