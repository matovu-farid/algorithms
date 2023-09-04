#include <climits>
#include <ios>
#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iomanip>
#include <iostream>
#include <vector>
using ll = long long;

long long fib(ll n, vector<ll> &memo) {
  if (memo[n] != -1)
    return memo[n];
  if (n <= 2)
    return 1;
  memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
  return memo[n];
}
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<ll> memo(n + 1, -1);
  cout << (long double)fib(n, memo) << endl;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  cout.precision(3);

  ios::sync_with_stdio(0);
  cin.tie(0);

  int tests;
  cin >> tests;
  while (tests--) {
    solve();
  }

  return 0;
}
