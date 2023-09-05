#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iostream>
#include <vector>
using ll = long long;

using namespace std;
// https://www.spoj.com/problems/ACODE/
void solve(string s) {
  int n = s.length();
  ll dp[n + 1];
  dp[0] = 1;
  dp[1] = 1;
  int charCode = stoi(s.substr(0, 2));
  if (charCode <= 26 && charCode >= 11 && charCode != 20)
    dp[1] += 1;
  for (int i = 2; i <= n; i++) {
    dp[i] = 0;
    if (s[i] != '0' )
      dp[i] += dp[i - 1];
    int charCode = stoi(s.substr(i - 1, 2));
    if ( charCode <= 26 && charCode >= 10) {
      dp[i] += dp[i - 2];
    }
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
  string s;

  cin >> s;
  while (s != "0") {
    solve(s);
    cin >> s;
  }

  return 0;
}
