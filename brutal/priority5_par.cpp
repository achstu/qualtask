#include <bits/stdc++.h>
using namespace std;

#include "part4.h"
#include "data.h"
#include "debug.hpp"
#include "path.h"
#include "BS_thread_pool.hpp"

mutex cout_mutex;

void better_beg_f(const vector<Planet> perm) {
  for (const Path begin : part4) {
    for (int i = sz(perm) - 3; i < sz(perm); i++) {
      auto path = perm;
      path.insert(path.begin() + i, origin());      // refuel
      path.insert(path.begin(), begin.path.back()); // start

      Path p = join(begin, path);
      if (p.valid()) {
        {
        std::lock_guard<std::mutex> lock(cout_mutex);
        cout << p.lenght() - p.remaining_fuel() << "#";
        cout << p.__repr__() << "\n";
        }
      }
    }
  }
}

void better_beg(const vector<Planet> perm) {
  for (const Path pref: part4) {

      Path p = join(pref, perm);
      if (p.valid()) {
        {
        std::lock_guard<std::mutex> lock(cout_mutex);
        cout << p.lenght() - p.remaining_fuel() << "#";
        cout << p.__repr__() << "\n";
        }
      }
  }
}

int main() {
  vector<Planet> planets = priority(5);

  BS::thread_pool pool;
  do {

    pool.detach_task([planets] { return better_beg_f(planets); });

  } while (next_permutation(planets.begin(), planets.end()));

  pool.wait();
}
