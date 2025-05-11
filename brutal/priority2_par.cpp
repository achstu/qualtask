#include <bits/stdc++.h>
using namespace std;

#include "begins.h"
#include "data.h"
#include "debug.hpp"
#include "path.h"

#include "BS_thread_pool.hpp"

mutex cout_mutex;

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

void better_beg(const vector<Planet> perm) {
  for (const Path begin : begins) {
    for (int i = sz(perm) - 5; i < sz(perm); i++) {
      auto path = perm;
      path.insert(path.begin() + i, origin());      // refuel
      path.insert(path.begin(), begin.path.back()); // start

      Path p = join(begin, path);
      if (p.valid() && p.lenght() - p.remaining_fuel() < 1300) {
        {
        std::lock_guard<std::mutex> lock(cout_mutex);
        cout << p.lenght() - p.remaining_fuel() << "#";
        cout << p.__repr__() << "\n";
        }
      }
    }
  }
}

int main() {
  vector<Planet> planets = priority(2);

  int cnt = 0;
  BS::thread_pool pool;
  do {
    // check_perm(planets);
    cnt ++;
    if (cnt % 100000 == 0) { 
      {
      std::lock_guard<std::mutex> lock(cout_mutex);
      cerr << double(cnt) / double(3628800) << "\n";
      }
    }
    pool.detach_task([planets] { return better_beg(planets); });

  } while (next_permutation(planets.begin(), planets.end()));

  pool.wait();
}
