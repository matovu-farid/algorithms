#include <algorithm>
#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

// No of ways to fill an array of length n with only zeros and ones without consequtive ones.
int ways(int n, vector<int>& memo){
  if (n == 0) return 1;
  if (n == 1) return 2;
  if (memo[n] != -1) return memo[n];
  memo[n] =  ways(n - 1, memo) + ways(n - 2, memo);
  return memo[n];
}
void solve() {
  int n;
  cin >> n;
  vector<int> memo(n + 1, -1);
  cout << ways(n, memo) << endl;
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
