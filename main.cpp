#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iostream>
#include <vector>
using ll = long long;

using namespace std;

void subsets(string s) {
  int n = s.length();
  for (int mask = 0; mask < (1 << n); mask++) {
    for (int i = 0; i < n; i++)
      if (mask & (1 << i))
        cout << s[i] << " ";

    cout << endl;
  }
}
void solve() {
  string s;
  cin >> s;
  subsets(s);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
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
