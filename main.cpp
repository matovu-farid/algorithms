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
  vector<int> dp(m, 0);

  for (int i = 1; i <= n; i++) {
    vector<int> new_dp(m, 0);
    new_dp = dp;

    for (int j = 0; j < m; j++) {
      if (dp[j]) {
        int k = (j + a[i - 1] % m) % m;
        new_dp[k] = 1;
      }
    }
    int num = a[i - 1];
    if (num < m)
      new_dp[num] = 1;
    dp = new_dp;
    // print(dp);
  }

  return dp[0];
}
void solve() {
  int n, m;
  cin >> n >> m;
  if (n > m) {
    cout << "YES" << endl;
    return;
  }
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
