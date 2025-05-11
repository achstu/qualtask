#pragma once

#include <bits/stdc++.h>
using namespace std;

#include "debug.hpp"

using Planet = int;

struct Point3 {
  int x, y, z;

  // string repr() const { return format("({},{},{})", x, y, z); };
  string repr() const { return "dupka"; }
  friend int dist(const Point3 &a, const Point3 &b) {
    return abs(a.x - b.x) + abs(a.y - b.y) + abs(a.z - b.z);
  }
};

struct Planet_t {
  string name;
  Point3 pos;
  int priority;

  // string repr() const { return format("{}{}{}", name, pos.repr(), priority);
  // } bool operator<(const Planet_t &other) const { return name < other.name; }
};

constexpr array<Planet_t, 41> galaxy = {
    Planet_t("Death Star", Point3(0, 0, 0), 0),
    Planet_t("Coruscant", Point3(12, 34, 56), 1),
    Planet_t("Naboo", Point3(23, 45, 67), 3),
    Planet_t("Tatooine", Point3(34, 56, 78), 2),
    Planet_t("Kashyyyk", Point3(45, 67, 89), 1),
    Planet_t("Mustafar", Point3(56, 78, 90), 4),
    Planet_t("Hoth", Point3(67, 89, 12), 2),
    Planet_t("Dagobah", Point3(78, 90, 23), 3),
    Planet_t("Endor", Point3(90, 12, 34), 1),
    Planet_t("Kamino", Point3(10, 20, 30), 5),
    Planet_t("Geonosis", Point3(20, 30, 40), 2),
    Planet_t("Alderaan", Point3(30, 40, 50), 4),
    Planet_t("Bespin", Point3(40, 50, 60), 1),
    Planet_t("Yavin4", Point3(50, 60, 70), 3),
    Planet_t("Felucia", Point3(60, 70, 80), 2),
    Planet_t("Mandalore", Point3(70, 80, 90), 1),
    Planet_t("Utapau", Point3(80, 90, 10), 4),
    Planet_t("Ryloth", Point3(90, 10, 20), 2),
    Planet_t("Jakku", Point3(11, 22, 33), 3),
    Planet_t("Scarif", Point3(22, 33, 44), 1),
    Planet_t("Lothal", Point3(33, 44, 55), 5),
    Planet_t("Malachor", Point3(15, 40, 50), 1),
    Planet_t("Dathomir", Point3(67, 23, 45), 3),
    Planet_t("Exegol", Point3(78, 34, 56), 2),
    Planet_t("Corellia", Point3(50, 70, 85), 1),
    Planet_t("Onderon", Point3(90, 56, 78), 4),
    Planet_t("Ilum", Point3(12, 67, 89), 2),
    Planet_t("Saleucami", Point3(80, 85, 25), 3),
    Planet_t("Mygeeto", Point3(85, 15, 40), 1),
    Planet_t("Christophsis", Point3(30, 10, 20), 5),
    Planet_t("Serenno", Point3(25, 35, 45), 2),
    Planet_t("Zygerria", Point3(50, 30, 40), 4),
    Planet_t("Umbara", Point3(44, 55, 66), 1),
    Planet_t("Kessel", Point3(70, 50, 60), 3),
    Planet_t("Savareen", Point3(65, 75, 85), 2),
    Planet_t("Mimban", Point3(75, 85, 88), 1),
    Planet_t("Vandor", Point3(10, 80, 90), 4),
    Planet_t("Jedha", Point3(20, 90, 10), 2),
    Planet_t("Eadu", Point3(13, 24, 35), 3),
    Planet_t("Wobani", Point3(44, 22, 33), 1),
    Planet_t("Lahmu", Point3(55, 33, 44), 5),
};

constexpr Planet origin() { return 0; }

constexpr Planet_t planet(Planet i) { return galaxy[i]; }

constexpr vector<Planet> priority(int p) {
  vector<Planet> result;
  for (int i = 0; i < sz(galaxy); i++) {
    if (galaxy[i].priority == p) {
      result.push_back(i);
    }
  }
  return result;
}
