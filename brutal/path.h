#pragma once

#include "data.h"
// #include <string>

const int MAX_FUEL = 550;

struct Path {
  const vector<Planet> &path;
  const int fuel;

  bool __valid;
  int __remaining_fuel;
  int __length;
  // string __repr;

  Path(const vector<Planet> &p, const int f) : path(p), fuel(f) { __init(); }

  void __init() {
    __valid = true;
    __remaining_fuel = fuel;
    __length = 0;

    for (Point3 curr = planet(path.front()).pos; Planet p : path) {
      int d = dist(curr, planet(p).pos);
      __remaining_fuel -= d;
      __length += d;
      curr = planet(p).pos;

      if (__remaining_fuel < 0) {
        __valid = false;
      }
      if (planet(p).priority == 0) {
        __remaining_fuel = MAX_FUEL;
      }
    }
  }

  bool valid() const { return __valid; }
  int remaining_fuel() const { return __remaining_fuel; }
  int lenght() const { return __length; }

  string repr() const {
    string res;
    for (Planet p : path) {
      res += planet(p).name + ",";
    }
    return res;
  }

  string __repr__() const {
    string res = "Path({";
    for (Planet p : path) {
      res += to_string(p) + ",";
    }
    return res + "}, " + to_string(fuel) + "),";
  }
};
