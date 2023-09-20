#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iostream>
#include <vector>
using ll = long long;

using namespace std;
/*
Hamming Distance
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, return the Hamming distance between them.

Constraints:

0 <= x, y <= 2^31 - 1
*/
int count_bits(int n){
  int count = 0;
  while(n){
    n = n & (n - 1);
    count ++;
  }
  return count;
}
int hammingDistance(int x, int y) {
  int diff = x ^ y;
  return count_bits(diff);
}
void solve() {
  int x, y;
  cin >> x >> y;
  cout << hammingDistance(x, y) << endl;

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
