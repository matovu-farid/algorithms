#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iostream>
#include <vector>
using ll = long long;

using namespace std;

// Compatible numbers
// https://codeforces.com/contest/165/problem/E
void compatible_numbers(vector<int>& a, int n) {
  vector<int> dp(1 << 22, -1);

  // Initialize DP table with numbers from the array
  for (int x : a) {
    dp[x] = x;
  }

  // Update DP table by trying to flip each zero bit to one
  for (int mask = 0; mask < (1 << 22); ++mask) {
    if (dp[mask] == -1) continue;
    for (int j = 0; j < 22; ++j) {
      if (!(mask & (1 << j))) { // If the bit at position j is 0
        int new_mask = mask | (1 << j);
        dp[new_mask] = dp[mask];  // Update dp by setting the bit at position j to 1
      }
    }
  }

  // Check compatibility for each number in the array
  for (int x : a) {
    int y = ~x & ((1 << 22) - 1);  // Invert all bits and limit to 22 bits
    cout << (dp[y] == -1 ? -1 : dp[y]) << ' ';
  }
  cout << endl;
}



void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  compatible_numbers(a, n);
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
