#include <array>
#include <iostream>
#include <string>
#include @\cppref{header/utility}{<utility>}@

using namespace std;@\tikzmark{namespace_std}@

namespace sbcs {@\tikzmark{namespace_nest_a}@
  namespace cse380 {@\tikzmark{namespace_nest_b}@
    struct Game {
      string name;
      string teamName;
      array<string, 3> members;
    };
  }

  namespace cse381 {@\tikzmark{namespace_nest_c}@
    using Team = @\cppref{utility/pair}{pair}@<string, string>;
  }
}

int main() {
  sbcs::cse380::Game game;@\tikzmark{namespace_qualified}@
  using sbcs::cse381::Team;@\tikzmark{namespace_using}@

  Team team("Jesse", "Karl");
}