#include <ostream>
#include <unordered_set>
#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iostream>
#include <vector>
using ll = long long;

using namespace std;
// https://codeforces.com/problemset/problem/577/B
bool moduloSum(int n, int m, vector<int> &a) {
  vector<vector<int>> dp(n + 1, vector<int>(m, 0));

  for (int i = 1; i <= n; i++) {
    int num = a[i - 1];
    if (num < m)
      dp[i][num] = true;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      dp[i][j] |= dp[i - 1][j];
      if (dp[i - 1][j]) {
        int k = (j + a[i - 1] % m) % m;
        dp[i][k] = 1;
      }
    }
    // print(dp);
  }

  return dp[n][0];
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> seq(n);
  for (int i = 0; i < n; i++) {
    cin >> seq[i];
  }
  if (moduloSum(n, m, seq))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
  return 0;
}
