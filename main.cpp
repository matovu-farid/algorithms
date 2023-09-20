#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iostream>
#include <vector>
using ll = long long;

using namespace std;

int count_bits(int n) {
  int count = 0;
  while (n){
    if(n & 1) count ++;
    n >>= 1;
  }
  return count;
}
void solve() {
  int n;
  cin >> n;
  cout << count_bits(n) << endl;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
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
