#include <unordered_set>
#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iostream>
#include <vector>
using ll = long long;

using namespace std;

int gcd(int n, int m){
  if (m == 0) return n;
  return gcd(m, n % m);
}

void solve() {
  int n, m;
  cin >> n >> m;
  if (m > n) swap(n, m);
  cout << gcd(n, m) << endl;
  
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
