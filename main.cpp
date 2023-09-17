#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iostream>
#include <vector>
using ll = long long;

using namespace std;

// Given a SUM and an array of non negative numbers. Determine if the subset of
// the array exists with a sum equals to SUM

// f(x, y) -> can we make a sum of y from the first x elements, where n is the array
// length f (x, y) = f(x - 1, y') or f(x - 1, y), y' = y - array[x] Either we
// can make the sum at using the element at the current idx or we can't

bool hasSum(int SUM, vector<int> &array) {
  int n = array.size();
  int dp[n + 1][SUM + 1];
  // we can always make a sum of zero
  for (int i = 0; i <= n; i++)
    dp[i][0] = 1;
  // if array is empty we can not make a sum > 0
  for (int j = 1; j <= SUM; j++)
    dp[0][j] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= SUM; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j >= array[i])
        dp[i][j] |= dp[i - 1][j - array[i]];
    }
  return dp[n][SUM];
}

void solve() {
  int SUM, n;
  cin >> SUM;
  cin >> n;
  vector<int> array(n);
  for (int i = 0; i < n; i++)
    cin >> array[i];
  cout << hasSum(SUM, array) << endl;
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
