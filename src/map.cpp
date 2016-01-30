#include <cstdlib>
#include @\cppref{header/functional}{<functional>}@
#include @\cppref{header/tuple}{<tuple>}@

using std::@\cppref{utility/hash}{hash}@;
using std::size_t;
using std::@\cppref{utility/tuple/tie}{tie}@;

struct Coordinates {
  int x, y;
};

bool operator<@\tikzmark{map_lt}@(const Coordinates& a, const Coordinates& b) {
  return tie(a.x, a.y) < tie(b.x, b.y);
}

bool operator==@\tikzmark{map_eq}@(const Coordinates& a, const Coordinates& b) {
  return a.x == b.x && a.y == b.y;
}

namespace std {@\tikzmark{map_std}@
  template<> struct hash<Coordinates> {@\tikzmark{map_hash}@
    using argument_type = Coordinates;@\tikzmark{map_arg}@
    using result_type = std::size_t;@\tikzmark{map_result}@

    result_type operator()(const argument_type& s) const {@\tikzmark{map_func}@
      result_type h1(hash<int>()(s.x));
      result_type h2(hash<int>()(s.y));
      return h1 ^ (h2 << 1);
    }
  };
}