#include <algorithm>
#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iostream>
#include <vector>
using ll = long long;

using namespace std;

// The min number of minutes I assign myself if I can not skip three days in a
// row.
int min_minutes(int activities[], int n) {
  int dp[n];
  dp[0] = activities[0];
  dp[1] = activities[1];
  dp[2] = activities[2];
  for (int i = 3; i < n; i++)
    dp[i] = activities[i] + min({dp[i - 2], dp[i - 3], dp[i - 1]});
  return min({dp[n - 2], dp[n - 3], dp[n - 1]});
}

void solve() {
  int n;
  cin >> n;
  int activities[n];
  for (int i = 0; i < n; i++)
    cin >> activities[i];
  cout << min_minutes(activities, n) << endl;
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
