#include <bits/stdc++.h>
using namespace std;

#include "begins.h"
#include "data.h"
#include "debug.hpp"
#include "path.h"

// pritns all good beginings
void check_perm(const vector<Planet> &perm) {

  auto path = perm;
  // path.insert(path.begin(), origin);
  Path _p(path, MAX_FUEL);
  cout << _p.lenght() << '\n';
  if (_p.valid()) {
    cout << _p.lenght() << " " << _p.remaining_fuel() << "\n";
  }
}

void better_beg(const vector<Planet> &perm) {
  for (const Path &begin : begins) {
    for (int i = sz(perm) - 5; i < sz(perm); i++) {
      auto path = perm;
      path.insert(path.begin() + i, origin());      // refuel
      path.insert(path.begin(), begin.path.back()); // start

      Path p(perm, begin.remaining_fuel());
      if (p.valid()) {
        cout << p.lenght() << " -> " << p.remaining_fuel() << "\n";
        cout << p.__repr__() << "\n";
      }
    }
  }
}

int main() {
  vector<Planet> planets = priority(2);

  size_t cnt = 0;
  do {
    cnt++;
    if (cnt % 100000 == 0) {
      cerr << double(cnt) / double(3628800) << '\n';
    }
    // check_perm(planets);
    better_beg(planets);
  } while (next_permutation(planets.begin(), planets.end()));
}
