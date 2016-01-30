#include <iostream>
#include <regex> // Test out regexes at @\href{https://www.regex101.com}{\underline{regex101}}@
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::regex;
using std::regex_search;@\tikzmark{regex_match}@
using std::smatch;
using std::string;
using std::vector;

int main() {
  regex secret_council("(\\b[plurandy]+\\b ?){2}"@\tikzmark{regex_syntax}@, regex::icase@\tikzmark{regex_flags}@);
  vector<string> members = {"Duran Duran", "Ayn Rand", "Paul Rudd", "Ann Druyan", "Randall Munroe"};

  for (const auto &m : members) {
      cout << m << ": " << regex_search(m, secret_council)@\tikzmark{regex_search}@ << endl;
  }   
 
  smatch member_match;@\tikzmark{regex_smatch_a}@
  for (const auto &m : members) {
    regex_search(m, member_match, secret_council);@\tikzmark{regex_smatch_b}@
    cout << "matches for '" << m << "':" << endl;

    for (size_t i = 0; i < member_match.size(); ++i) {
      cout << "    " << i << ": " << member_match[i]@\tikzmark{regex_access_match}@ << endl;
    }
  }
}