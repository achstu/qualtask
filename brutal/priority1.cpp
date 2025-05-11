#include <bits/stdc++.h>
using namespace std;

#include "data.h"
#include "debug.hpp"
#include "path.h"

// pritns all good beginings
void check_perm(const vector<Planet> &perm) {
  for (int i = sz(perm) - 5; i < sz(perm); i++) {
    auto path = perm;
    path.insert(path.begin() + i, origin()); // refuel
    path.insert(path.begin(), origin());     // push_front
    Path p(path, MAX_FUEL);
    if (p.valid() && p.lenght() - p.remaining_fuel() < 300) {
      cout << p.__repr__() << "\n";
      // cout << p.repr() << "\n";
      // cout << "len:  " << p.lenght() << "\n";
      // cout << "fuel: " << p.remaining_fuel() << "\n";
    }
  }
}

// You have to come back to origin before visiting
// all plantes with priority=1
void check_prem_no_fuel(const vector<Planet> &perm) {
  auto path = perm;
  path.insert(path.begin(), origin());
  path.push_back(origin());

  Path p(path, MAX_FUEL);
  if (p.valid()) {
    cout << p.lenght() << '\n';
  }
}

int main() {
  vector<Planet> planets = priority(1);

  cerr << setprecision(2);
  size_t cnt = 0;
  do {
    cnt++;
    if (cnt % 10000000 == 0) {
      cerr << double(100 * cnt) / 479001600.0 << "%\n";
    }
    check_perm(planets);
    // check_prem_no_fuel(planets);
  } while (next_permutation(planets.begin(), planets.end()));
}
