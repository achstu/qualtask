#include <bits/stdc++.h>
using namespace std;

#include "data.h"
#include "mids.h"

int main() {
  for (const Path& mid : mids) {
    if (mid.lenght() - mid.remaining_fuel() < 1200) {
      cout << mid.__repr__() << "\n";
    }
  }
}
