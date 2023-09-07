#include <unordered_set>
#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iostream>
#include <vector>
using ll = long long;

using namespace std;

// find values or x and y such that, ax + by = gcd(a, b)
vector<int> extended_gcd(int a, int b) {
  if (b == 0)
    return {1, 0, a};
  vector<int> res = extended_gcd(b, a % b);
  int x = res[1];
  int y = res[0] - (a / b) * x;
  return {x, y, res[2]};
}

void solve() {
  int a, b;
  cin >> a >> b;
  if (b > a)
    swap(a, b);
  auto res = extended_gcd(a, b);
  cout << res[0] << " " << res[1] << " " << res[2] << endl;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);

  int tests;
  cin >> tests;
  while (tests--) {
    solve();
  }

  return 0;
}
