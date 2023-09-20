#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iostream>
#include <vector>
using ll = long long;

using namespace std;

int covert_to_binary(int n) {
  int res = 0;
  int power = 1;
  while (n) {
    res += (n & 1) * power;
    n >>= 1;
    power *= 10;
  }
  return res;
}
void solve() {
  int n;
  cin >> n;
  cout << covert_to_binary(n) << endl;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
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
