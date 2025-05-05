#include <bits/stdc++.h>
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

template <typename T> bool ckmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T> bool ckmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}

template <typename S, typename T> S &operator>>(S &s, vector<T> &vec) {
  for (T &x : vec)
    s >> x;
  return s;
}

template <typename S, typename T> S &operator<<(S &s, const vector<T> &vec) {
  for (const T &x : vec)
    s << x << ' ';
  return s;
}

#define sz(x) static_cast<int>((x).size())
const int INF = 1e9;

void solve() {
  int n;
  cin >> n;

  vi a(n);
  cin >> a;
  cout << a << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
