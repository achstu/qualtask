#include <bits/stdc++.h>
using namespace std;

#include "data.h"

int main() {
  for (int p : {1, 2, 3, 4, 5}) {
    cout << p << ": " << priority(p).size() << "\n";
  }
}
