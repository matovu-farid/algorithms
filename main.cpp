#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iostream>
#include <vector>
using ll = long long;

using namespace std;

// Given a SUM and an array of non negative numbers. Determine if the subset of the array exists with a sum equals to SUM

// f(x, y) -> can we make a sum of y from index 0...x, where n is the array length 
// f (x, y) = f(x - 1, y') or f(x - 1, y), y' = y - array[x]
// Either we can make the sum at using the element at the current idx or we cant
bool hasSumHelper(int SUM, vector<int> &array, int idx,
                  vector<vector<int>> &memo) {
  if (SUM == 0)
    return true;
  if (SUM < 0 || idx < 0)
    return false;
  if (memo[idx][SUM] != -1)
    return memo[idx][SUM];
  memo[idx][SUM] = hasSumHelper(SUM - array[idx], array, idx - 1, memo) ||
                   hasSumHelper(SUM, array, idx - 1, memo);
  return memo[idx][SUM];
}

bool hasSum(int SUM, vector<int> &array) {
  int n = array.size();
  vector<vector<int>> memo(n, vector<int>(SUM + 1, -1));
  bool res = hasSumHelper(SUM, array, n - 1, memo);
  return res;
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
