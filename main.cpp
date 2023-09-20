#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iostream>
#include <vector>
using ll = long long;

using namespace std;
/*
Longest Consecutive Run of 1s in Binary
Given a non-negative integer n, return the length of the longest consecutive run
of 1s in its binary representation.
*/
void solve() {
  int n;
  cin >> n;
  int max_count = 0;
  int current_count = 0;
  while (n) {
    if (n & 1) {
      current_count++;
    } else {
      max_count = max(max_count, current_count);
      current_count = 0;
    }
    n >>= 1;
  }
  max_count = max(max_count, current_count);

  cout << max_count << endl;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
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
