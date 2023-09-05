#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iostream>
#include <vector>
using ll = long long;

using namespace std;


void solve() {
  int n;
  cin >> n;
  int dp[n + 1];
  dp[1]= 0;
  for (int i = 2; i <= n; i++){
    dp[i] = 1 + dp[i - 1];
    if (i % 2 == 0)
      dp[i] = min(dp[i],1 + dp[i / 2]);
    if (i % 3 == 0)
      dp[i] = min(dp[i],1 + dp[i / 3]);
  }
  cout << dp[n] << endl;
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
