#include <climits>
#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iostream>
#include <vector>
using ll = long long;

using namespace std;

//Problem statement
// https://codeforces.com/problemset/problem/698/A

vector<vector<int>> A = {{0}, {1, 0}, {2, 0}, {0, 1, 2}};
int dp(int i, int prev, vector<int> &days, vector<vector<int>> &memo ) {
  if (i >= days.size())
    return 0;
  if (memo[i][prev] != -1)
    return memo[i][prev];
  int ans = INT_MAX;
  for (int c : A[days[i]]) {
    if (c != prev || c == 0) {
      int curr = dp(i + 1, c, days, memo);
      if (c == 0) curr += 1;
      ans = min(ans, curr);
    }

  }
  return  memo[i][prev] = ans;
}

void solve() {
  int n;
  cin >> n;
  vector<int> days(n);
  vector<vector<int>> memo(n, vector<int>(3, -1));
  vector<string> chosen(n) ;
  

  for (int i = 0; i < n; i++)
    cin >> days[i];
  int ans = dp(0, 0, days, memo);
  cout << ans <<  endl;
  // print(memo);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();

  return 0;
}
