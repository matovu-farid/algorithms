
#include <algorithm>
#include <vector>
#include <iostream>
using ll = long long;

// https://codeforces.com/contest/1921/problem/D
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), c(m);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = 0; i < m; i++)
    cin >> c[i];
  sort(a.begin(), a.end());
  sort(c.begin(), c.end(), greater<int>());

  ll  res = 0;
  int l1 = 0, l2 = 0, r1 = n - 1, r2 = m - 1;

  while (l1 <= r1){
    int diff1 = abs(c[l2] - a[l1]);
    int diff2 = abs(c[r2] - a[r1]);
    if (diff1 > diff2){
      res += diff1;
      l1++; l2++;
    }else {
      res += diff2;
      r1--; r2--;
    }
  }
  cout << res << endl;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen(".input", "r", stdin);
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
