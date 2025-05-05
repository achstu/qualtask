#include <bits/stdc++.h>
#include <string>
#include <type_traits>
using namespace std;

#ifdef LOCAL
#include "debug.hpp"
#else
#define debug(...) 13.09
#endif

using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

using vi = vector<int>;
using pii = pair<int, int>;

template <typename T> bool ckmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T> bool ckmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}

struct Planet {
  string name;
  vi coords;
  int priority;
};

int main() {
  vector<Planet> galaxy;
  {
    string name;
    vi coords(3);
    int priority;
    while (cin >> name >> coords[0] >> coords[1] >> coords[2] >> priority) {
      galaxy.push_back(Planet(name, coords, priority));
    }
  }

  vector<Planet> by_pri[6];

  for (Planet p : galaxy) {
    by_pri[p.priority].push_back(p);
    // cout << p.name << p.priority << '\n';
  }

  for (int i = 1; i <= 5; i++) {
    cout << by_pri[i].size() << '\n';
    for (Planet p : by_pri[i]) {
      cout << p.name << '\n';
    }
    cout << '\n';
  }
}
