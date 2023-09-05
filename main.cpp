#include <algorithm>
#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iostream>
#include <vector>
using ll = long long;

using namespace std;

void solve() {
  const int n = 10;
  int nums[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int dp[n + 1];
  dp[0] = 0;
  for (int num = 1; num <= n; num++)
    dp[num] = dp[num >> 1] + (num & 1);

  for (int i = 1; i <= n; i++)
    cout << dp[i] << " ";
  cout << endl;
  
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
