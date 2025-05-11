#pragma once

#include <iostream>
#include <string>
using namespace std;

template <typename T> bool ckmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T> bool ckmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}

#define sz(x) (static_cast<int>((x).size()))

template <typename T, typename = T::value_type>
static ostream &operator<<(ostream &os, const T &x)
  requires(!same_as<T, string>)
{
  os << '{';
  string sep;
  for (const auto &v : x) {
    os << sep << v;
    sep = ", ";
  }
  return os << '}';
}

template <typename T, typename U>
static ostream &operator<<(ostream &os, const pair<T, U> &x) {
  return os << format("({},{})", x.first, x.second);
}

template <typename... Args> static void __print(const Args &...x) {
  ((cerr << ' ' << x), ...);
  cerr << endl;
}

#define debug(...)                                                             \
  do {                                                                         \
    cerr << '[' << #__VA_ARGS__ << "]:";                                       \
    __print(__VA_ARGS__);                                                      \
  } while (0)
