#include <algorithm>
#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iostream>
#include <vector>
using ll = long long;

using namespace std;

int max_money(int activities[], int n) {
  int dp[n];
  int max_prev[n];
  dp[0] = max_prev[0] = activities[0];
  dp[1]  = max_prev[1]= activities[1] + activities[0];

  dp[2] = activities[2] + max(activities[1], activities[0]);
  max_prev[2] = max(dp[2], dp[1]);


  for (int i = 3; i < n; i++){
    

    dp[i] = activities[i] + max({dp[i - 2], max_prev[i - 3] + activities[i - 1]});
    max_prev[i] = max(max_prev[i - 1], dp[i]);
  }
  return max({dp[n - 2], dp[n - 1]});
}

void solve() {
  int n;
  cin >> n;
  int activities[n];
  for (int i = 0; i < n; i++)
    cin >> activities[i];
  cout << max_money(activities, n) << endl;
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
